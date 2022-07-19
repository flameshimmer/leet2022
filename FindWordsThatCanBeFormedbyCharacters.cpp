#include "stdafx.h"

//You are given an array of strings words and a string chars.
//A string is good if it can be formed by characters from chars (each character
//can only be used once).
//Return the sum of lengths of all good strings in words.
// 
//
//Example 1:
//Input: words = ["cat","bt","hat","tree"], chars = "atach"
//Output: 6
//Explanation: The strings that can be formed are "cat" and "hat" so the answer
//is 3 + 3 = 6.
//
//Example 2:
//Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
//Output: 10
//Explanation: The strings that can be formed are "hello" and "world" so the
//answer is 5 + 5 = 10.
// 
//Constraints:
//1 <= words.length <= 1000
//1 <= words[i].length, chars.length <= 100
//words[i] and chars consist of lowercase English letters.

namespace Solution2022
{
	namespace FindWordsThatCanBeFormedbyCharacters
	{
		int helper(string& w, unordered_map<char, int> map) {
			for (char c : w) {
				map[c]--;
				if (map[c] < 0) { return 0; }
			}
			return w.size();
		}

	    int countCharacters(vector<string>& words, string chars) {
			unordered_map<char, int> map;
			for (char c : chars) { map[c]++; }

			int result = 0;
			for (string& w : words) {
				result += helper(w, map);
			}
			return result;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
