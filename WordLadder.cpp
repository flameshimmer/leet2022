#include "stdafx.h"

//A transformation sequence from word beginWord to word endWord using a
//dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk
//such that:
//Every adjacent pair of words differs by a single letter.
//Every si for 1 <= i <= k is in wordList. 
//Note that beginWord does not need to
//be in wordList.
//sk == endWord
//Given two words, beginWord and endWord, and a dictionary wordList, return the
//number of words in the shortest transformation sequence from beginWord to
//endWord, or 0 if no such sequence exists.
// 
//
//Example 1:
//Input: beginWord = "hit", endWord = "cog", wordList =
//["hot","dot","dog","lot","log","cog"]
//Output: 5
//Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" ->
//"dog" -> cog", which is 5 words long.
//
//Example 2:
//Input: beginWord = "hit", endWord = "cog", wordList =
//["hot","dot","dog","lot","log"]
//Output: 0
//Explanation: The endWord "cog" is not in wordList, therefore there is no valid
//transformation sequence.
// 
//Constraints:
//1 <= beginWord.length <= 10
//endWord.length == beginWord.length
//1 <= wordList.length <= 5000
//wordList[i].length == beginWord.length
//beginWord, endWord, and wordList[i] consist of lowercase English letters.
//beginWord != endWord
//All the words in wordList are unique.

namespace Solution2022
{
	namespace WordLadder
	{
	    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
			unordered_set<string> dict(wordList.begin(), wordList.end());
			queue<string> q;
			q.push(beginWord);
			int level = 1;
			
			while (!q.empty()) {
				int sz = q.size();
				while (sz) {
					sz--;
					string top = q.front();
					q.pop();
					if (top == endWord) { return level; }

					// The diff between wordladderI and wordladderII: I only need to find the shortest distant 
					//and will return length at the earlies chance, thus we can remove the top from candidate list. 
					// For II, since we need to find all possible path, we can't just remove the top, 
					// since both "cop" and "cup" can go to "cap", if we move candiate when we process cop, 
					// the cup will loose this candidate. Thus for II, the candidate erasing from the dict is 
					// done when level increased by 1 time.  
					dict.erase(top); 
					for (int i = 0; i < top.size(); i++) {
						char backup = top[i];
						for (char c = 'a'; c <= 'z'; c++) {
							if (c == backup) { continue; }
							top[i] = c;
							if (dict.find(top) != dict.end()) { q.push(top); }
						}
						top[i] = backup;
					}
				}
				level++;
			}
			return 0;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
