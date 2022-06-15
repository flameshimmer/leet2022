#include "stdafx.h"

//Given a string s containing just the characters '(', ')', '{', '}', '[' and
//']', determine if the input string is valid.
//An input string is valid if:
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
// 
//
//Example 1:
//Input: s = "()"
//Output: true
//
//Example 2:
//Input: s = "()[]{}"
//Output: true
//
//Example 3:
//Input: s = "(]"
//Output: false
// 
//Constraints:
//1 <= s.length <= 104
//s consists of parentheses only '()[]{}'.

namespace Solution2022
{
	namespace ValidParentheses
	{
		bool matches(char a, char b) {
			if (a == '(') { return b == ')'; }
			else if (a == '[') { return b == ']'; }
			else if (a == '{') { return b == '}'; }
			else { return false; }
		}

		bool isValid(string str) {
			int len = str.size();
			if (len == 0) { return true; }

			stack<char> s;
			for (char c : str) {
				if (c == '(' || c == '[' || c == '{') {
					s.push(c);
				}
				else if (s.empty() || !matches(s.top(), c)) {
					return false;
				}
				else {
					s.pop();
				}
			}
			return s.empty();
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
