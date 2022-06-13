#include "stdafx.h"

//Given an array of distinct strings words, return the minimal possible
//abbreviations for every word.
//The following are the rules for a string abbreviation:
//Begin with the first character, and then the number of characters abbreviated,
//followed by the last character.
//If there is any conflict and more than one word shares the same abbreviation, a
//longer prefix is used instead of only the first character until making the map
//from word to abbreviation become unique. In other words, a final abbreviation
//cannot map to more than one original word.
//If the abbreviation does not make the word shorter, then keep it as the
//original.
// 
//
//Example 1:
//["like","god","internal","me","internet","interval","intension","face","intrusion"]
//Output: ["l2e","god","internal","me","i6t","interval","inte4n","f2e","intr4n"]
//
//Example 2:
//Input: words = ["aa","aaa"]
//Output: ["aa","aaa"]
// 
//Constraints:
//1 <= words.length <= 400
//2 <= words[i].length <= 400
//words[i] consists of lowercase English letters.
//All the strings of words are unique.

namespace Solution2022
{
	namespace WordAbbreviation
	{

	//    vector<string> wordsAbbreviation(vector<string>& words) {
	//        
	//    }


		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
