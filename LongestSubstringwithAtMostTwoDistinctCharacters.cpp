#include "stdafx.h"

//Given a string s, return the length of the longest substring that contains at
//most two distinct characters.
// 
//
//Example 1:
//Input: s = "eceba"
//Output: 3
//Explanation: The substring is "ece" which its length is 3.
//
//Example 2:
//Input: s = "ccaabbb"
//Output: 5
//Explanation: The substring is "aabbb" which its length is 5.
// 
//Constraints:
//1 <= s.length <= 105
//s consists of English letters.

namespace Solution2022
{
	namespace LongestSubstringwithAtMostTwoDistinctCharacters
	{

		int lengthOfLongestSubstringTwoDistinct(string s) {
			int len = s.size();
			if (len <= 2) { return len; }
			unordered_map<char, int> map;

			int start = 0;
			int end = 0;
			int result = 0;

			while (end < len) {
				map[s[end]] ++;

				if (map.size() > 2) {
					result = max(result, end - start);
					while (map.size() > 2) {
						char c = s[start];
						map[c]--;
						if (map[c] == 0) { map.erase(c); }
						start++;
					}
				}
				end++;
			}
			result = max(result, end - start);
			return result;
		}

		
		namespace Another {
			int lengthOfLongestSubstringTwoDistinct(string s) {
				int len = s.size();
				if (len < 3) { return len; }
				unordered_map<char, int> map;

				int start = 0;
				int end = 0;
				int result = 0;
				while (end < len) {
					if (map.find(s[end]) != map.end() || map.size() < 2) {
						map[s[end]]++;
						end++;
					}
					else {
						result = max(result, end - start);
						while (map.size() >= 2) {
							char c = s[start];
							map[c]--;
							if (map[c] == 0) { map.erase(c); }
							start++;
						}
					}
				}
				result = max(result, end - start);
				return result;
			}
		}

		void Main() {
			print(lengthOfLongestSubstringTwoDistinct("eceba"));
		}
	}
}
