#include "stdafx.h"

//Given two strings first and second, consider occurrences in some text of the
//form "first second third", where second comes immediately after first, and
//third comes immediately after second.
//Return an array of all the words third for each occurrence of "first second
//third".
// 
//
//Example 1:
//Input: text = "alice is a good girl she is a good student", first = "a", second
//= "good"
//Output: ["girl","student"]
//
//Example 2:
//Input: text = "we will we will rock you", first = "we", second = "will"
//Output: ["we","rock"]
// 
//Constraints:
//1 <= text.length <= 1000
//text consists of lowercase English letters and spaces.
//All the words in text a separated by a single space.
//1 <= first.length, second.length <= 10
//first and second consist of lowercase English letters.

namespace Solution2022
{
	namespace OccurrencesAfterBigram
	{
	    vector<string> findOcurrences(string text, string first, string second) {
	        
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
