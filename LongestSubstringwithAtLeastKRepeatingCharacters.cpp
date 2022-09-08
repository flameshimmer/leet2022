#include "stdafx.h"

//Given a string s and an integer k, return the length of the longest substring
//of s such that the frequency of each character in this substring is greater
//than or equal to k.
// 
//
//Example 1:
//Input: s = "aaabb", k = 3
//Output: 3
//Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
//
//Example 2:
//Input: s = "ababbc", k = 2
//Output: 5
//Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and
//'b' is repeated 3 times.
// 
//Constraints:
//1 <= s.length <= 104
//s consists of only lowercase English letters.
//1 <= k <= 105

namespace Solution2022
{
	namespace LongestSubstringwithAtLeastKRepeatingCharacters
	{

		int longestSubstring(string s, int k) {
			int len = s.size();
			unordered_map<char, int> map;
			for (char c : s) { map[c]++; }

			int i = 0;
			while (i < len && map[s[i]] >= k) { i++; }
			if (i == len) { return len; }

			int left = longestSubstring(s.substr(0, i), k);
			int right = longestSubstring(s.substr(i + 1), k);
			return max(left, right);
		}

		namespace TwoPointers {
			//https://www.youtube.com/watch?v=_MJKUvM-4fM
			int longestSubstring(string s, int k) {
				int len = s.size();
				int result = 0;

				for (int i = 1; i <= 26; i++) {
					unordered_map<char, int> map;
					int start = 0;
					int end = 0;
					int uniqueChar = 0;
					while (end < len) {
						bool valid = true;
						char c = s[end];
						if (map[c] == 0) { uniqueChar++; }
						map[c]++;
						end++;

						while (uniqueChar > i) {
							char c2 = s[start];
							if (map[c2] == 1) { uniqueChar--; }
							map[c2]--;
							start++;
						}
						for (char j = 'a'; j <= 'z'; j++) {
							if (map[j] > 0 && map[j] < k) { valid = false; }
						}
						if (valid) { result = max(result, end - start); }
					}
				}
				return result;
			}
		}

		void Main() {
			print(longestSubstring("ababbc", 3));
			print(longestSubstring("weitong", 2));
			print(longestSubstring("aaabb", 3));
			print(longestSubstring("ababbc", 2));
		}
	}
}
