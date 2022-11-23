#include "stdafx.h"

//Given two strings s and t, determine if they are isomorphic.
//Two strings s and t are isomorphic if the characters in s can be replaced to
//get t.
//All occurrences of a character must be replaced with another character while
//preserving the order of characters. No two characters may map to the same
//character, but a character may map to itself.
// 
//
//Example 1:
//Input: s = "egg", t = "add"
//Output: true
//
//Example 2:
//Input: s = "foo", t = "bar"
//Output: false
//
//Example 3:
//Input: s = "paper", t = "title"
//Output: true
// 
//Constraints:
//1 <= s.length <= 5 * 104
//t.length == s.length
//s and t consist of any valid ascii character.

namespace Solution2022
{
	namespace IsomorphicStrings
	{
		bool isIsomorphic(string s, string t) {
			int lens = s.size();
			int lent = t.size();
			if (lens != lent) { return false; }
			if (lens == 0) { return true; }

			unordered_map<char, char> map;
			unordered_set<char> set;
			for (int i = 0; i < lens; i++) {
				char c1 = s[i];
				char c2 = t[i];
				if (map.find(c1) != map.end() && map[c1] != c2) { return false; }
				if (map.find(c1) == map.end() && set.find(c2) != set.end()) { return false; }
				map[c1] = c2;
				set.insert(c2);
			}
			return true;
		}

		void Main() {
			print(isIsomorphic("foo", "bar"));
		}
	}
}
