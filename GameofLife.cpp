#include "stdafx.h"

//According to Wikipedia's article: "The Game of Life, also known simply as Life,
//is a cellular automaton devised by the British mathematician John Horton Conway
//in 1970."
//The board is made up of an m x n grid of cells, where each cell has an initial
//state: live (represented by a 1) or dead (represented by a 0). Each cell
//interacts with its eight neighbors (horizontal, vertical, diagonal) using the
//following four rules (taken from the above Wikipedia article):
//Any live cell with fewer than two live neighbors dies as if caused by
//under-population.
//Any live cell with two or three live neighbors lives on to the next generation.
//Any live cell with more than three live neighbors dies, as if by
//over-population.
//Any dead cell with exactly three live neighbors becomes a live cell, as if by
//reproduction.
//The next state is created by applying the above rules simultaneously to every
//cell in the current state, where births and deaths occur simultaneously. Given
//the current state of the m x n grid board, return the next state.
// 
//
//Example 1:
//Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
//Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
//
//Example 2:
//Input: board = [[1,1],[1,0]]
//Output: [[1,1],[1,1]]
// 
//Constraints:
//m == board.length
//n == board[i].length
//1 <= m, n <= 25
//board[i][j] is 0 or 1.
// 
//Follow up:
//Could you solve it in-place? Remember that the board needs to be updated
//simultaneously: You cannot update some cells first and then use their updated
//values to update other cells.
//
//In this question, we represent the board using a 2D array. In principle, the
//board is infinite, which would cause problems when the active area encroaches
//upon the border of the array (i.e., live cells reach the border). How would you
//address these problems?

namespace Solution2022
{
	namespace GameofLife
	{
		namespace InfiniteBoard {
		//Essentially, we obtain only the live cells from the entire boardand then apply the
		//different rules using only the live cellsand finally we update the board in - place.
		//The only problem with this solution would be when the entire board cannot fit into
		//memory.If that is indeed the case, then we would have to approach this problem in a
		//different way.For that scenario, we assume that the contents of the matrix are stored
		//in a file, one row at a time.

		//In order for us to update a particular cell, we only have to look at its 8 neighbors
		//which essentially lie in the row above and below it.So, for updating the cells of a row,
		//we just need the row aboveand the row below.Thus, we read one row at a time from the 
		//fileand at max we will have 3 rows in memory.We will keep discarding rows that are
		//processed and then we will keep reading new rows from the file, one at a time.		
		}

		namespace InPlace {

			int helper(vector<vector<int>>& board, int x, int y, int rowCount, int colCount) {
				if ((x < rowCount && x >= 0) && (y < colCount && y >= 0) && (abs(board[x][y]) == 1)) { // note that this is both 1 and -1!
					return 1;
				}
				return 0;
			}

			int getSum(vector<vector<int>>& board, int x, int y, int rowCount, int colCount) {
				return helper(board, x, y - 1, rowCount, colCount) +
					helper(board, x, y + 1, rowCount, colCount) +
					helper(board, x - 1, y - 1, rowCount, colCount) +
					helper(board, x - 1, y, rowCount, colCount) +
					helper(board, x - 1, y + 1, rowCount, colCount) +
					helper(board, x + 1, y - 1, rowCount, colCount) +
					helper(board, x + 1, y, rowCount, colCount) +
					helper(board, x + 1, y + 1, rowCount, colCount);
			}

			void gameOfLife(vector<vector<int>>& board) {
				int rowCount = board.size();
				if (rowCount == 0) { return; }
				int colCount = board[0].size();
				if (colCount == 0) { return; }
				
				for (int i = 0; i < rowCount; i++) {
					for (int j = 0; j < colCount; j++) {
						int liveNeighbour = getSum(board, i, j, rowCount, colCount);
						if (board[i][j] == 1 && (liveNeighbour < 2 || liveNeighbour > 3)) { board[i][j] = -1; }
						else if (board[i][j] == 0 && liveNeighbour == 3) { board[i][j] = 2; }
					}				
				}

				for (int i = 0; i < rowCount; i++) {
					for (int j = 0; j < colCount; j++) {
						if (board[i][j] > 0) { board[i][j] = 1; }
						else { board[i][j] = 0; }
					}
				}
			}
		}


		namespace CopyBoard {
			int helper(vector<vector<int>>& board, int x, int y, int rowCount, int colCount) {
				if (x < 0 || x >= rowCount || y < 0 || y >= colCount) { return 0; }
				return board[x][y] == 1;
			}

			int getSum(vector<vector<int>>& board, int x, int y, int rowCount, int colCount) {
				return helper(board, x, y - 1, rowCount, colCount) +
					helper(board, x, y + 1, rowCount, colCount) +
					helper(board, x - 1, y - 1, rowCount, colCount) +
					helper(board, x - 1, y, rowCount, colCount) +
					helper(board, x - 1, y + 1, rowCount, colCount) +
					helper(board, x + 1, y - 1, rowCount, colCount) +
					helper(board, x + 1, y, rowCount, colCount) +
					helper(board, x + 1, y + 1, rowCount, colCount);
			}

			void gameOfLife(vector<vector<int>>& board) {
				int rowCount = board.size();
				if (rowCount == 0) { return; }
				int colCount = board[0].size();
				if (colCount == 0) { return; }

				vector<vector<int>> sum(rowCount, vector<int>(colCount, 0));
				for (int i = 0; i < rowCount; i++) {
					for (int j = 0; j < colCount; j++) {
						sum[i][j] = getSum(board, i, j, rowCount, colCount);
					}
				}

				for (int i = 0; i < rowCount; i++) {
					for (int j = 0; j < colCount; j++) {
						if (board[i][j] == 1 && (sum[i][j] < 2 || sum[i][j] > 3)) {
							board[i][j] = 0;
						}
						else if (board[i][j] == 0 && sum[i][j] == 3) {
							board[i][j] = 1;
						}
					}
				}
				return;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
