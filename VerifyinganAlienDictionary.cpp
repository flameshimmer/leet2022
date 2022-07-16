#include "stdafx.h"

//In an alien language, surprisingly, they also use English lowercase letters,
//but possibly in a different order. The order of the alphabet is some
//permutation of lowercase letters.
//Given a sequence of words written in the alien language, and the order of the
//alphabet, return true if and only if the given words are sorted
//lexicographically in this alien language.
// 
//
//Example 1:
//Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
//Output: true
//Explanation: As 'h' comes before 'l' in this language, then the sequence is
//sorted.
//
//Example 2:
//Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
//Output: false
//Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1],
//hence the sequence is unsorted.
//
//Example 3:
//Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
//Output: false
//Explanation: The first three characters "app" match, and the second string is
//shorter (in size.) According to lexicographical rules "apple" > "app", because
//'l' > '∅', where '∅' is defined as the blank character which is less than any
//other character (More info).
// 
//Constraints:
//1 <= words.length <= 100
//1 <= words[i].length <= 20
//order.length == 26
//All characters in words[i] and order are English lowercase letters.

namespace Solution2022
{
	namespace VerifyinganAlienDictionary
	{

		bool isAlienSorted(vector<string>& words, string order) {
			unordered_map<char, int> map;
			for (int i = 0; i < order.size(); i++) {
				map[order[i]] = i;
			}

			auto comp = [&map](string& a, string& b) {
				int lena = a.size();
				int lenb = b.size();
				for (int i = 0; i < min(lena, lenb); i++) {
					if (a[i] != b[i]) { return map[a[i]] < map[b[i]]; }
				}
				return lena < lenb;
			};

			return is_sorted(words.begin(), words.end(), comp);
		}

		void Main() {
			vector<string> test = { "hello", "leetcode"};
			print(isAlienSorted(test, "hlabcdefgijkmnopqrstuvwxyz"));
		}
	}
}
