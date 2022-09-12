#include "stdafx.h"

//Given a string s, remove duplicate letters so that every letter appears once
//and only once. You must make sure your result is the smallest in
//lexicographical order among all possible results.
// 
//
//Example 1:
//Input: s = "bcabc"
//Output: "abc"
//
//Example 2:
//Input: s = "cbacdcbc"
//Output: "acdb"
// 
//Constraints:
//1 <= s.length <= 104
//s consists of lowercase English letters.
// 
//
//Note: This question is the same as 1081:
//https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

namespace Solution2022
{
	namespace RemoveDuplicateLetters
	{
		string removeDuplicateLetters(string s) {
			vector<int> count(26, 0); // count after current position
			for (char c : s) { count[c - 'a']++; }

			vector<bool> used(26, false);
			string result;

			for (char c : s) {
				count[c - 'a']--;
				if (used[c - 'a']) { continue; }

				while (!result.empty() && result.back() > c && count[result.back() - 'a'] > 0) {
					used[result.back() - 'a'] = false; // Note: this will have to happen before result pop_back!!!
					result.pop_back();
				}
				result += c;
				used[c - 'a'] = true;
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
