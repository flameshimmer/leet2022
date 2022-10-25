#include "stdafx.h"

//You are given an integer array nums. In one move, you can pick an index i where
//0 <= i < nums.length and increment nums[i] by 1.
//Return the minimum number of moves to make every value in nums unique.
//The test cases are generated so that the answer fits in a 32-bit integer.
// 
//
//Example 1:
//Input: nums = [1,2,2]
//Output: 1
//Explanation: After 1 move, the array could be [1, 2, 3].
//
//Example 2:
//Input: nums = [3,2,1,2,1,7]
//Output: 6
//Explanation: After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
//It can be shown with 5 or less moves that it is impossible for the array to
//have all unique values.
// 
//Constraints:
//1 <= nums.length <= 105
//0 <= nums[i] <= 105

namespace Solution2022
{
	namespace MinimumIncrementtoMakeArrayUnique
	{
		//The idea is to sort the input -O(nlogn)- , then we move forward from the
		//beginning of the array till the end.
		//As soon as we found a condition that the current element is less than or equal
		//to the previous elements then we need to update the current array element.
		//here is an example of the given input.
		//A = [3,2,1,2,1,7]
		//Sorted A = [1,1,2,2,3,7]
		//After reaching the second 1 on the array since the condition is satisfied
		//A[i]<=A[i-1] so we need to update the A[i] by A[i-1]+1.
		//At the same time we need to keep track of result by
		//result += A[i-1]+ 1 - A[i];
		//The rest of iterations are as following :
		//A = [1,2,2,2,3,7]
		//res= 1
		//A = [1,2,3,2,3,7]
		//res= 2
		//A = [1,2,3,4,3,7]
		//res= 4
		//A = [1,2,3,4,5,7]
		//res= 6

		int minIncrementForUnique(vector<int>& A) {
			int len = A.size();
			if (len < 2) { return 0; }

			int result = 0;
			sort(A.begin(), A.end());
			for (int i = 1; i < len; i++) {
				if (A[i] <= A[i - 1]) {
					result += A[i - 1] + 1 - A[i];
					A[i] = A[i - 1] + 1;
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
