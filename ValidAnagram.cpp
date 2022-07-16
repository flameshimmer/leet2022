#include "stdafx.h"

//Given two strings s and t, return true if t is an anagram of s, and false
//otherwise.
//An Anagram is a word or phrase formed by rearranging the letters of a different
//word or phrase, typically using all the original letters exactly once.
// 
//
//Example 1:
//Input: s = "anagram", t = "nagaram"
//Output: true
//
//Example 2:
//Input: s = "rat", t = "car"
//Output: false
// 
//Constraints:
//1 <= s.length, t.length <= 5 * 104
//s and t consist of lowercase English letters.
// 
//Follow up: What if the inputs contain Unicode characters? How would you adapt
//your solution to such a case?

namespace Solution2022
{
	namespace ValidAnagram
	{
	    bool isAnagram(string s, string t) {
			vector<int> map1(26, 0);
			vector<int> map2(26, 0);

			for (char c : s) {
				map1[c - 'a']++;
			}
			for (char c : t) {
				map2[c - 'a']++;
			}
			
			for (int i = 0; i < 26; i++) {
				if (map1[i] != map2[i]) { return false; }
			}
			return true;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
