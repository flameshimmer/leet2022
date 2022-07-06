#include "stdafx.h"

//You are given an array of strings products and a string searchWord.
//Design a system that suggests at most three product names from products after
//each character of searchWord is typed. Suggested products should have common
//prefix with searchWord. If there are more than three products with a common
//prefix return the three lexicographically minimums products.
//Return a list of lists of the suggested products after each character of
//searchWord is typed.
// 
//
//Example 1:
//Input: products = ["mobile","mouse","moneypot","monitor","mousepad"],
//searchWord = "mouse"
//Output: [
//["mobile","moneypot","monitor"],
//["mobile","moneypot","monitor"],
//["mouse","mousepad"],
//["mouse","mousepad"],
//["mouse","mousepad"]
//]
//Explanation: products sorted lexicographically =
//["mobile","moneypot","monitor","mouse","mousepad"]
//After typing m and mo all products match and we show user
//["mobile","moneypot","monitor"]
//After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
//
//Example 2:
//Input: products = ["havana"], searchWord = "havana"
//Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
//
//Example 3:
//Input: products = ["bags","baggage","banner","box","cloths"], searchWord =
//"bags"
//[["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
// 
//Constraints:
//1 <= products.length <= 1000
//1 <= products[i].length <= 3000
//1 <= sum(products[i].length) <= 2 * 104
//All the strings of products are unique.
//products[i] consists of lowercase English letters.
//1 <= searchWord.length <= 1000
//searchWord consists of lowercase English letters.

namespace Solution2022
{
	namespace SearchSuggestionsSystem
	{
	    vector<vector<string>> suggestedProducts(vector<string>& A, string searchWord) {
			sort(A.begin(), A.end());
			
			vector<vector<string>> results;
			string cur = "";

			for (char c : searchWord) {
				cur += c;
				vector<string> result;
				auto it = lower_bound(A.begin(), A.end(), cur);
				for (int i = 0; i < 3 && it + i < A.end(); i++) {
					string& s = *(it + i);
					if (s.find(cur) == string::npos) { break; }
					result.push_back(s);
				}
				results.push_back(result);
			}
			return results;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
