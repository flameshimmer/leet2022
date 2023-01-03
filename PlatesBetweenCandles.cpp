#include "stdafx.h"

//There is a long table with a line of plates and candles arranged on top of it.
//You are given a 0-indexed string s consisting of characters '*' and '|' only,
//where a '*' represents a plate and a '|' represents a candle.
//You are also given a 0-indexed 2D integer array queries where queries[i] =
//[lefti, righti] denotes the substring s[lefti...righti] (inclusive). For each
//query, you need to find the number of plates between candles that are in the
//substring. A plate is considered between candles if there is at least one
//candle to its left and at least one candle to its right in the substring.
//For example, s = "||**||**|*", and a query [3, 8] denotes the substring
//"*||**|". The number of plates between candles in this substring is 2, as each
//of the two plates has at least one candle in the substring to its left and
//right.
//Return an integer array answer where answer[i] is the answer to the ith query.
// 
//
//Example 1:
//Input: s = "**|**|***|", queries = [[2,5],[5,9]]
//Output: [2,3]
//Explanation:
//- queries[0] has two plates between candles.
//- queries[1] has three plates between candles.
//
//Example 2:
//Input: s = "***|**|*****|**||**|*", queries =
//[[1,17],[4,5],[14,17],[5,11],[15,16]]
//Output: [9,0,0,0,0]
//Explanation:
//- queries[0] has nine plates between candles.
//- The other queries have zero plates between candles.
// 
//Constraints:
//3 <= s.length <= 105
//s consists of '*' and '|' characters.
//1 <= queries.length <= 105
//queries[i].length == 2
//0 <= lefti <= righti < s.length

namespace Solution2022
{
	namespace PlatesBetweenCandles
	{

		vector<int> platesBetweenCandles(string s, vector<vector<int>>& qs) {
			int len = qs.size();
			if (len == 0) { return {}; }

			unordered_map<int, int> map;
			vector<int> candleIndex;
			int platCount = 0;
			bool seenCandle = false;
			for (int i = 0; i < s.size(); i++) {
				char c = s[i];
				if (c == '*') { platCount++; }
				else if (c == '|') {
					candleIndex.push_back(i);
					if (!seenCandle) { platCount = 0; seenCandle = true; }
					else {
						map[i] = platCount;
					}
				}				
			}

			vector<int> result;
			for (vector<int>& q : qs) {
				int start = q[0];
				int end = q[1];
				
				auto i = lower_bound(candleIndex.begin(), candleIndex.end(), start);
				auto j = lower_bound(candleIndex.begin(), candleIndex.end(), end);
				if (i == candleIndex.end() || i == j) { result.push_back(0); continue; }
				if (j == candleIndex.end() || *j != end) { j = prev(j); }
				if (j >= i) { result.push_back(map[*j] - map[*i]); }
			}
			return result;
		}


		namespace ON2 {
			vector<int> platesBetweenCandles(string s, vector<vector<int>>& qs) {
				int len = qs.size();
				if (len == 0) { return {}; }

				vector<int> result;
				for (vector<int>& q : qs) {
					int start = q[0];
					int end = q[1];
					string temp = s.substr(start, end - start + 1);
					int b1 = temp.find_first_of('|');
					int b2 = temp.find_last_of('|');
					if (b1 == -1 || b1 == b2) { result.push_back(0); continue; }
					int count = 0;
					for (int i = b1; i <= b2; i++) { if (temp[i] == '*') { count++; } }
					result.push_back(count);
				}
				return result;
			}
		}
		

		void Main() {
			vector<vector<int>> test = { {1,17},{4,5},{14,17},{5,11},{15,16} };
			print(platesBetweenCandles("***|**|*****|**||**|*", test));
		}
	}
}
