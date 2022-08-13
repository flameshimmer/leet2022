#include "stdafx.h"

//Given a string s and a dictionary of strings wordDict, add spaces in s to
//construct a sentence where each word is a valid dictionary word. Return all
//such possible sentences in any order.
//
//Note that the same word in the dictionary may be reused multiple times in the
//segmentation.
// 
//
//Example 1:
//Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
//Output: ["cats and dog","cat sand dog"]
//
//Example 2:
//Input: s = "pineapplepenapple", wordDict =
//["apple","pen","applepen","pine","pineapple"]
//Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
//Explanation: 
//Note that you are allowed to reuse a dictionary word.
//
//Example 3:
//Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
//Output: []
// 
//Constraints:
//1 <= s.length <= 20
//1 <= wordDict.length <= 1000
//1 <= wordDict[i].length <= 10
//s and wordDict[i] consist of only lowercase English letters.
//All the strings of wordDict are unique.

namespace Solution2022
{
	namespace WordBreakII
	{
		void helper(int start, int len, string& s, unordered_set<string>& dict, string result, vector<string>& results, vector<bool>& P) {
			if (start == len) {
				result.pop_back();
				results.push_back(result);
				return;
			}

			for (int i = start; i < len; i++) {
				string cur = s.substr(start, i - start + 1);
				if (dict.find(cur) != dict.end() && P[i + 1]) {
					int oldSize = results.size();
					helper(i + 1, len, s, dict, result + cur + " ", results, P);
					if (results.size() == oldSize) { P[i + 1] = false; }
				}
			}
		}


		vector<string> wordBreak(string s, vector<string>& wordDict) {
			int len = s.size();
			unordered_set<string> dict(wordDict.begin(), wordDict.end());
			vector<bool> P(len, true);
			string result;
			vector<string> results;
			helper(0, len, s, dict, result, results, P);
			return results;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
