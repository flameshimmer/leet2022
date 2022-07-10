#include "stdafx.h"

//Given an integer numRows, return the first numRows of Pascal's triangle.
//In Pascal's triangle, each number is the sum of the two numbers directly above
//it as shown:
// 
//
//Example 1:
//Input: numRows = 5
//Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
//
//Example 2:
//Input: numRows = 1
//Output: [[1]]
// 
//Constraints:
//1 <= numRows <= 30

namespace Solution2022
{
	namespace PascalsTriangle
	{
	    vector<vector<int>> generate(int numRows) {
			vector<vector<int>> results;
			if (numRows == 0) { return results; }

			results.push_back({1});

			for (int i = 2; i <= numRows; i++) {
				vector<int> newRow(results.back().begin(), results.back().end());
				for (int j = 1; j < newRow.size(); j++) {
					newRow[j] += results.back()[j - 1];
				}
				newRow.push_back(1);
				results.push_back(newRow);
			}
			return results;
	    }

		void Main() {
			generate(5);
		}
	}
}
