#include "stdafx.h"

//There are n points on a road you are driving your taxi on. The n points on the
//road are labeled from 1 to n in the direction you are going, and you want to
//drive from point 1 to point n to make money by picking up passengers. You
//cannot change the direction of the taxi.
//The passengers are represented by a 0-indexed 2D integer array rides, where
//rides[i] = [starti, endi, tipi] denotes the ith passenger requesting a ride
//from point starti to point endi who is willing to give a tipi dollar tip.
//For each passenger i you pick up, you earn endi - starti + tipi dollars. You
//may only drive at most one passenger at a time.
//Given n and rides, return the maximum number of dollars you can earn by picking
//up the passengers optimally.
//
//Note: You may drop off a passenger and pick up a different passenger at the
//same point.
// 
//
//Example 1:
//Input: n = 5, rides = [[2,5,4],[1,5,1]]
//Output: 7
//Explanation: We can pick up passenger 0 to earn 5 - 2 + 4 = 7 dollars.
//
//Example 2:
//Input: n = 20, rides =
//[[1,6,1],[3,10,2],[10,12,3],[11,12,2],[12,15,2],[13,18,1]]
//Output: 20
//Explanation: We will pick up the following passengers:
//- Drive passenger 1 from point 3 to point 10 for a profit of 10 - 3 + 2 = 9
//dollars.
//- Drive passenger 2 from point 10 to point 12 for a profit of 12 - 10 + 3 = 5
//dollars.
//- Drive passenger 5 from point 13 to point 18 for a profit of 18 - 13 + 1 = 6
//dollars.
//We earn 9 + 5 + 6 = 20 dollars in total.
// 
//Constraints:
//1 <= n <= 105
//1 <= rides.length <= 3 * 104
//rides[i].length == 3
//1 <= starti < endi <= n
//1 <= tipi <= 105

namespace Solution2022
{
	namespace MaximumEarningsFromTaxi
	{
		namespace DP {
			long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
				vector<long long> dp(n + 1);
				unordered_map<int, vector<pair<int, int>>> map;
				for (vector<int>& r : rides) {
					map[r[1]].push_back({ r[0], r[1] - r[0] + r[2] });
				}

				for (int i = 1; i <= n; i++) {
					dp[i] = dp[i - 1];
					for (auto [start, gain] : map[i]) {
						dp[i] = max(dp[i], dp[start] + gain);
					}
				}
				return dp[n];
			}
		}

		namespace DPOptimized {
			long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
				int m = rides.size();
				rides.push_back({ 0, 0, 0 });

				vector<long long> dp(m + 1);
				sort(rides.begin(), rides.end(), [](vector<int>& a, vector<int>& b) {return a[1] < b[1]; });

				vector<int> times;
				for (auto& r : rides) { times.push_back(r[1]); }

				for (int i = 1; i <= m; i++) {
					dp[i] = dp[i - 1];
					int start = rides[i][0];
					auto it = upper_bound(times.begin(), times.end(), start);
					if (it != times.begin()) {
						int j = prev(it) - times.begin();
						int gain = rides[i][1] - rides[i][0] + rides[i][2];
						dp[i] = max(dp[i], dp[j] + gain);
					}
				}
				return dp[m];
			}
		}

		namespace AnotherDP {
			long long maxTaxiEarnings(int n, vector<vector<int>>& A) {
				sort(A.begin(), A.end());
				vector<long long> dp(n + 1);
				int j = 0;
				for (int i = 1; i <= n; ++i) {
					dp[i] = max(dp[i], dp[i - 1]);
					while (j < A.size() && A[j][0] == i)
						dp[A[j++][1]] = max(dp[A[j][1]], dp[i] + A[j][1] - A[j][0] + A[j][2]);
				}
				return dp[n];
			}		
		}


		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
