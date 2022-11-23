#include "stdafx.h"

//Given a string array words, return an array of all characters that show up in
//all strings within the words (including duplicates). You may return the answer
//in any order.
// 
//
//Example 1:
//Input: words = ["bella","label","roller"]
//Output: ["e","l","l"]
//
//Example 2:
//Input: words = ["cool","lock","cook"]
//Output: ["c","o"]
// 
//Constraints:
//1 <= words.length <= 100
//1 <= words[i].length <= 100
//words[i] consists of lowercase English letters.

namespace Solution2022
{
	namespace FindCommonCharacters
	{
		vector<int> helper(string& s) {
			vector<int> result(26, 0);
			for (char c : s) { result[c - 'a']++; }
			return result;
		}

	    vector<string> commonChars(vector<string>& words) {			
			int len = words.size();
			if (len == 0) { return {}; }

			vector<vector<int>> maps;
			for (string& w : words) { maps.push_back(helper(w)); }

			vector<string> result;
			vector<int> map0 = maps[0];
			for (int i = 0; i < 26; i++) {
				int minCount = map0[i];
				for (int j = 1; j < len; j++) {
					minCount = min(minCount, maps[j][i]);
				}
				for (int k = 0; k < minCount; k++) { result.push_back(string(1, 'a' + i)); }
			}
			return result;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
