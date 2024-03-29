#include "stdafx.h"

//You are given an array prices where prices[i] is the price of a given stock on
//the ith day.
//You want to maximize your profit by choosing a single day to buy one stock and
//choosing a different day in the future to sell that stock.
//Return the maximum profit you can achieve from this transaction. If you cannot
//achieve any profit, return 0.
// 
//
//Example 1:
//Input: prices = [7,1,5,3,6,4]
//Output: 5
//Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit =
//6-1 = 5.
//
//Note that buying on day 2 and selling on day 1 is not allowed because you must
//buy before you sell.
//
//Example 2:
//Input: prices = [7,6,4,3,1]
//Output: 0
//Explanation: In this case, no transactions are done and the max profit = 0.
// 
//Constraints:
//1 <= prices.length <= 105
//0 <= prices[i] <= 104

namespace Solution2022
{
	namespace BestTimetoBuyandSellStock
	{
		int maxProfit(vector<int>& prices) {
			int len = prices.size();
			if (len < 2) { return 0; }

			vector<int>maxRight(len, 0);
			int result = 0;
			for (int i = len - 2; i >= 0; i--) {
				maxRight[i] = max(maxRight[i + 1], prices[i + 1]);
				result = max(result, maxRight[i] - prices[i]);
			}
			return result;
		}

		namespace Another {
			int maxProfit(vector<int>& prices) {
				int len = prices.size();
				if (len < 2) { return 0; }

				vector<int> minLeft(len, prices[0]);
				vector<int> maxRight(len, prices[len - 1]);

				for (int i = 1; i < len; i++) {
					minLeft[i] = min(minLeft[i - 1], prices[i]);
					maxRight[len - 1 - i] = max(maxRight[len - i], prices[len - 1 - i]);
				}
				int result = INT_MIN;
				for (int i = 0; i < len; i++) {
					result = max(result, maxRight[i] - minLeft[i]);
				}
				return result;
			}
		}


		void Main() {
			vector<int> test = { 7,1,5,3,6,4 };
			print(maxProfit(test));
		}
	}
}
