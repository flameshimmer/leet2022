#include "stdafx.h"

//You are given a string s consisting of lowercase English letters. A duplicate
//removal consists of choosing two adjacent and equal letters and removing them.
//We repeatedly make duplicate removals on s until we no longer can.
//Return the final string after all such duplicate removals have been made. It
//can be proven that the answer is unique.
// 
//
//Example 1:
//Input: s = "abbaca"
//Output: "ca"
//Explanation: 
//For example, in "abbaca" we could remove "bb" since the letters are adjacent
//and equal, and this is the only possible move.  The result of this move is that
//the string is "aaca", of which only "aa" is possible, so the final string is
//"ca".
//
//Example 2:
//Input: s = "azxxzy"
//Output: "ay"
// 
//Constraints:
//1 <= s.length <= 105
//s consists of lowercase English letters.

namespace Solution2022
{
	namespace RemoveAllAdjacentDuplicatesInString
	{
	    string removeDuplicates(string s) {
			int len = s.size();
			if (len < 2) { return s; }
			
			string result = "";
			for (char c : s) {
				if (!result.empty() && c == result.back()) { 
					result.pop_back();
				}
				else {
					result.push_back(c);
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
