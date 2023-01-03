#include "stdafx.h"

//Given a rectangular pizza represented as a rows x cols matrix containing the
//following characters: 'A' (an apple) and '.' (empty cell) and given the integer
//k. You have to cut the pizza into k pieces using k-1 cuts. 
//For each cut you choose the direction: vertical or horizontal, then you choose
//a cut position at the cell boundary and cut the pizza into two pieces. If you
//cut the pizza vertically, give the left part of the pizza to a person. If you
//cut the pizza horizontally, give the upper part of the pizza to a person. Give
//the last piece of pizza to the last person.
//Return the number of ways of cutting the pizza such that each piece contains at
//least one apple. Since the answer can be a huge number, return this modulo 10^9
//+ 7.
// 
//
//Example 1:
//Input: pizza = ["A..","AAA","..."], k = 3
//Output: 3 
//Explanation: The figure above shows the three ways to cut the pizza. 
//Note that
//pieces must contain at least one apple.
//
//Example 2:
//Input: pizza = ["A..","AA.","..."], k = 3
//Output: 1
//
//Example 3:
//Input: pizza = ["A..","A..","..."], k = 1
//Output: 1
// 
//Constraints:
//1 <= rows, cols <= 50
//rows == pizza.length
//cols == pizza[i].length
//1 <= k <= 10
//pizza consists of characters 'A' and '.' only.

namespace Solution2022
{
	namespace NumberofWaysofCuttingaPizza
	{

		int ways(vector<string>& pizza, int k) {
			int kMod = 1e9 + 7;
			int rowCount = pizza.size();
			int colCount = pizza[0].size();

			vector<vector<int>> A(rowCount + 1, vector<int>(colCount + 1));
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					A[i + 1][j + 1] = A[i][j + 1] + A[i + 1][j] + (pizza[i][j] == 'A') - A[i][j];
				}
			}

			auto hasApple = [&](int x1, int y1, int x2, int y2) {
				return A[y2 + 1][x2 + 1] - A[y2 + 1][x1] - A[y1][x2 + 1] + A[y1][x1] > 0;
			};
			
			
			vector<vector<vector<int>>> M(rowCount, vector<vector<int>>(colCount, vector<int>(k, -1)));

			function<int(int, int, int)> helper = [&](int row, int col, int k) -> int {
				if (k == 0) { return hasApple(col, row, colCount - 1, rowCount - 1); }
				if (M[row][col][k] != -1) { return M[row][col][k]; }

				int result = 0;
				for (int i = row; i < rowCount - 1; i++) {
					result = (result + hasApple(col, row, colCount -1, i) * helper(i+1, col, k-1)) % kMod;
				}

				for (int j = col; j < colCount - 1; j++) {
					result = (result + hasApple(col, row, j, rowCount - 1) * helper(row, j + 1, k-1)) % kMod;
				}
				M[row][col][k] = result;
				return result;
			};
			return M[0][0][k - 1];
		}


		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
