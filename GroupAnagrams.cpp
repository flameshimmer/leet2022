#include "stdafx.h"

//Given an array of strings strs, group the anagrams together. You can return the
//answer in any order.
//An Anagram is a word or phrase formed by rearranging the letters of a different
//word or phrase, typically using all the original letters exactly once.
// 
//
//Example 1:
//Input: strs = ["eat","tea","tan","ate","nat","bat"]
//Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
//
//Example 2:
//Input: strs = [""]
//Output: [[""]]
//
//Example 3:
//Input: strs = ["a"]
//Output: [["a"]]
// 
//Constraints:
//1 <= strs.length <= 104
//0 <= strs[i].length <= 100
//strs[i] consists of lowercase English letters.

namespace Solution2022
{
	namespace GroupAnagrams
	{
		string getAnagram(string& s) {
			vector<int> map(26, 0);
			for (char c : s) {
				map[c - 'a']++;
			}
			string result = "";
			for (int i = 0; i < 26; i++) {
				result += string(1, ('a' + i)) + to_string(map[i]);
			}
			return result;
		}
		
		vector<vector<string>> groupAnagrams(vector<string>& strs) {
			vector<vector<string>> result;
			int len = strs.size();
			if (len == 0) { return result; }

			unordered_map<string, vector<string>> map;
			for (string& s : strs) {
				map[getAnagram(s)].push_back(s);
			}
			for (auto& [key, group] : map) {
				result.push_back(group);
			}
			return result;
	    }

		void Main() {
			vector<string> test = { "eat","tea","tan","ate","nat","bat"};
			print(groupAnagrams(test));
		}
	}
}
