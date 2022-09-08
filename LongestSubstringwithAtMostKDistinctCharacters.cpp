#include "stdafx.h"

//Given a string s and an integer k, return the length of the longest substring
//of s that contains at most k distinct characters.
// 
//
//Example 1:
//Input: s = "eceba", k = 2
//Output: 3
//Explanation: The substring is "ece" with length 3.
//
//Example 2:
//Input: s = "aa", k = 1
//Output: 2
//Explanation: The substring is "aa" with length 2.
// 
//Constraints:
//1 <= s.length <= 5 * 104
//0 <= k <= 50

namespace Solution2022
{
	namespace LongestSubstringwithAtMostKDistinctCharacters
	{
		int lengthOfLongestSubstringKDistinct(string s, int k) {
			int len = s.size();
			if (len <= k) { return len; }

			unordered_map<char, int> map;
			int start = 0;
			int end = 0;
			int result = 0;

			while (end < len) {
				map[s[end]]++;
				if (map.size() > k) {
					result = max(result, end - start);
					while (map.size() > k) {
						char c = s[start];
						map[c]--;
						if (map[c] == 0) { map.erase(c); }
						start++;
					}
				}
				end++; // Note: Don't forget to increment end here!!!
			}
			result = max(result, end - start);
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
