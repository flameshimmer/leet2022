#include "stdafx.h"

//Given a string s of '(' , ')' and lowercase English characters.
//Your task is to remove the minimum number of parentheses ( '(' or ')', in any
//positions ) so that the resulting parentheses string is valid and return any
//valid string.
//Formally, a parentheses string is valid if and only if:
//It is the empty string, contains only lowercase characters, or
//It can be written as AB (A concatenated with B), where A and B are valid
//strings, or
//It can be written as (A), where A is a valid string.
// 
//
//Example 1:
//Input: s = "lee(t(c)o)de)"
//Output: "lee(t(c)o)de"
//Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
//
//Example 2:
//Input: s = "a)b(c)d"
//Output: "ab(c)d"
//
//Example 3:
//Input: s = "))(("
//Output: ""
//Explanation: An empty string is also valid.
// 
//Constraints:
//1 <= s.length <= 105
//s[i] is either'(' , ')', or lowercase English letter.

namespace Solution2022
{
	namespace MinimumRemovetoMakeValidParentheses
	{
	    string minRemoveToMakeValid(string str) {
			int len = str.size();
			if (len == 0) { return str; }

			string result = str;
			stack<int> s;

			for (int i = 0; i < len; i++) {
				if (str[i] == '(') { s.push(i); }
				else if (str[i] == ')') {
					if (s.empty()) { result[i] = '*'; }
					else { s.pop(); }
				}
			}
			while (!s.empty()) {
				result[s.top()] = '*';
				s.pop();
			}
			result.erase(remove(result.begin(), result.end(), '*'), result.end());
			return result;
		}

		void Main() {
			print(minRemoveToMakeValid("))(("));
			//print(minRemoveToMakeValid("lee(t(c)o)de)"));
		}
	}
}
