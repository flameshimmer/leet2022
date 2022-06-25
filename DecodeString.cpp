#include "stdafx.h"

//Given an encoded string, return its decoded string.
//The encoding rule is: k[encoded_string], where the encoded_string inside the
//square brackets is being repeated exactly k times. 
//Note that k is guaranteed to
//be a positive integer.
//You may assume that the input string is always valid; there are no extra white
//spaces, square brackets are well-formed, etc. Furthermore, you may assume that
//the original data does not contain any digits and that digits are only for
//those repeat numbers, k. For example, there will not be input like 3a or 2[4].
//The test cases are generated so that the length of the output will never exceed
//105.
// 
//
//Example 1:
//Input: s = "3[a]2[bc]"
//Output: "aaabcbc"
//
//Example 2:
//Input: s = "3[a2[c]]"
//Output: "accaccacc"
//
//Example 3:
//Input: s = "2[abc]3[cd]ef"
//Output: "abcabccdcdcdef"
// 
//Constraints:
//1 <= s.length <= 30
//s consists of lowercase English letters, digits, and square brackets '[]'.
//s is guaranteed to be a valid input.
//All the integers in s are in the range [1, 300].

namespace Solution2022
{
	namespace DecodeString
	{
	    string decodeString(string s) {
			int len = s.size();
			if (len == 0) { return ""; }

			stack<int> nums;
			stack<string> strs;

			string result = "";
			for (int i = 0; i < len; i++) {
				char c = s[i];
				if (isdigit(c)) {
					int val = 0;
					while (isdigit(s[i])) {
						val = val * 10 + (s[i] - '0');
						i++;
					}
					nums.push(val);
					i--;
				}
				else if (c == '[') {
					strs.push(result);
					result = "";
				}
				else if (c == ']') {
					string temp = strs.top();
					strs.pop();
					int count = nums.top();
					nums.pop();
					for (int j = 0; j < count; j++) {
						temp += result;
					}
					result = temp;
				}
				else {
					result.push_back(c);
				}
			}
			return result;
	    }

		void Main() {
			print(decodeString("3[a]2[bc]"));
		}
	}
}
