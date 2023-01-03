#include "stdafx.h"

//Given a string text, you want to use the characters of text to form as many
//instances of the word "balloon" as possible.
//You can use each character in text at most once. Return the maximum number of
//instances that can be formed.
// 
//
//Example 1:
//Input: text = "nlaebolko"
//Output: 1
//
//Example 2:
//Input: text = "loonbalxballpoon"
//Output: 2
//
//Example 3:
//Input: text = "leetcode"
//Output: 0
// 
//Constraints:
//1 <= text.length <= 104
//text consists of lower case English letters only.

namespace Solution2022
{
	namespace MaximumNumberofBalloons
	{
		int maxNumberOfBalloons(string text) {
			unordered_map<char, int> map;
			for (char c : text) { map[c] ++; }
			return min(map['b'], min(map['a'], min(map['l'] / 2, min(map['o'] / 2, map['n']))));
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
