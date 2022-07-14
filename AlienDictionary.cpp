#include "stdafx.h"

//There is a new alien language that uses the English alphabet. However, the
//order among the letters is unknown to you.
//You are given a list of strings words from the alien language's dictionary,
//where the strings in words are sorted lexicographically by the rules of this
//new language.
//Return a string of the unique letters in the new alien language sorted in
//lexicographically increasing order by the new language's rules. If there is no
//solution, return "". If there are multiple solutions, return any of them.
//A string s is lexicographically smaller than a string t if at the first letter
//where they differ, the letter in s comes before the letter in t in the alien
//language. If the first min(s.length, t.length) letters are the same, then s is
//smaller if and only if s.length < t.length.
// 
//
//Example 1:
//Input: words = ["wrt","wrf","er","ett","rftt"]
//Output: "wertf"
//
//Example 2:
//Input: words = ["z","x"]
//Output: "zx"
//
//Example 3:
//Input: words = ["z","x","z"]
//Output: ""
//Explanation: The order is invalid, so return "".
// 
//Constraints:
//1 <= words.length <= 100
//1 <= words[i].length <= 100
//words[i] consists of only lowercase English letters.

namespace Solution2022
{
	namespace AlienDictionary
	{
	    string alienOrder(vector<string>& words) {
			int len = words.size();
			unordered_map<char, int> indegree;
			unordered_map<char, unordered_set<char>> adj;

			for (string& w : words) {
				for (char c : w) {
					indegree[c] = 0;
				}
			}

			for (int i = 0; i < len - 1; i++) {
				string& w1 = words[i];
				string& w2 = words[i + 1];

				int minLen = min(w1.size(), w2.size());
				if (w1.substr(0, minLen) == w2.substr(0, minLen) && w1.size() > w2.size()) { return ""; }
				for (int j = 0; j < minLen; j++) {
					char c1 = w1[j];
					char c2 = w2[j];
					if (c1 != c2) {
						if (adj[c1].count(c2) == 0) {
							adj[c1].insert(c2);
							indegree[c2]++;
						}
						break;
					}					
				}
			}

			string result;
			queue<char> q;
			for (auto [c, count] : indegree) {
				if (count == 0) { q.push(c); }
			}

			while (!q.empty()) {
				char top = q.front();
				q.pop();

				result.push_back(top);
				for (char n : adj[top]) {
					indegree[n]--;
					if (indegree[n] == 0) { q.push(n); }
				}
			}
			return result.size() == indegree.size() ? result : "";
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
