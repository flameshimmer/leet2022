#include "stdafx.h"

//Given a m * n matrix of ones and zeros, return how many square submatrices have
//all ones.
// 
//
//Example 1:
//Input: matrix =
//[
//  [0,1,1,1],
//  [1,1,1,1],
//  [0,1,1,1]
//]
//Output: 15
//Explanation: 
//There are 10 squares of side 1.
//There are 4 squares of side 2.
//There is  1 square of side 3.
//Total number of squares = 10 + 4 + 1 = 15.
//
//Example 2:
//Input: matrix = 
//[
//  [1,0,1],
//  [1,1,0],
//  [1,1,0]
//]
//Output: 7
//Explanation: 
//There are 6 squares of side 1.  
//There is 1 square of side 2. 
//Total number of squares = 6 + 1 = 7.
// 
//Constraints:
//1 <= arr.length <= 300
//1 <= arr[0].length <= 300
//0 <= arr[i][j] <= 1

namespace Solution2022
{
	namespace CountSquareSubmatriceswithAllOnes
	{
		//https://www.youtube.com/watch?v=GfGsM2G1tP8
	    int countSquares(vector<vector<int>>& M) {
			int rowCount = M.size();
			int colCount = M[0].size();
			
			int result = 0;

			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					if (M[i][j] > 0 && i - 1 >= 0 && j - 1 >= 0) {
						M[i][j] = min(M[i - 1][j], min(M[i][j - 1], M[i - 1][j - 1])) + 1;						
					}
					result += M[i][j]; // Note that this addition should not be included in the above if statment!!
				}
			}
			return result;			
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
