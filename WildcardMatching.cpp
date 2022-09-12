#include "stdafx.h"

//Given an input string (s) and a pattern (p), implement wildcard pattern
//matching with support for '?' and '*' where:
//'?' Matches any single character.
//'*' Matches any sequence of characters (including the empty sequence).
//The matching should cover the entire input string (not partial).
// 
//
//Example 1:
//Input: s = "aa", p = "a"
//Output: false
//Explanation: "a" does not match the entire string "aa".
//
//Example 2:
//Input: s = "aa", p = "*"
//Output: true
//Explanation: '*' matches any sequence.
//
//Example 3:
//Input: s = "cb", p = "?a"
//Output: false
//Explanation: '?' matches 'c', but the second letter is 'a', which does not
//match 'b'.
// 
//Constraints:
//0 <= s.length, p.length <= 2000
//s contains only lowercase English letters.
//p contains only lowercase English letters, '?' or '*'.

namespace Solution2022
{
	namespace WildcardMatching
	{
		bool isMatch(string s, string p) {
			int lens = s.size();
			int lenp = p.size();

			vector<vector<bool>> M(lens + 1, vector<bool>(lenp + 1, false));
			M[0][0] = true;
			for (int i = 1; i < lenp + 1 && p[i - 1] == '*'; i++) {
				M[0][i] = M[0][i - 1];
			}

			for (int i = 1; i < lens + 1; i++) {
				for (int j = 1; j < lenp + 1; j++) {
					if (s[i - 1] == p[j - 1] || p[j - 1] == '?') { M[i][j] = M[i - 1][j - 1]; }
					else if (p[j - 1] == '*') { M[i][j] = M[i-1][j] || M[i][j-1]; }
				}
			}
			return M[lens][lenp];
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
