#include "stdafx.h"

//You are given an integer array prices where prices[i] is the price of a given
//stock on the ith day, and an integer k.
//Find the maximum profit you can achieve. You may complete at most k
//transactions.
//
//Note: You may not engage in multiple transactions simultaneously (i.e., you
//must sell the stock before you buy again).
// 
//
//Example 1:
//Input: k = 2, prices = [2,4,1]
//Output: 2
//Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit =
//4-2 = 2.
//
//Example 2:
//Input: k = 2, prices = [3,2,6,5,0,3]
//Output: 7
//Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit =
//6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit =
//3-0 = 3.
// 
//Constraints:
//0 <= k <= 100
//0 <= prices.length <= 1000
//0 <= prices[i] <= 1000

namespace Solution2022
{
	// https://www.youtube.com/watch?v=lXRe__YD8JY
	namespace BestTimetoBuyandSellStockIV
	{

		int maxProfit(int k, vector<int>& prices)
		{
			int n = prices.size();

			if (k >= n / 2)
			{
				int result = 0;
				for (int i = 1; i < prices.size(); i++)
					if (prices[i] > prices[i - 1])
						result += prices[i] - prices[i - 1];
				return result;
			}

			vector<int>hold(k + 1, INT_MIN / 2);
			vector<int>sold(k + 1, INT_MIN / 2);

			hold[0] = 0;
			sold[0] = 0;

			for (int i = 0; i < n; i++)
			{
				auto hold_old = hold;
				auto sold_old = sold;

				for (int j = 1; j <= k; j++)
				{
					hold[j] = max(sold_old[j - 1] - prices[i], hold_old[j]);
					sold[j] = max(hold_old[j] + prices[i], sold_old[j]);
				}

			}

			int result = INT_MIN;
			for (int j = 0; j <= k; j++)
				result = max(result, sold[j]);
			return result;
		}




		namespace BinarySearchWithFee {
			int len;

			vector<int> helper(vector<int>& prices, int fee)
			{
				vector<int>sell(len + 1, 0);
				vector<int>buy(len + 1, 0);
				sell[0] = 0;
				buy[0] = INT_MIN / 2;
				int sellCount = 0;
				int buyCount = 0;

				for (int i = 1; i <= len; i++)
				{
					if (buy[i - 1] + prices[i] > sell[i - 1])
					{
						sell[i] = buy[i - 1] + prices[i];
						sellCount = buyCount + 1;
					}
					else
					{
						sell[i] = sell[i - 1];
					}

					if (sell[i - 1] - prices[i] - fee > buy[i - 1])
					{
						buy[i] = sell[i - 1] - prices[i] - fee;
						buyCount = sellCount;
					}
					else
					{
						buy[i] = buy[i - 1];
					}
				}
				return { sell[len], sellCount };
			}

			int maxProfit(int k, vector<int>& prices)
			{
				len = prices.size();
				prices.insert(prices.begin(), 0);
				int left = 0;
				int right = *max_element(prices.begin(), prices.end());

				while (left < right)
				{
					int fee = left + (right - left) / 2;
					if (helper(prices, fee)[1] > k)
						left = fee + 1;
					else
						right = fee;
				}
				return helper(prices, left)[0] + left * k;
			}
		}
		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
