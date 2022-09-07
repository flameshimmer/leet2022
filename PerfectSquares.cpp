#include "stdafx.h"

//Given an integer n, return the least number of perfect square numbers that sum
//to n.
//A perfect square is an integer that is the square of an integer; in other
//words, it is the product of some integer with itself. For example, 1, 4, 9, and
//16 are perfect squares while 3 and 11 are not.
// 
//
//Example 1:
//Input: n = 12
//Output: 3
//Explanation: 12 = 4 + 4 + 4.
//
//Example 2:
//Input: n = 13
//Output: 2
//Explanation: 13 = 4 + 9.
// 
//Constraints:
//1 <= n <= 104

namespace Solution2022
{
	namespace PerfectSquares
	{
		namespace DP {
			int numSquares(int n) {
				if (n == 0) { return 0; }

				vector<int> dp(n + 1, 0);
				for (int i = 0; i <= n; i++) {
					dp[i] = i; // Note: don't forget dp[i] = i, this means in the worst case, every number can be sum up with 1
					for (int j = 1; j * j <= i; j++) {
						dp[i] = min(dp[i], dp[i - j * j] + 1);
					}
				}
				return dp[n];
			}
		}

		namespace BFS {
			int numSquares(int n) {
				queue<int> q;
				unordered_set<int> visited;

				q.push(0);
				visited.insert(0);
				int level = 0;

				while (!q.empty()) {
					int sz = q.size();
					level++; // Note: level increase must be at the beginning of the while loop to ensure it is 1 based. 
					while (sz) {
						sz--;

						int top = q.front();
						q.pop();
						
						for (int i = 1; i * i <= n; i++) {
							int sum = top + i * i;
							if (sum == n) { return level; }
							else if (sum > n) { break; }
							else if (visited.find(sum) == visited.end()){
								visited.insert(sum);
								q.push(sum);
							}
						}					
					}
				}
				return level;
			}
		}


		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
