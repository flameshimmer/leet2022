#include "stdafx.h"

//A transformation sequence from word beginWord to word endWord using a
//dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk
//such that:
//Every adjacent pair of words differs by a single letter.
//Every si for 1 <= i <= k is in wordList. 
//Note that beginWord does not need to
//be in wordList.
//sk == endWord
//Given two words, beginWord and endWord, and a dictionary wordList, return all
//the shortest transformation sequences from beginWord to endWord, or an empty
//list if no such sequence exists. Each sequence should be returned as a list of
//the words [beginWord, s1, s2, ..., sk].
// 
//
//Example 1:
//Input: beginWord = "hit", endWord = "cog", wordList =
//["hot","dot","dog","lot","log","cog"]
//Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
//Explanation: There are 2 shortest transformation sequences:
//"hit" -> "hot" -> "dot" -> "dog" -> "cog"
//"hit" -> "hot" -> "lot" -> "log" -> "cog"
//
//Example 2:
//Input: beginWord = "hit", endWord = "cog", wordList =
//["hot","dot","dog","lot","log"]
//Output: []
//Explanation: The endWord "cog" is not in wordList, therefore there is no valid
//transformation sequence.
// 
//Constraints:
//1 <= beginWord.length <= 5
//endWord.length == beginWord.length
//1 <= wordList.length <= 1000
//wordList[i].length == beginWord.length
//beginWord, endWord, and wordList[i] consist of lowercase English letters.
//beginWord != endWord
//All the words in wordList are unique.

namespace Solution2022
{
	namespace WordLadderII
	{
		namespace UseBFS {
			class Solution {
			private:
				void constructPath(string& beginWord, string& curWord, vector<string>& result, vector<vector<string>>& results, unordered_map<string, int>& levelMap) {
					if (curWord == beginWord) {
						reverse(result.begin(), result.end());
						results.push_back(result);
						reverse(result.begin(), result.end());
						return;
					}
					int level = levelMap[curWord];

					for (int i = 0; i < curWord.size(); i++) {
						char backup = curWord[i];
						for (char c = 'a'; c <= 'z'; c++) {
							curWord[i] = c;
							if (levelMap.find(curWord) != levelMap.end() && levelMap[curWord] == level - 1) {
								result.push_back(curWord);
								constructPath(beginWord, curWord, result, results, levelMap);
								result.pop_back();
							}
						}
						curWord[i] = backup;
					}
				}
			public:
				vector<vector<string>> findLadders(string beginWord, string endWord,
					vector<string>& wordList)
				{
					unordered_set<string> set(wordList.begin(), wordList.end());
					set.erase(beginWord);

					queue<string> q;
					q.push({ beginWord });

					unordered_map<string, int> levelMap;
					levelMap[beginWord] = 1;


					while (!q.empty()) {
						string top = q.front();
						int level = levelMap[top];
						q.pop();

						if (top == endWord) break;

						for (int i = 0; i < beginWord.size(); i++) {
							char backup = top[i];
							for (char c = 'a'; c <= 'z'; c++) {
								top[i] = c;
								if (set.find(top) != set.end()) {
									q.push(top);
									set.erase(top);
									levelMap[top] = level + 1;
								}
							}
							top[i] = backup;
						}
					}

					vector<vector<string>> results;
					if (levelMap.find(endWord) != levelMap.end()) {
						vector<string> result;
						result.push_back(endWord);
						constructPath(beginWord, endWord, result, results, levelMap);
					}
					return results;
				}
			};		
		}



		vector<string> getDistanceOne(string s, unordered_set<string>& dict)
		{
			vector<string> results;
			for (int i = 0; i < s.length(); i++)
			{
				char b = s[i];
				for (int j = 0; j < 26; j++)
				{
					char n = j + 'a';
					if (n == b) { continue; }
					s[i] = n;
					if (dict.find(s) != dict.end()) { results.push_back(s); }
				}
				s[i] = b;
			}
			return results;
		}

		void getPath(string s, unordered_map<string, pair<vector<string>, int>>& map, string start, vector<string>& result, vector<vector<string>>& results)
		{
			if (s == "")
			{
				if (result.back() == start)
				{
					vector<string> temp = result;
					reverse(temp.begin(), temp.end());
					results.push_back(temp);
				}
				else
				{
					results.push_back(result);
				}
				return;
			}
			result.push_back(s);
			for (string p : map[s].first)
			{
				getPath(p, map, start, result, results);
			}
			result.pop_back();
		}

		void constructPath(string s, string child, string start, unordered_map<string, pair<vector<string>, int>>& map, vector<vector<string>>& result)
		{
			vector<vector<string>> firstHalf, secondHalf;
			vector<string> merged, temp;
			getPath(s, map, start, temp, firstHalf);
			temp.clear();
			getPath(child, map, start, temp, secondHalf);

			for (vector<string> first : firstHalf)
			{
				for (vector<string>second : secondHalf)
				{
					merged.clear();
					if (first[0] == start)
					{
						merged.insert(merged.end(), first.begin(), first.end());
						merged.insert(merged.end(), second.begin(), second.end());
					}
					else
					{
						merged.insert(merged.end(), second.begin(), second.end());
						merged.insert(merged.end(), first.begin(), first.end());
					}
					result.push_back(merged);
				}
			}
		}

		vector<vector<string>> findLadders(string start, string end, vector<string>& wordList) {
			unordered_set<string> dict(wordList.begin(), wordList.end());

			vector<vector<string>> results;
			if (dict.find(end) == dict.end()) { return results; }
			dict.insert(start); dict.insert(end);
			unordered_set<string> s1, s2, temp;
			s1.insert(start); s2.insert(end);
			int level = 1; bool met = false;
			unordered_map<string, pair<vector<string>, int>> map;// key, (parents vector, level)
			map[start] = make_pair(vector<string>(1, ""), INT_MAX);
			map[end] = make_pair(vector<string>(1, ""), INT_MAX);

			while (!met && !s1.empty() && !s2.empty() && !dict.empty())
			{
				level++;
				if (s1.size() > s2.size()) { swap(s1, s2); }
				for (string s : s1)
				{
					dict.erase(s);
					vector<string> children = getDistanceOne(s, dict);
					for (string child : children)
					{
						if (s2.find(child) != s2.end())
						{
							met = true;
							constructPath(s, child, start, map, results);
						}
						else if (map.find(child) == map.end() || level <= map[child].second)
						{
							map[child].first.push_back(s);
							map[child].second = level;
						}
						if (s1.find(child) == s1.end())
						{
							temp.insert(child);
						}
					}
				}
				swap(temp, s1);
				temp.clear();
			}
			return results;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
