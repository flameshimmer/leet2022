#include "stdafx.h"

//Let's define a function countUniqueChars(s) that returns the number of unique
//characters on s.
//For example, calling countUniqueChars(s) if s = "LEETCODE" then "L", "T", "C",
//"O", "D" are the unique characters since they appear only once in s, therefore
//countUniqueChars(s) = 5.
//Given a string s, return the sum of countUniqueChars(t) where t is a substring
//of s.
//Notice that some substrings can be repeated so in this case you have to count
//the repeated ones too.
// 
//
//Example 1:
//Input: s = "ABC"
//Output: 10
//Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
//Every substring is composed with only unique letters.
//Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10
//
//Example 2:
//Input: s = "ABA"
//Output: 8
//Explanation: The same as example 1, except countUniqueChars("ABA") = 1.
//
//Example 3:
//Input: s = "LEETCODE"
//Output: 92
// 
//Constraints:
//1 <= s.length <= 105
//s consists of uppercase English letters only.

namespace Solution2022
{
	namespace CountUniqueCharactersofAllSubstringsofaGivenString
	{
	    int uniqueLetterString(string s) {
			vector<vector<int>> index(26, vector<int>(2, -1));
			int len = s.size();
			int mod = pow(10, 9) + 7;
			int result = 0;
			for (int i = 0; i < len; i++) {
				int c = s[i] - 'A';
				result = (result + (i - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;
				index[c][0] = index[c][1];
				index[c][1] = i;
			}

			for (int c = 0; c < 26; c++) {
				result = (result + (len - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;
			}
			return result;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
