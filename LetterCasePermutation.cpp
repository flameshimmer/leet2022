#include "stdafx.h"

//Given a string s, you can transform every letter individually to be lowercase
//or uppercase to create another string.
//Return a list of all possible strings we could create. Return the output in any
//order.
// 
//
//Example 1:
//Input: s = "a1b2"
//Output: ["a1b2","a1B2","A1b2","A1B2"]
//
//Example 2:
//Input: s = "3z4"
//Output: ["3z4","3Z4"]
// 
//Constraints:
//1 <= s.length <= 12
//s consists of lowercase English letters, uppercase English letters, and digits.

namespace Solution2022
{
	namespace LetterCasePermutation
	{
		void helper(int level, int len, string& s, string& result, vector<string>& results) {
			if (level == len) {
				results.push_back(result);
				return;
			}
			
			char c = s[level];
			if (!isalpha(c)) { 
				result.push_back(c); 
				helper(level + 1, len, s, result, results);
				result.pop_back();
			}
			else {
				result.push_back(tolower(c));
				helper(level + 1, len, s, result, results);
				result.pop_back();

				result.push_back(toupper(c));
				helper(level + 1, len, s, result, results);
				result.pop_back();
			}			
		}

		vector<string> letterCasePermutation(string s) {
			vector<string> results;
			int len = s.size();
			if (len == 0) { return results; }

			string result;
			helper(0, len, s, result, results);
			return results;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
