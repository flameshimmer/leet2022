#include "stdafx.h"

//Let's play the minesweeper game (Wikipedia, online game)!
//You are given an m x n char matrix board representing the game board where:
//'M' represents an unrevealed mine,
//'E' represents an unrevealed empty square,
//'B' represents a revealed blank square that has no adjacent mines (i.e., above,
//below, left, right, and all 4 diagonals),
//digit ('1' to '8') represents how many mines are adjacent to this revealed
//square, and
//'X' represents a revealed mine.
//You are also given an integer array click where click = [clickr, clickc]
//represents the next click position among all the unrevealed squares ('M' or
//'E').
//Return the board after revealing this position according to the following rules:
//If a mine 'M' is revealed, then the game is over. You should change it to 'X'.
//If an empty square 'E' with no adjacent mines is revealed, then change it to a
//revealed blank 'B' and all of its adjacent unrevealed squares should be
//revealed recursively.
//If an empty square 'E' with at least one adjacent mine is revealed, then change
//it to a digit ('1' to '8') representing the number of adjacent mines.
//Return the board when no more squares will be revealed.
// 
//
//Example 1:
//[["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]],
//click = [3,0]
//[["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
//
//Example 2:
//[["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]],
//click = [1,2]
//[["B","1","E","1","B"],["B","1","X","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
// 
//Constraints:
//m == board.length
//n == board[i].length
//1 <= m, n <= 50
//board[i][j] is either 'M', 'E', 'B', or a digit from '1' to '8'.
//click.length == 2
//0 <= clickr < m
//0 <= clickc < n
//board[clickr][clickc] is either 'M' or 'E'.

namespace Solution2022
{
	namespace Minesweeper
	{
		vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
			int rowCount = board.size();
			if (rowCount == 0) { return board; }
			int colCount = board[0].size();
			if (colCount == 0) { return board; }

			int x = click[0];
			int y = click[1];

			if (board[x][y] == 'M') { board[x][y] = 'X'; return board; }
			if (isdigit(board[x][y]) || board[x][y] == 'B') { return board; }

			vector<pair<int, int>> dirs = { {-1, -1}, {-1, 0},{-1, 1},{0, -1},{0, 1},{1, -1},{1, 0},{1, 1} };
			int adjCount = 0;
			for (auto [xx, yy] : dirs) {
				int a = x + xx;
				int b = y + yy;
				if (a < 0 || a >= rowCount || b < 0 || b >= colCount) { continue; }
				if (board[a][b] == 'M') { adjCount++; }
			}
			if (adjCount > 0) { board[x][y] = '0' + adjCount; return board; }
			board[x][y] = 'B';
			for (auto [xx, yy] : dirs) {
				int a = x + xx;
				int b = y + yy;
				if (a < 0 || a >= rowCount || b < 0 || b >= colCount) { continue; }
				vector<int> newClick = { a, b };
				updateBoard(board, newClick);
			}
			return board;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
