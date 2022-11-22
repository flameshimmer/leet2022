#include "stdafx.h"

//Given a string s, check if it can be constructed by taking a substring of it
//and appending multiple copies of the substring together.
// 
//
//Example 1:
//Input: s = "abab"
//Output: true
//Explanation: It is the substring "ab" twice.
//
//Example 2:
//Input: s = "aba"
//Output: false
//
//Example 3:
//Input: s = "abcabcabcabc"
//Output: true
//Explanation: It is the substring "abc" four times or the substring "abcabc"
//twice.
// 
//Constraints:
//1 <= s.length <= 104
//s consists of lowercase English letters.

namespace Solution2022
{
	namespace RepeatedSubstringPattern
	{
		bool valid(string& s, int len, int tryLen) {
			if (len % tryLen != 0) { return false; }
			string tmp = "";
			string sub = s.substr(0, tryLen);
			for (int i = 0; i < len / tryLen; i++) { tmp += sub; }
			return s == tmp;
		}

		bool repeatedSubstringPattern(string s) {
			int len = s.size();
			int tryLen = 1;
			while (tryLen <= len / 2) {
				if (valid(s, len, tryLen)) { return true; }
				tryLen++;
			}
			return false;
		}

		void Main() {
			string test = "ababab";
			print(repeatedSubstringPattern(test));
		}
	}
}
