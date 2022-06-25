#include "stdafx.h"

//Given an array of strings wordsDict and two different strings that already
//exist in the array word1 and word2, return the shortest distance between these
//two words in the list.
// 
//
//Example 1:
//Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 =
//"coding", word2 = "practice"
//Output: 3
//
//Example 2:
//Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 =
//"makes", word2 = "coding"
//Output: 1
// 
//Constraints:
//1 <= wordsDict.length <= 3 * 104
//1 <= wordsDict[i].length <= 10
//wordsDict[i] consists of lowercase English letters.
//word1 and word2 are in wordsDict.
//word1 != word2

namespace Solution2022
{
	namespace ShortestWordDistance
	{
	    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
			int i1 = -1;
			int i2 = -1;
			int result = wordsDict.size();
			for (int i = 0; i < wordsDict.size(); i++) {
				if (wordsDict[i] == word1) {
					i1 = i;
				}
				else if (wordsDict[i] == word2) {
					i2 = i;
				}
				if (i1 >= 0 && i2 >= 0) {
					result = min(result, abs(i1 - i2));
				}
			}
			return result;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
