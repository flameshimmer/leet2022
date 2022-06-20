#include "stdafx.h"

//Given a string s which represents an expression, evaluate this expression and
//return its value. 
//The integer division should truncate toward zero.
//You may assume that the given expression is always valid. All intermediate
//results will be in the range of [-231, 231 - 1].
//
//Note: You are not allowed to use any built-in function which evaluates strings
//as mathematical expressions, such as eval().
// 
//
//Example 1:
//Input: s = "3+2*2"
//Output: 7
//
//Example 2:
//Input: s = " 3/2 "
//Output: 1
//
//Example 3:
//Input: s = " 3+5 / 2 "
//Output: 5
// 
//Constraints:
//1 <= s.length <= 3 * 105
//s consists of integers and operators ('+', '-', '*', '/') separated by some
//number of spaces.
//s represents a valid expression.
//All the integers in the expression are non-negative integers in the range [0,
//231 - 1].
//The answer is guaranteed to fit in a 32-bit integer.

namespace Solution2022
{
	namespace BasicCalculatorII
	{
	    int calculate(string s) {
			istringstream in(s + '+');
			long long lastOp = 0;
			long long nextOp = 0;
			long long sign = 1;
			char op;
			int result = 0;

			in >> lastOp;
			while (in >> op) {
				if (op == '+' || op == '-') {
					result += sign * lastOp;
					sign = (op == '+') ? 1 : -1;
					in >> lastOp;
				}
				else {
					in >> nextOp;
					if (op == '*') { lastOp *= nextOp; }
					else if (op == '/') { lastOp /= nextOp; }				
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
