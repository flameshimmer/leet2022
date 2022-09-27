#include "stdafx.h"

//You have a convex n-sided polygon where each vertex has an integer value. You
//are given an integer array values where values[i] is the value of the ith
//vertex (i.e., clockwise order).
//You will triangulate the polygon into n - 2 triangles. For each triangle, the
//value of that triangle is the product of the values of its vertices, and the
//total score of the triangulation is the sum of these values over all n - 2
//triangles in the triangulation.
//Return the smallest possible total score that you can achieve with some
//triangulation of the polygon.
// 
//
//Example 1:
//Input: values = [1,2,3]
//Output: 6
//Explanation: The polygon is already triangulated, and the score of the only
//triangle is 6.
//
//Example 2:
//Input: values = [3,7,4,5]
//Output: 144
//Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7
//= 245, or 3*4*5 + 3*4*7 = 144.
//The minimum score is 144.
//
//Example 3:
//Input: values = [1,3,1,4,1,5]
//Output: 13
//Explanation: The minimum score triangulation has score 1*1*3 + 1*1*4 + 1*1*5 +
//1*1*1 = 13.
// 
//Constraints:
//n == values.length
//3 <= n <= 50
//1 <= values[i] <= 100

namespace Solution2022
{
	namespace MinimumScoreTriangulationofPolygon
	{
		namespace Recursion {
			int helper(vector<int>& A, int i, int j, vector<vector<int>>& M) {
				if (M[i][j] != 0) { return M[i][j]; }

				int result = 0;
				for (int k = i + 1; k < j; k++) {
					int curV = helper(A, i, k, M) + A[i] * A[j] * A[k] + helper(A, k, j, M);
					result = min(result == 0 ? INT_MAX : result, curV);
				}
				M[i][j] = result;
				return result;
			}

			int minScoreTriangulation(vector<int>& A) {
				vector<vector<int>> M(50, vector<int>(50, 0));
				return helper(A, 0, A.size() - 1, M);
			}
		}

		namespace DP {
			int minScoreTriangulation(vector<int>& A) {
				int len = A.size();
				vector<vector<int>> dp(len, vector<int>(len, 0));

				for (int i = len - 1; i >= 0; i--) { // 0...i ... k ... j... len-1
					for (int j = i + 1; j < len; j++) {
						for (int k = i + 1; k < j; k++) {
							dp[i][j] = min((dp[i][j] == 0 ? INT_MAX : dp[i][j]), dp[i][k] + A[i] * A[j] * A[k] + dp[k][j]);
						}
					}
				}
				return dp[0][len - 1];
			}
		}

		void Main() {
			vector<int> test = { 1, 2, 3 };
			print(DP::minScoreTriangulation(test));
		}
	}
}
