#include "stdafx.h"

//You are given an m x n matrix board, representing the current state of a
//crossword puzzle. The crossword contains lowercase English letters (from solved
//words), ' ' to represent any empty cells, and '#' to represent any blocked
//cells.
//A word can be placed horizontally (left to right or right to left) or
//vertically (top to bottom or bottom to top) in the board if:
//It does not occupy a cell containing the character '#'.
//The cell each letter is placed in must either be ' ' (empty) or match the
//letter already on the board.
//There must not be any empty cells ' ' or other lowercase letters directly left
//or right of the word if the word was placed horizontally.
//There must not be any empty cells ' ' or other lowercase letters directly above
//or below the word if the word was placed vertically.
//Given a string word, return true if word can be placed in board, or false
//otherwise.
// 
//
//Example 1:
//Input: board = [["#", " ", "#"], [" ", " ", "#"], ["#", "c", " "]], word = "abc"
//Output: true
//Explanation: The word "abc" can be placed as shown above (top to bottom).
//
//Example 2:
//Input: board = [[" ", "#", "a"], [" ", "#", "c"], [" ", "#", "a"]], word = "ac"
//Output: false
//Explanation: It is impossible to place the word because there will always be a
//space/letter above or below it.
//
//Example 3:
//Input: board = [["#", " ", "#"], [" ", " ", "#"], ["#", " ", "c"]], word = "ca"
//Output: true
//Explanation: The word "ca" can be placed as shown above (right to left). 
// 
//Constraints:
//m == board.length
//n == board[i].length
//1 <= m * n <= 2 * 105
//board[i][j] will be ' ', '#', or a lowercase English letter.
//1 <= word.length <= max(m, n)
//word will contain only lowercase English letters.

namespace Solution2022
{
	namespace CheckifWordCanBePlacedInCrossword
	{
		bool isSeparator(vector<vector<char>>& board, int x, int y, int rowCount, int colCount) {
			if (x < 0 || y < 0 || x >= rowCount || y >= colCount) { return true; }
			return board[x][y] == '#';
		}

		bool check(vector<vector<char>>& board, string& word, int x, int y, int pos, bool isVertical, int inc, int rowCount, int colCount) {
			bool outOfBound = (x < 0 || y < 0 || x >= rowCount || y >= colCount);
			if (pos == word.size()) {
				return outOfBound || board[x][y] == '#';
			}

			if (outOfBound || (board[x][y] != ' ' && board[x][y] != word[pos])) { 
				return false;
			}

			int a = x + (isVertical * inc); // note that how next index is generated!!!
			int b = y + (!isVertical * inc);
			return check(board, word, a, b, pos + 1, isVertical, inc, rowCount, colCount);
		}


		bool placeWordInCrossword(vector<vector<char>>& board, string word) {
			int rowCount = board.size();
			int colCount = board[0].size();

			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					if (board[i][j] != '#') {
						if (isSeparator(board, i - 1, j, rowCount, colCount) && check(board, word, i, j, 0, true, 1, rowCount, colCount)) {
							return true;
						}
						if (isSeparator(board, i + 1, j, rowCount, colCount) && check(board, word, i, j, 0, true, -1, rowCount, colCount)) {
							return true;
						}
						if (isSeparator(board, i, j - 1, rowCount, colCount) && check(board, word, i, j, 0, false, 1, rowCount, colCount)) {
							return true;
						}
						if (isSeparator(board, i, j + 1, rowCount, colCount) && check(board, word, i, j, 0, false, -1, rowCount, colCount)) {
							return true;
						}
					}
				}
			}
			return false;
		}

		void Main() {
			vector<vector<char>> test = { {'#',' ','#'},{' ',' ','#'},{'#','c',' '} };
			print(placeWordInCrossword(test, "abc"));
		}
	}
}
