#include "stdafx.h"

//Given an input string s and a pattern p, implement regular expression matching
//with support for '.' and '*' where:
//'.' Matches any single character.​​​​
//'*' Matches zero or more of the preceding element.
//The matching should cover the entire input string (not partial).
// 
//
//Example 1:
//Input: s = "aa", p = "a"
//Output: false
//Explanation: "a" does not match the entire string "aa".
//
//Example 2:
//Input: s = "aa", p = "a*"
//Output: true
//Explanation: '*' means zero or more of the preceding element, 'a'. Therefore,
//by repeating 'a' once, it becomes "aa".
//
//Example 3:
//Input: s = "ab", p = ".*"
//Output: true
//Explanation: ".*" means "zero or more (*) of any character (.)".
// 
//Constraints:
//1 <= s.length <= 20
//1 <= p.length <= 30
//s contains only lowercase English letters.
//p contains only lowercase English letters, '.', and '*'.
//It is guaranteed for each appearance of the character '*', there will be a
//previous valid character to match.

namespace Solution2022
{
	namespace RegularExpressionMatching
	{
		bool matches(string& s, string& p, int i, int j) {
			return s[i] == p[j] || p[j] == '.';
		}

		bool isMatch(string s, string p) {
			int lens = s.size();
			int lenp = p.size();

			vector<vector<bool>> M(lens + 1, vector<bool>(lenp + 1, false));
			M[0][0] = true;

			for (int i = 0; i < lens + 1; i++) {
				for (int j = 1; j < lenp + 1; j++) {
					if (i - 1 >= 0 && matches(s, p, i - 1, j - 1) && M[i - 1][j - 1]) {
						M[i][j] = true;
						continue;
					}

					// if we want to match X*
					if (i - 1 >= 0 && j - 2 >= 0 && p[j-1] == '*' && matches(s, p, i - 1, j - 2) && M[i - 1][j]) {
						M[i][j] = true;
						continue;
					}

					// if we don't want to matching X*
					if (j - 2 >= 0 && p[j - 1] == '*' && M[i][j - 2]) {
						M[i][j] = true;
						continue;
					}
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
