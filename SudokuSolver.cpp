#include "stdafx.h"

//Write a program to solve a Sudoku puzzle by filling the empty cells.
//A sudoku solution must satisfy all of the following rules:
//Each of the digits 1-9 must occur exactly once in each row.
//Each of the digits 1-9 must occur exactly once in each column.
//Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes
//of the grid.
//The '.' character indicates empty cells.
// 
//
//Example 1:
//[
//["5","3",".",".","7",".",".",".","."],
//["6",".",".","1","9","5",".",".","."],
//[".","9","8",".",".",".",".","6","."],
//["8",".",".",".","6",".",".",".","3"],
//["4",".",".","8",".","3",".",".","1"],
//["7",".",".",".","2",".",".",".","6"],
//[".","6",".",".",".",".","2","8","."],
//[".",".",".","4","1","9",".",".","5"],
//[".",".",".",".","8",".",".","7","9"]
//]
//[
//["5","3","4","6","7","8","9","1","2"],
//["6","7","2","1","9","5","3","4","8"],
//["1","9","8","3","4","2","5","6","7"],
//["8","5","9","7","6","1","4","2","3"],
//["4","2","6","8","5","3","7","9","1"],
//["7","1","3","9","2","4","8","5","6"],
//["9","6","1","5","3","7","2","8","4"],
//["2","8","7","4","1","9","6","3","5"],
//["3","4","5","2","8","6","1","7","9"]
//]
//Explanation: The input board is shown above and the only valid solution is
//shown below:
// 
//Constraints:
//board.length == 9
//board[i].length == 9
//board[i][j] is a digit or '.'.
//It is guaranteed that the input board has only one solution.

namespace Solution2022
{
	namespace SudokuSolver
	{
		bool helper(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& row, vector<vector<bool>>& col, vector<vector<vector<bool>>>& grid) {
			if (i >= 9) { return true; }
			int nextRow = i + (j + 1) / 9;
			int nextCol = (j + 1) % 9;
			if (board[i][j] != '.') { return helper(board, nextRow, nextCol, row, col, grid); }

			for (int v = 1; v <= 9; v++) {
				if (row[i][v] || col[j][v] || grid[i / 3][j / 3][v]) { continue; }
				board[i][j] = '0' + v;
				row[i][v] = true;
				col[j][v] = true;
				grid[i / 3][j / 3][v] = true;
				if (helper(board, nextRow, nextCol, row, col, grid)) { return true; }
				board[i][j] = '.';
				row[i][v] = false;
				col[j][v] = false;
				grid[i / 3][j / 3][v] = false;
			}
			return false;
		}

		void solveSudoku(vector<vector<char>>& board) {
			vector<vector<bool>> row(9, vector<bool>(10, false));
			vector<vector<bool>> col(9, vector<bool>(10, false));
			vector<vector<vector<bool>>> grid(3, vector<vector<bool>>(3, vector<bool>(10, false)));

			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (board[i][j] == '.') { continue; }
					int v = board[i][j] - '0';
					row[i][v] = true;
					col[j][v] = true;
					grid[i / 3][j / 3][v] = true;
				}
			}
			helper(board, 0, 0, row, col, grid);
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
