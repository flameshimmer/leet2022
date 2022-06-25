#include "stdafx.h"

//Given an array of strings wordsDict and two strings that already exist in the
//array word1 and word2, return the shortest distance between these two words in
//the list.
//
//Note that word1 and word2 may be the same. It is guaranteed that they represent
//two individual words in the list.
// 
//
//Example 1:
//Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 =
//"makes", word2 = "coding"
//Output: 1
//
//Example 2:
//Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 =
//"makes", word2 = "makes"
//Output: 3
// 
//Constraints:
//1 <= wordsDict.length <= 105
//1 <= wordsDict[i].length <= 10
//wordsDict[i] consists of lowercase English letters.
//word1 and word2 are in wordsDict.

namespace Solution2022
{
	namespace ShortestWordDistanceIII
	{
	    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
			int i1 = -1;
			int i2 = -1;
			int result = INT_MAX;
			for (int i = 0; i < wordsDict.size(); i++) {
				if (wordsDict[i] == word1 && wordsDict[i] != word2) {
					i1 = i;
				}
				else if (wordsDict[i] == word2 && wordsDict[i] != word1) {
					i2 = i;
				}
				else if(wordsDict[i] == word1 && wordsDict[i] == word2) {
					if (i1 < i2) { i1 = i; }
					else { i2 = i; }
				}
				if (i1 >= 0 && i2 >= 0) {
					result = min(result, abs(i1 - i2));
				}
			}
			return result;
	    }

		void Main() {
			vector<string> test = {"practice", "makes", "perfect", "coding", "makes"};
			print(shortestWordDistance(test, "makes", "makes"));
		}
	}
}
