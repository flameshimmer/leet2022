#include "stdafx.h"

//Given a string s and an array of strings words, return the number of words[i]
//that is a subsequence of s.
//A subsequence of a string is a new string generated from the original string
//with some characters (can be none) deleted without changing the relative order
//of the remaining characters.
//For example, "ace" is a subsequence of "abcde".
// 
//
//Example 1:
//Input: s = "abcde", words = ["a","bb","acd","ace"]
//Output: 3
//Explanation: There are three strings in words that are a subsequence of s: "a",
//"acd", "ace".
//
//Example 2:
//Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
//Output: 2
// 
//Constraints:
//1 <= s.length <= 5 * 104
//1 <= words.length <= 5000
//1 <= words[i].length <= 50
//s and words[i] consist of only lowercase English letters.

namespace Solution2022
{
	namespace NumberofMatchingSubsequences
	{
		int numMatchingSubseq(string s, vector<string>& words) {
			vector<vector<int>> charIndexes(26, vector<int>());
			for (int i = 0; i < s.size(); i++) {
				charIndexes[s[i] - 'a'].push_back(i);
			}

			int result = 0;
			for (string& w : words) {
				int lastIndex = -1;
				bool found = true;

				for (char c : w) {
					vector<int>& indexes = charIndexes[c - 'a'];
					auto it = lower_bound(indexes.begin(), indexes.end(), lastIndex + 1);
					if (it == indexes.end()) {
						found = false;
						break;
					}
					lastIndex = *it;
				}
				if (found) { result++; }
			}
			return result;
		}

		void Main() {
			vector<string> test = {"a", "bb", "acd", "ace"};
			print(numMatchingSubseq("abcde", test));
		}
	}
}
