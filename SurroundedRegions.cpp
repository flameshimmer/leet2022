#include "stdafx.h"

//Given an m x n matrix board containing 'X' and 'O', capture all regions that
//are 4-directionally surrounded by 'X'.
//A region is captured by flipping all 'O's into 'X's in that surrounded region.
// 
//
//Example 1:
//Input: board =
//[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
//Output:
//[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
//Explanation: Surrounded regions should not be on the border, which means that
//any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not
//on the border and it is not connected to an 'O' on the border will be flipped
//to 'X'. Two cells are connected if they are adjacent cells connected
//horizontally or vertically.
//
//Example 2:
//Input: board = [["X"]]
//Output: [["X"]]
// 
//Constraints:
//m == board.length
//n == board[i].length
//1 <= m, n <= 200
//board[i][j] is 'X' or 'O'.

namespace Solution2022
{
	namespace SurroundedRegions
	{
		void helper(int row, int col, vector<vector<char>>& board, int rowCount, int colCount) {
			if (row < 0 || row >= rowCount || col < 0 || col >= colCount || board[row][col] != 'O') { return; }
			board[row][col] = '1';

			helper(row - 1, col, board, rowCount, colCount);
			helper(row + 1, col, board, rowCount, colCount);
			helper(row, col - 1, board, rowCount, colCount);
			helper(row, col + 1, board, rowCount, colCount);
		}

		void solve(vector<vector<char>>& board) {
			int rowCount = board.size();
			int colCount = board[0].size();

			for (int col = 0; col < colCount; col++) {
				if (board[0][col] == 'O') {
					helper(0, col, board, rowCount, colCount);
				}
				if (rowCount > 1) {
					if (board[rowCount - 1][col] == 'O') {
						helper(rowCount - 1, col, board, rowCount, colCount);
					}
				}
			}

			for (int row = 0; row < rowCount; row++) {
				if (board[row][0] == 'O') {
					helper(row, 0, board, rowCount, colCount);
				}
				if (colCount > 1) {
					if (board[row][colCount - 1] == 'O') {
						helper(row, colCount - 1, board, rowCount, colCount);
					}
				}
			}

			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					if (board[i][j] == 'O') { board[i][j] = 'X'; }
					else if (board[i][j] == '1') { board[i][j] = 'O'; }
				}
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
