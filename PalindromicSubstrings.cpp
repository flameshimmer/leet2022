#include "stdafx.h"

//Given a string s, return the number of palindromic substrings in it.
//A string is a palindrome when it reads the same backward as forward.
//A substring is a contiguous sequence of characters within the string.
// 
//
//Example 1:
//Input: s = "abc"
//Output: 3
//Explanation: Three palindromic strings: "a", "b", "c".
//
//Example 2:
//Input: s = "aaa"
//Output: 6
//Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
// 
//Constraints:
//1 <= s.length <= 1000
//s consists of lowercase English letters.

namespace Solution2022
{
	namespace PalindromicSubstrings
	{
		void helper(string& s, int len, int i, int j, int& result) {
			while (i >= 0 && j < len && s[i] == s[j]) {
				result++;
				i--;
				j++;
			}
		}

		int countSubstrings(string s) {
			int len = s.size();
			int result = 0;
			for (int i = 0; i < len; i++) {
				helper(s, len, i, i, result);
				helper(s, len, i, i + 1, result);
			}
			return result;
		}

		namespace DP {
			int countSubstrings(string s) {
				int len = s.size();
				int result = 0;
				vector<vector<bool>> dp(len, vector<bool>(len, false));
				for (int i = len - 1; i >= 0; i--) { // i+1, j-1 decides how we write the index for the for loops
					for (int j = i; j < len; j++) {
						dp[i][j] = (s[i] == s[j]) && (j - i <= 2 || dp[i + 1][j - 1]);
						if (dp[i][j]) { result++; }
					}
				}
				return result;
			}
		}


		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
