#include "stdafx.h"

//Given a string s, return the longest palindromic substring in s.
// 
//
//Example 1:
//Input: s = "babad"
//Output: "bab"
//Explanation: "aba" is also a valid answer.
//
//Example 2:
//Input: s = "cbbd"
//Output: "bb"
// 
//Constraints:
//1 <= s.length <= 1000
//s consist of only digits and English letters.

namespace Solution2022
{
	namespace LongestPalindromicSubstring
	{
	    string longestPalindrome(string s) {
			int len = s.size();
			if (len < 2) { return s; }

			int longest = 0;
			int head = 0;

			for (int i = 0; i < len; i++) {
				int start = i;
				while (i + 1 < len && s[i] == s[i + 1]) { i++; }
				int end = i;
				while (start >= 0 && end < len && s[start] == s[end]) {
					start--;
					end++;
				}
				if (end - start - 1 > longest) {
					longest = end - start - 1;
					head = start + 1;
				}
			}
			return s.substr(head, longest);
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
