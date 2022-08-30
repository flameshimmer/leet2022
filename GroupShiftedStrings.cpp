#include "stdafx.h"

//We can shift a string by shifting each of its letters to its successive letter.
//For example, "abc" can be shifted to be "bcd".
//We can keep shifting the string to form a sequence.
//For example, we can keep shifting "abc" to form the sequence: "abc" -> "bcd" ->
//... -> "xyz".
//Given an array of strings strings, group all strings[i] that belong to the same
//shifting sequence. You may return the answer in any order.
// 
//
//Example 1:
//Input: strings = ["abc","bcd","acef","xyz","az","ba","a","z"]
//Output: [["acef"],["a","z"],["abc","bcd","xyz"],["az","ba"]]
//
//Example 2:
//Input: strings = ["a"]
//Output: [["a"]]
// 
//Constraints:
//1 <= strings.length <= 200
//1 <= strings[i].length <= 50
//strings[i] consists of lowercase English letters.

namespace Solution2022
{
	namespace GroupShiftedStrings
	{
		string getKey(string& s) {
			string key;
			for (int i = 1; i < s.size(); i++) {
				int diff = (s[i] - s[i - 1] + 26) % 26;
				key += 'a' + diff + '_';
			}
			return key;
		}

		vector<vector<string>> groupStrings(vector<string>& strings) {			
			unordered_map<string, vector<string>> map;
			for (string& s : strings) {
				map[getKey(s)].push_back(s);
			}

			vector<vector<string>> result;
			for (auto& p : map) {
				result.push_back(p.second);
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
