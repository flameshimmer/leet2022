#include "stdafx.h"

//Given a string s, consider all duplicated substrings: (contiguous) substrings
//of s that occur 2 or more times. The occurrences may overlap.
//Return any duplicated substring that has the longest possible length. If s does
//not have a duplicated substring, the answer is "".
// 
//
//Example 1:
//Input: s = "banana"
//Output: "ana"
//
//Example 2:
//Input: s = "abcd"
//Output: ""
// 
//Constraints:
//2 <= s.length <= 3 * 104
//s consists of lowercase English letters.

namespace Solution2022
{
	namespace LongestDuplicateSubstring
	{
		typedef uint64_t ULL;
		unordered_map<int, int>len2start;

		bool found(string& s, int len) {
			unordered_set<ULL> set;
			ULL base = 31;
			ULL hash = 0;

			ULL powBaseLen = 1;
			for (int i = 0; i < len; i++) { powBaseLen *= base; }

			for (int i = 0; i < s.size(); i++) {
				hash = hash * base + (s[i] - 'a');
				if (i >= len) {
					hash -= powBaseLen * (s[i - len] - 'a');  // i - ? + 1 = len + 1, thus ? = i-len
				}

				if (i >= len - 1) {
					if (set.find(hash) != set.end()) {
						len2start[len] = i - len + 1; // i - ? + 1 = len, thus ? = i-len + 1
						return true;
					}
					set.insert(hash);
				}
			}
			return false;
		}

		string longestDupSubstring(string s) {
			int left = 1;
			int right = s.size() - 1;
			while (left < right) {
				int mid = right - (right - left) / 2;
				if (found(s, mid)) {
					left = mid;
				}
				else {
					right = mid - 1;
				}
			}
			if (found(s, left)) {
				return s.substr(len2start[left], left);
			}
			return "";
		}



		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
