#include "stdafx.h"

//Given a string containing just the characters '(' and ')', find the length of
//the longest valid (well-formed) parentheses substring.
// 
//
//Example 1:
//Input: s = "(()"
//Output: 2
//Explanation: The longest valid parentheses substring is "()".
//
//Example 2:
//Input: s = ")()())"
//Output: 4
//Explanation: The longest valid parentheses substring is "()()".
//
//Example 3:
//Input: s = ""
//Output: 0
// 
//Constraints:
//0 <= s.length <= 3 * 104
//s[i] is '(', or ')'.

namespace Solution2022
{
	namespace LongestValidParentheses
	{
		namespace UseStack {
			int longestValidParentheses(string str) {
				int len = str.size();
				if (len == 0) { return 0; }

				stack<pair<char, int>> s;
				int result = 0;
				str = ")" + str; // why adding this line? Because without this line, "result = max(result, i - s.top().second);" will run into s is empty while calling s.top

				for (int i = 0; i < len + 1; i++) {
					char c = str[i];

					if (s.empty() || c == '(' || (c == ')' && s.top().first != '(')) {
						s.push({ c, i });
					}
					else {
						s.pop();
						result = max(result, i - s.top().second);
					}
				}
				return result;
			}
		}


		namespace UseTwoScans {
			int longestValidParentheses(string str) {
				int len = str.size();
				if (len < 2) { return 0; }

				int result = 0;
				int counter = 0;
				int curLen = 0;

				for (char c : str) {
					if (c == '(') {
						counter++;
						curLen++;
					}
					else {
						if (counter > 0) {
							counter--;
							curLen++;
							if (counter == 0) {
								result = max(result, curLen);
							}
						}
						else {
							counter = 0;
							curLen = 0;
						}
					}
				}

				curLen = 0;
				counter = 0;

				for (int i = len - 1; i >= 0; i--) {
					char c = str[i];
					if (c == ')') {
						counter++;
						curLen++;
					}
					else {
						if (counter > 0) {
							counter--;
							curLen++;
							if (counter == 0) {
								result = max(result, curLen);
							}
						}
						else {
							counter = 0;
							curLen = 0;
						}
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
