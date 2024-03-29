#include "stdafx.h"

//Given an input string s, reverse the order of the words.
//A word is defined as a sequence of non-space characters. The words in s will be
//separated by at least one space.
//Return a string of the words in reverse order concatenated by a single space.
//
//Note that s may contain leading or trailing spaces or multiple spaces between
//two words. The returned string should only have a single space separating the
//words. Do not include any extra spaces.
// 
//
//Example 1:
//Input: s = "the sky is blue"
//Output: "blue is sky the"
//
//Example 2:
//Input: s = "  hello world  "
//Output: "world hello"
//Explanation: Your reversed string should not contain leading or trailing spaces.
//
//Example 3:
//Input: s = "a good   example"
//Output: "example good a"
//Explanation: You need to reduce multiple spaces between two words to a single
//space in the reversed string.
// 
//Constraints:
//1 <= s.length <= 104
//s contains English letters (upper-case and lower-case), digits, and spaces ' '.
//There is at least one word in s.
// 
//Follow-up: If the string data type is mutable in your language, can you solve
//it in-place with O(1) extra space?

namespace Solution2022
{
	namespace ReverseWordsinaString
	{

		string reverseWords(string s) {
			int len = s.size();
			int start = 0;
			int end = 0;
			int wordCount = 0;

			while (end < len) {
				while (end < len && s[end] == ' ') { end++; }
				if (end == len) { break; }
				if (wordCount > 0) { s[start] = ' '; start++; }

				int tmp = start;
				while (end < len && s[end] != ' ') {
					s[start] = s[end];
					start++;
					end++;
				}
				wordCount++;
				reverse(s.begin() + tmp, s.begin() + start);
			}
			s.resize(start);
			reverse(s.begin(), s.end());
			return s;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
