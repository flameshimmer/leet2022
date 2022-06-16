#include "stdafx.h"

//Given a string s, return true if the s can be palindrome after deleting at most
//one character from it.
// 
//
//Example 1:
//Input: s = "aba"
//Output: true
//
//Example 2:
//Input: s = "abca"
//Output: true
//Explanation: You could delete the character 'c'.
//
//Example 3:
//Input: s = "abc"
//Output: false
// 
//Constraints:
//1 <= s.length <= 105
//s consists of lowercase English letters.

namespace Solution2022
{
	namespace ValidPalindromeII
	{
		bool isPalindrome(string& s, int start, int end) {
			while (start < end) {
				if (s[start] == s[end]) { start++; end--; }
				else { return false; }
			}
			return true;
		}

	    bool validPalindrome(string s) {
			int len = s.size();
			if (len < 3) { return true; }

			int start = 0;
			int end = len - 1;
			while (start < end) {
				if (s[start] == s[end]) { start++; end--; }
				else {
					return isPalindrome(s, start + 1, end) || isPalindrome(s, start, end - 1);
				}
			}
			return true;
	    }

		void Main() {
			string test = "tst test test";
			print(validPalindrome("aba"));
		}
	}
}
