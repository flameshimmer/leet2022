#include "stdafx.h"

//Given an m x n grid of characters board and a string word, return true if word
//exists in the grid.
//The word can be constructed from letters of sequentially adjacent cells, where
//adjacent cells are horizontally or vertically neighboring. The same letter cell
//may not be used more than once.
// 
//
//Example 1:
//Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
//"ABCCED"
//Output: true
//
//Example 2:
//Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
//"SEE"
//Output: true
//
//Example 3:
//Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
//"ABCB"
//Output: false
// 
//Constraints:
//m == board.length
//n = board[i].length
//1 <= m, n <= 6
//1 <= word.length <= 15
//board and word consists of only lowercase and uppercase English letters.
// 
//Follow up: Could you use search pruning to make your solution faster with a
//larger board?

namespace Solution2022
{
	namespace WordSearch
	{
		bool helper(vector<vector<char>>& board, int rowCount, int colCount, int x, int y, string& word, int i, int len, vector<vector<bool>>& used) {
			if (i == len) { return true; }
			if (x < 0 || x >= rowCount || y < 0 || y >= colCount || used[x][y] || word[i] != board[x][y]) { return false; }
			used[x][y] = true;
			vector<pair<int, int>> dirs = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
			for (auto& [a, b] : dirs) {
				if (helper(board, rowCount, colCount, x + a, y + b, word, i + 1, len, used)) { return true; }
			}
			used[x][y] = false;
			return false;
		}

		bool exist(vector<vector<char>>& board, string word) {
			int rowCount = board.size();
			if (rowCount == 0) { return false; }
			int colCount = board[0].size();
			if (colCount == 0) { return false; }

			int len = word.size();
			vector<vector<bool>>used(rowCount, vector<bool>(colCount, false));

			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					if (helper(board, rowCount, colCount, i, j, word, 0, len, used)) { return true; }
				}
			}
			return false;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
