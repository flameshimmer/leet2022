#include "stdafx.h"

//There is a row of m houses in a small city, each house must be painted with one
//of the n colors (labeled from 1 to n), some houses that have been painted last
//summer should not be painted again.
//A neighborhood is a maximal group of continuous houses that are painted with
//the same color.
//For example: houses = [1,2,2,3,3,2,1,1] contains 5 neighborhoods [{1}, {2,2},
//{3,3}, {2}, {1,1}].
//Given an array houses, an m x n matrix cost and an integer target where:
//houses[i]: is the color of the house i, and 0 if the house is not painted yet.
//cost[i][j]: is the cost of paint the house i with the color j + 1.
//Return the minimum cost of painting all the remaining houses in such a way that
//there are exactly target neighborhoods. If it is not possible, return -1.
// 
//
//Example 1:
//Input: houses = [0,0,0,0,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5,
//n = 2, target = 3
//Output: 9
//Explanation: Paint houses of this way [1,2,2,1,1]
//This array contains target = 3 neighborhoods, [{1}, {2,2}, {1,1}].
//Cost of paint all houses (1 + 1 + 1 + 1 + 5) = 9.
//
//Example 2:
//Input: houses = [0,2,1,2,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5,
//n = 2, target = 3
//Output: 11
//Explanation: Some houses are already painted, Paint the houses of this way
//[2,2,1,2,2]
//This array contains target = 3 neighborhoods, [{2,2}, {1}, {2,2}]. 
//Cost of paint the first and last house (10 + 1) = 11.
//
//Example 3:
//Input: houses = [3,1,2,3], cost = [[1,1,1],[1,1,1],[1,1,1],[1,1,1]], m = 4, n =
//3, target = 3
//Output: -1
//Explanation: Houses are already painted with a total of 4 neighborhoods
//[{3},{1},{2},{3}] different of target = 3.
// 
//Constraints:
//m == houses.length == cost.length
//n == cost[i].length
//1 <= m <= 100
//1 <= n <= 20
//1 <= target <= m
//0 <= houses[i] <= n
//1 <= cost[i][j] <= 104

namespace Solution2022
{
	namespace PaintHouseIII
	{
		//https://www.youtube.com/watch?v=53b32Upplk0
		/*dp[k][i][c] : = min cost to form k neighbors with first i houses and i - th house is in color c.

		dp[k][i][c] : = min{ dp[k - (c != cj)][j][cj] for cj in 1..n } +0 if houses[i] == c else cost[i][c]

		init : dp[0][0][*] = 0 otherwise inf
		ans = min(dp[target][m])

		Time complexity : O(T * M * N ^ 2)
		Space complexity : O(T * M * N)->O(M * N)*/

	    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
			int kInf = 1e9 + 7;
			int s = 1;
			vector<vector<vector<int>>> dp(target + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, kInf)));
			fill(dp[0][0].begin(), dp[0][0].end(), 0);
			for (int k = 1; k <= target; k++) {
				for (int i = k; i <= m; i++) {
					int hi = houses[i - 1];
					int hj = (i - 2 >= 0) ? houses[i - 2] : 0;
					const auto& [si, ei] = hi ? tie(hi, hi) : tie(s, n);
					const auto& [sj, ej] = hj ? tie(hj, hj) : tie(s, n);
					for (int ci = si; ci <= ei; ci++) {
						int v = (ci == hi) ? 0 : cost[i - 1][ci - 1];
						for (int cj = sj; cj <= ej; cj++) {
							dp[k][i][ci] = min(dp[k][i][ci], dp[k - (ci != cj)][i - 1][cj] + v);
						}
					}
				}
			}
			int result = *min_element(dp[target][m].begin(), dp[target][m].end());
			return result >= kInf ? -1 : result;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
