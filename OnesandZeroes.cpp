#include "stdafx.h"

//You are given an array of binary strings strs and two integers m and n.
//Return the size of the largest subset of strs such that there are at most m 0's
//and n 1's in the subset.
//A set x is a subset of a set y if all elements of x are also elements of y.
// 
//
//Example 1:
//Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
//Output: 4
//Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001",
//"1", "0"}, so the answer is 4.
//Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
//{"111001"} is an invalid subset because it contains 4 1's, greater than the
//maximum of 3.
//
//Example 2:
//Input: strs = ["10","0","1"], m = 1, n = 1
//Output: 2
//Explanation: The largest subset is {"0", "1"}, so the answer is 2.
// 
//Constraints:
//1 <= strs.length <= 600
//1 <= strs[i].length <= 100
//strs[i] consists only of digits '0' and '1'.
//1 <= m, n <= 100

namespace Solution2022
{
	namespace OnesandZeroes
	{
		namespace LoopFromBegin {
			int findMaxForm(vector<string>& strs, int m, int n) {
				vector<vector<int>> dp = vector(m + 1, vector<int>(n + 1, 0));
				for (string& s : strs) {

					int zeroCount = 0;
					int oneCount = 0;
					for (char c : s) {
						if (c == '0') { zeroCount++; }
						else { oneCount++; }
					}

					auto tmp = dp;
					for (int i = zeroCount; i <= m; i++) {
						for (int j = oneCount; j <= n; j++) {
							dp[i][j] = max(tmp[i][j], tmp[i - zeroCount][j - oneCount] + 1);
						}
					}
				}
				return dp[m][n];
			}
		}

		namespace LoopFromEnd {
			int findMaxForm(vector<string>& strs, int m, int n) {
				vector<vector<int>> dp = vector(m + 1, vector<int>(n + 1, 0));
				for (string& s : strs) {
					int oneCount = 0;
					int zeroCount = 0;
					for (char c : s) {
						if (c == '1') { oneCount++; }
						else { zeroCount++; }
					}

					for (int i = m; i >= zeroCount; i--) {
						for (int j = n; j >= oneCount; j--) {
							dp[i][j] = max(dp[i][j], dp[i - zeroCount][j - oneCount] + 1);
						}
					}
				}
				return dp[m][n];
			}
		}


		void Main() {
			vector<string> test = { "10", "0001", "111001", "1", "0" };
			print(findMaxForm(test, 5, 3));
		}
	}
}
