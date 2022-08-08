#include "stdafx.h"

//Implement a basic calculator to evaluate a simple expression string.
//The expression string contains only non-negative integers, '+', '-', '*', '/'
//operators, and open '(' and closing parentheses ')'. The integer division
//should truncate toward zero.
//You may assume that the given expression is always valid. All intermediate
//results will be in the range of [-231, 231 - 1].
//
//Note: You are not allowed to use any built-in function which evaluates strings
//as mathematical expressions, such as eval().
// 
//
//Example 1:
//Input: s = "1+1"
//Output: 2
//
//Example 2:
//Input: s = "6-4/2"
//Output: 4
//
//Example 3:
//Input: s = "2*(5+5*2)/3+(6/2+8)"
//Output: 21
// 
//Constraints:
//1 <= s <= 104
//s consists of digits, '+', '-', '*', '/', '(', and ')'.
//s is a valid expression.

namespace Solution2022
{
	namespace BasicCalculatorIII
	{
		int parseNum(string& s, int& i) {
			long long result = 0;
			while (i < s.size() && isdigit(s[i])) {
				result = result * 10 + (s[i] - '0');
				i++;
			}
			return result;
		}

		int helper(string& s, int& i) {
			vector<long long> nums;
			char op = '+';

			for (; i < s.size() && op != ')'; i++) {
				if (s[i] == ' ') { continue; }
				long long n = s[i] == '(' ? helper(s, ++i) : parseNum(s, i);
				switch (op) {
				case '+': nums.push_back(n); break;
				case '-': nums.push_back(-n); break;
				case '*': nums.back() *= n; break;
				case '/': nums.back() /= n; break;
				}
				op = s[i];
			}
			return accumulate(nums.begin(), nums.end(), 0);
		}


		int calculate(string s) {
			int i = 0; 
			return helper(s, i);
		}

		void Main() {
			print(calculate("1+1"));
		}
	}
}
