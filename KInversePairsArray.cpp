#include "stdafx.h"

//For an integer array nums, an inverse pair is a pair of integers [i, j] where 0
//<= i < j < nums.length and nums[i] > nums[j].
//Given two integers n and k, return the number of different arrays consist of
//numbers from 1 to n such that there are exactly k inverse pairs. Since the
//answer can be huge, return it modulo 109 + 7.
// 
//
//Example 1:
//Input: n = 3, k = 0
//Output: 1
//Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3 has
//exactly 0 inverse pairs.
//
//Example 2:
//Input: n = 3, k = 1
//Output: 2
//Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
// 
//Constraints:
//1 <= n <= 1000
//0 <= k <= 1000

namespace Solution2022
{
	namespace KInversePairsArray
	{

		// https://www.youtube.com/watch?v=PBk2-aUP-nQ&t=2164s

		//1. dp[i][j] = dp[i-1][j]+dp[i-1][j-1]+dp[i-1][j-2]+...+dp[i-1][j-i+1]
		//2. dp[i][j-1] = dp[i-1][j-1]+dp[i-1][j-2]+...+dp[i-1][j-i]
		//point 1-2 will make: dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-i]

		int kInversePairs(int n, int k) {
			vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
			const int mod = pow(10, 9) + 7;

			for (int i = 1; i <= n; i++)
				dp[i][0] = 1;

			for (int i = 2; i <= n; i++)
				for (int j = 1; j <= k; j++)
				{
					if (j >= i)
						dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - i]) % mod;
					else
						dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;

					if (dp[i][j] < 0)
						dp[i][j] += mod;
				}

			return dp[n][k];
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
