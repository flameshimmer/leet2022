#include "stdafx.h"
//Given two strings s1and s2, return true if s2 contains a permutation of s1, or false otherwise.
//
//In other words, return true if one of s1's permutations is the substring of s2.
//
//
//
//Example 1:
//
//Input: s1 = "ab", s2 = "eidbaooo"
//	Output : true
//	Explanation : s2 contains one permutation of s1("ba").
//	Example 2 :
//
//	Input : s1 = "ab", s2 = "eidboaoo"
//	Output : false
//
//
//	Constraints :
//
//	1 <= s1.length, s2.length <= 104
//	s1 and s2 consist of lowercase English letters.

namespace Solution2022
{
	namespace PermutationinString
	{
		bool matches(int* map1, int* map2) {
			for (int i = 0; i < 26; i++) {
				if (map1[i] != map2[i]) { return false; }
			}
			return true;
		}

		bool checkInclusion(string s1, string s2) {
			int len1 = s1.size();
			int len2 = s2.size();
			if (len1 == 0) { return true; }
			if (len1 > len2) { return false; }

			int goal[26];
			int seen[26];
			memset(goal, 0, sizeof(goal));
			memset(seen, 0, sizeof(seen));

			for (int i = 0; i < len1; i++) {
				goal[s1[i] - 'a'] ++;
				seen[s2[i] - 'a'] ++;
			}

			for (int i = 0; i < len2 - len1; i++) {
				if (matches(goal, seen)) { return true; }
				seen[s2[i] - 'a']--;
				seen[s2[len1 + i] - 'a'] ++;
			}
			return matches(goal, seen);
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
