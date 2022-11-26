#include "stdafx.h"

//Given a string s, rearrange the characters of s so that any two adjacent
//characters are not the same.
//Return any possible rearrangement of s or return "" if not possible.
// 
//
//Example 1:
//Input: s = "aab"
//Output: "aba"
//
//Example 2:
//Input: s = "aaab"
//Output: ""
// 
//Constraints:
//1 <= s.length <= 500
//s consists of lowercase English letters.

namespace Solution2022
{
	namespace ReorganizeString
	{
		string reorganizeString(string s) {
			int len = s.size();
			vector<int> map(26, 0);
			int maxFreqV = 0;
			int maxFreqI = -1;
			for (char c : s) {
				map[c - 'a']++;
				if (map[c - 'a'] > maxFreqV) {
					maxFreqV = map[c - 'a'];
					maxFreqI = c - 'a';
				}
			}

			if (maxFreqV > (len + 1) / 2) { return ""; }

			string result(len, ' ');
			int i = 0;
			while (map[maxFreqI]) {
				result[i] = 'a' + maxFreqI;
				i += 2;
				map[maxFreqI] --;
			}

			for (int j = 0; j < 26; j++) {
				while (map[j]) {
					if (i >= len) { i = 1; }
					result[i] = 'a' + j;
					map[j]--;
					i += 2;
				}
			}
			return result;
		}

		void Main() {
			print(reorganizeString("aab"));
		}
	}
}
