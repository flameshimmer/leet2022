#include "stdafx.h"

//Given a string s representing a valid expression, implement a basic calculator
//to evaluate it, and return the result of the evaluation.
//
//Note: You are not allowed to use any built-in function which evaluates strings
//as mathematical expressions, such as eval().
// 
//
//Example 1:
//Input: s = "1 + 1"
//Output: 2
//
//Example 2:
//Input: s = " 2-1 + 2 "
//Output: 3
//
//Example 3:
//Input: s = "(1+(4+5+2)-3)+(6+8)"
//Output: 23
// 
//Constraints:
//1 <= s.length <= 3 * 105
//s consists of digits, '+', '-', '(', ')', and ' '.
//s represents a valid expression.
//'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
//'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
//There will be no two consecutive operators in the input.
//Every number and running calculation will fit in a signed 32-bit integer.

namespace Solution2022
{
	namespace BasicCalculator
	{
		int calculate(string str) {
			int len = str.size();
			if (len == 0) { return 0; }

			int local = 1; // immediate sign associated with a number
			int global = 1; // global sign
			int result = 0;
			stack<int> s;

			for (int i = 0; i < len; i++) {
				char c = str[i];
				switch (c) {
				case '+':
				case ' ':
					break;
				case '-':
					local = -1;
					break;
				case '(':
					s.push(local);
					global *= local;
					local = 1;
					break;
				case ')':
					global /= s.top();
					s.pop();
					local = 1;
					break;
				default:
					long long val = 0;
					while (i < len && isdigit(str[i])) {
						val = val * 10 + str[i] - '0';
						i++;
					}
					i--;
					result += global * local * val;
					local = 1;
				}
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
