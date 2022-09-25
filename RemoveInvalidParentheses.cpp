#include "stdafx.h"

//Given a string s that contains parentheses and letters, remove the minimum
//number of invalid parentheses to make the input string valid.
//Return all the possible results. You may return the answer in any order.
// 
//
//Example 1:
//Input: s = "()())()"
//Output: ["(())()","()()()"]
//
//Example 2:
//Input: s = "(a)())()"
//Output: ["(a())()","(a)()()"]
//
//Example 3:
//Input: s = ")("
//Output: [""]
// 
//Constraints:
//1 <= s.length <= 25
//s consists of lowercase English letters and parentheses '(' and ')'.
//There will be at most 20 parentheses in s.

namespace Solution2022
{
	namespace RemoveInvalidParentheses
	{
		bool isValidParenthese(string& s) {
			int count = 0;
			for (char c : s) {
				if (c == '(') { count++; }
				else if (c == ')') { count--; }
				if (count < 0) { return false; }
			}
			return count == 0;
		}

		void helper(string& s, int start, int l, int r, vector<string>& result) {
			if (l == 0 && r == 0) {
				if (isValidParenthese(s)) { result.push_back(s); }
				return;
			}

			for (int i = start; i < s.size(); i++) {
				if (i != start && s[i] == s[i - 1]) { continue; }

				if (s[i] == '(' || s[i] == ')') {
					string cur = s;
					cur.erase(i, 1);
					if (s[i] == ')' && r > 0) {
						helper(cur, i, l, r - 1, result);
					}
					else if (s[i] == '(' && l > 0) {
						helper(cur, i, l - 1, r, result);
					}
				}
			}
		}

		vector<string> removeInvalidParentheses(string s) {
			int l = 0;
			int r = 0;
			for (char c : s) {
				if (c == '(') { l++; }
				else if (c == ')') {
					if (l > 0) { l--; }
					else { r++; }
				}
			}
			vector<string> result;
			helper(s, 0, l, r, result);
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
