#include "stdafx.h"

//Given two strings s and t, return the number of distinct subsequences of s
//which equals t.
//A string's subsequence is a new string formed from the original string by
//deleting some (can be none) of the characters without disturbing the remaining
//characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while
//"AEC" is not).
//The test cases are generated so that the answer fits on a 32-bit signed integer.
// 
//
//Example 1:
//Input: s = "rabbbit", t = "rabbit"
//Output: 3
//Explanation:
//As shown below, there are 3 ways you can generate "rabbit" from S.
//rabbbit
//rabbbit
//rabbbit
//
//Example 2:
//Input: s = "babgbag", t = "bag"
//Output: 5
//Explanation:
//As shown below, there are 5 ways you can generate "bag" from S.
//babgbag
//babgbag
//babgbag
//babgbag
//babgbag
// 
//Constraints:
//1 <= s.length, t.length <= 1000
//s and t consist of English letters.

namespace Solution2022
{
	namespace DistinctSubsequences
	{
		//https://www.youtube.com/watch?v=-Q6XfyMiYUc
		int numDistinct(string s, string t) {
			int lens = s.size();
			int lent = t.size();
			if (lens < lent) { return 0; }
			if (lens == lent) { return s == t; }

			vector<vector<double>> dp(lens + 1, vector<double>(lent + 1, 0));

			for (int i = 0; i <= lens; i++) { dp[i][0] = 1; }

			for (int i = 1; i <= lens; i++) {
				for (int j = 1; j <= lent; j++) {
					if (s[i - 1] == t[j - 1]) { dp[i][j] += dp[i - 1][j - 1]; }
					dp[i][j] += dp[i - 1][j];
				}
			}
			return dp[lens][lent];
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
