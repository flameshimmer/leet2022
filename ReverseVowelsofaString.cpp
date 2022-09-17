#include "stdafx.h"

//Given a string s, reverse only all the vowels in the string and return it.
//The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both cases.
// 
//
//Example 1:
//Input: s = "hello"
//Output: "holle"
//
//Example 2:
//Input: s = "leetcode"
//Output: "leotcede"
// 
//Constraints:
//1 <= s.length <= 3 * 105
//s consist of printable ASCII characters.

namespace Solution2022
{
	namespace ReverseVowelsofaString
	{
		namespace useStdLib {
			string reverseVowels(string s) {
				int len = s.size();
				int start = 0;
				int end = len - 1;
				while (start < end) {
					start = s.find_first_of("aeiouAEIOU", start);
					end = s.find_last_of("aeiouAEIOU", end);
					if (start < end) {
						swap(s[start], s[end]);
						start++;
						end--;
					}
				}
				return s;
			}
		}
				
		namespace UseWhileLoop {
			bool isVowls(char c) {
				return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
			}

			string reverseVowels(string s) {
				int len = s.size();
				if (len < 2) { return s; }

				int start = 0;
				int end = len - 1;
				while (start < end) {
					while (start < end && !isVowls(s[start])) { start++; }
					while (start < end && !isVowls(s[end])) { end--; }
					swap(s[start], s[end]);
					start++;
					end--;
				}
				return s;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
