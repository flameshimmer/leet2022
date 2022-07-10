#include "stdafx.h"

//Given an integer rowIndex, return the rowIndexth (0-indexed) row of the
//Pascal's triangle.
//In Pascal's triangle, each number is the sum of the two numbers directly above
//it as shown:
// 
//
//Example 1:
//Input: rowIndex = 3
//Output: [1,3,3,1]
//
//Example 2:
//Input: rowIndex = 0
//Output: [1]
//
//Example 3:
//Input: rowIndex = 1
//Output: [1,1]
// 
//Constraints:
//0 <= rowIndex <= 33
// 
//Follow up: Could you optimize your algorithm to use only O(rowIndex) extra
//space?

namespace Solution2022
{
	namespace PascalsTriangleII
	{
	    vector<int> getRow(int rowIndex) {
			vector<int> result(rowIndex + 1, 1); // init to 1 instead of 0
			
			for (int i = 2; i <= rowIndex; i++) { // we rowIndex row in total
				for (int j = i - 1; j >= 1; j--) { // for every row max Index is i, we skip the first and last
					result[j] += result[j - 1];
				}
			}
			return result;
	    }

		void Main() {
			print(getRow(3));
		}
	}
}
