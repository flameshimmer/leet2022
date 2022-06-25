#include "stdafx.h"

//Given n pairs of parentheses, write a function to generate all combinations of
//well-formed parentheses.
// 
//
//Example 1:
//Input: n = 3
//Output: ["((()))","(()())","(())()","()(())","()()()"]
//
//Example 2:
//Input: n = 1
//Output: ["()"]
// 
//Constraints:
//1 <= n <= 8

namespace Solution2022
{
	namespace GenerateParentheses
	{
		void helper(int sp, int ep, int n, string curResult, vector<string>& result) {
			if (sp == n && ep == n) {
				result.push_back(curResult);
				return;
			}

			if (sp < n) {
				helper(sp + 1, ep, n, curResult + "(", result);
			}
			if (ep < sp) {
				helper(sp, ep + 1, n, curResult + ")", result);
			}
		}
		
		vector<string> generateParenthesis(int n) {
			vector<string> result;
			if (n == 0) { return result; }

			string curResult = "";
			helper(0, 0, n, curResult, result);
			return result;
		
		}

		void Main() {
			print(generateParenthesis(1));
			print(generateParenthesis(2));
			print(generateParenthesis(3));
		}
	}
}
