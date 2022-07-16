#include "stdafx.h"

//You are given an array of transactions transactions where transactions[i] =
//[fromi, toi, amounti] indicates that the person with ID = fromi gave amounti $
//to the person with ID = toi.
//Return the minimum number of transactions required to settle the debt.
// 
//
//Example 1:
//Input: transactions = [[0,1,10],[2,0,5]]
//Output: 2
//Explanation:
//Person #0 gave person #1 $10.
//Person #2 gave person #0 $5.
//Two transactions are needed. One way to settle the debt is person #1 pays
//person #0 and #2 $5 each.
//
//Example 2:
//Input: transactions = [[0,1,10],[1,0,1],[1,2,5],[2,0,5]]
//Output: 1
//Explanation:
//Person #0 gave person #1 $10.
//Person #1 gave person #0 $1.
//Person #1 gave person #2 $5.
//Person #2 gave person #0 $5.
//Therefore, person #1 only need to give person #0 $4, and all debt is settled.
// 
//Constraints:
//1 <= transactions.length <= 8
//transactions[i].length == 3
//0 <= fromi, toi < 12
//fromi != toi
//1 <= amounti <= 100

namespace Solution2022
{
	namespace OptimalAccountBalancing
	{
		int dfs(int start, int len, vector<int>& debts) {
			if (start == len) { return 0; }

			int cur = debts[start];
			if (cur == 0) { return dfs(start +1, len, debts); }

			int result = INT_MAX;
			for (int i = start + 1; i < len; i++) {
				int tmp = debts[i];
				if (tmp * cur < 0) {
					debts[i] += cur;
					result = min(result, 1 + dfs(start + 1, len, debts));
					debts[i] = tmp;
				}
				if (tmp + cur == 0) { break; }
			}
			return result;
		}


	    int minTransfers(vector<vector<int>>& transactions) {
			int len = transactions.size();
			if (len < 2) { return len; }

			unordered_map<int, int> map;
			for (vector<int>& t : transactions) {
				map[t[0]] -= t[2];
				map[t[1]] += t[2];
			}

			vector<int> list;
			for (auto& p : map) {
				if (p.second != 0) { list.push_back(p.second); }
			}
			return dfs(0, list.size(), list); // note that the second param is list.size, not transactions.size()!!!
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
