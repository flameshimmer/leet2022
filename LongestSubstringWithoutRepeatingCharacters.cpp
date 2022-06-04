#include "stdafx.h"
//Given a string s, find the length of the longest 
//substring without repeating characters.
//
//Example 1:
//
//Input: s = "abcabcbb"
//	Output : 3
//	Explanation : The answer is "abc", with the length of 3.
//	Example 2 :
//
//	Input : s = "bbbbb"
//	Output : 1
//	Explanation : The answer is "b", with the length of 1.
//	Example 3 :
//
//	Input : s = "pwwkew"
//	Output : 3
//	Explanation : The answer is "wke", with the length of 3.
//	Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
//
//
//	Constraints :
//
//	0 <= s.length <= 5 * 104
//	s consists of English letters, digits, symbols and spaces.
namespace Solution2022
{
	namespace LongestSubstringWithoutRepeatingCharacters
	{
		int lengthOfLongestSubstring(string s) {
			int len = s.size();
			if (len < 2) { return len; }
			
			int seen[256];
			memset(seen, -1, sizeof(seen));
			int front = 0;
			int back = 0;
			int maxLen = 0;

			while (front < len) {
				char c = s[front];
				if (seen[c] != -1) {
					maxLen = max(maxLen, front - back);
					back = max(back, seen[c] + 1);
				}
				seen[c] = front;
				front++;
			}
			maxLen = max(maxLen, front - back);
			return maxLen;
		}


		int lengthOfLongestSubstringSecondWay(string s) {
			int len = s.size();
			if (len < 2) { return len; }

			int front = 0;
			int back = 0;
			unordered_set<int> seen;
			int maxLen = 0;
			while (front < len) {
				if (seen.find(s[front]) == seen.end()) {
					seen.insert(s[front]);
				}
				else {
					maxLen = max(maxLen, front - back);
					while (s[back] != s[front]) {
						seen.erase(s[back]);
						back++;
					}
					back++;
				}
				front++;
			}
			maxLen = max(maxLen, front - back);
			return maxLen;
		}

		void Main() {
			string test = "tst test test";
			print(lengthOfLongestSubstring("pwwkew"));
		}
	}
}
