#include "stdafx.h"

//You are given an m x n binary matrix image where 0 represents a white pixel and
//1 represents a black pixel.
//The black pixels are connected (i.e., there is only one black region). Pixels
//are connected horizontally and vertically.
//Given two integers x and y that represents the location of one of the black
//pixels, return the area of the smallest (axis-aligned) rectangle that encloses
//all black pixels.
//You must write an algorithm with less than O(mn) runtime complexity
// 
//
//Example 1:
//Input: image = [["0","0","1","0"],["0","1","1","0"],["0","1","0","0"]], x = 0,
//y = 2
//Output: 6
//
//Example 2:
//Input: image = [["1"]], x = 0, y = 0
//Output: 1
// 
//Constraints:
//m == image.length
//n == image[i].length
//1 <= m, n <= 100
//image[i][j] is either '0' or '1'.
//0 <= x < m
//0 <= y < n
//image[x][y] == '1'.
//The black pixels in the image only form one component.

namespace Solution2022
{
	namespace SmallestRectangleEnclosingBlackPixels
	{
		int searchRows(int startRow, int endRow, int startCol, int endCol, bool opt, vector<vector<char>>& image) {
			while (startRow != endRow) {
				int midRow = startRow + (endRow - startRow) / 2;
				int col = startCol;
				while (col < endCol && image[midRow][col] == '0') { col++; }

				if ((col < endCol) == opt) {
					endRow = midRow;
				}
				else {
					startRow = midRow + 1;
				}
			}
			return startRow;
		}

		int searchColumns(int startCol, int endCol, int startRow, int endRow, bool opt, vector<vector<char>>& image) {
			while (startCol < endCol) {
				int midCol = startCol + (endCol - startCol) / 2;
				int row = startRow;
				while (row < endRow && image[row][midCol] == '0') { row++; }
				if ((row < endRow)) == opt) {
					endCol = midCol;
				}
				else {
					startCol = midCol + 1;
				}
			}
			return startCol;
		}


		//top = search row[0...x], find first row contain 1,
		//bottom = search row[x + 1, row], find first row contian all 0
		//left = search col[0...y], find first col contain 1,
		//right = search col[y + 1, col], find first col contain all 0
	    int minArea(vector<vector<char>>& image, int x, int y) {
			int rowCount = image.size();
			int colCount = image[0].size();

			int top = searchRows(0, x, 0, colCount, true, image);
			int bottom = searchRows(x+1, rowCount, 0, colCount, false, image);
			int left = searchColumns(0, y, top, bottom, true, image);
			int right = searchColumns(y+1, colCount, top, bottom, false, image);

			return (right - left) * (bottom - top);
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
