#include "stdafx.h"

//The n-queens puzzle is the problem of placing n queens on an n x n chessboard
//such that no two queens attack each other.
//Given an integer n, return all distinct solutions to the n-queens puzzle. You
//may return the answer in any order.
//Each solution contains a distinct board configuration of the n-queens'
//placement, where 'Q' and '.' both indicate a queen and an empty space,
//respectively.
// 
//
//Example 1:
//Input: n = 4
//Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//Explanation: There exist two distinct solutions to the 4-queens puzzle as shown
//above
//
//Example 2:
//Input: n = 1
//Output: [["Q"]]
// 
//Constraints:
//1 <= n <= 9

namespace Solution2022
{
	namespace NQueens
	{
		bool isValid(int i, int colMask, int diagMask, int aDiagMask) {
			int mask = colMask | diagMask | aDiagMask;
			return ((1 << i) & mask) == 0;
		}

		void helper(int level, int n, vector<string>& result, vector<vector<string>>& results, int colMask, int diagMask, int aDiagMask) {
			if (level == n) { results.push_back(result); return; }

			for (int i = 0; i < n; i++) {
				if (isValid(i, colMask, diagMask, aDiagMask)) {
					result[level][i] = 'Q';
					int mask = 1 << i;
					helper(level + 1, n, result, results, colMask | mask, (diagMask | mask) << 1, (aDiagMask | mask) >> 1);
					result[level][i] = '.';
				}				
			}
		}

	    vector<vector<string>> solveNQueens(int n) {
			vector<vector<string>> results;
			vector<string> result(n, string(n, '.'));
			helper(0, n, result, results, 0, 0, 0);
			return results;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
