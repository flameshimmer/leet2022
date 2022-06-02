#include "stdafx.h"
//Given an integer array nums sorted in non - decreasing order, return an array 
//of the squares of each number sorted in non - decreasing order.
//
//Example 1:
//
//Input: nums = [-4, -1, 0, 3, 10]
//	Output : [0, 1, 9, 16, 100]
//	Explanation : After squaring, the array becomes[16, 1, 0, 9, 100].
//	After sorting, it becomes[0, 1, 9, 16, 100].
//	Example 2 :
//
//	Input : nums = [-7, -3, 2, 3, 11]
//	Output : [4, 9, 9, 49, 121]
//
//
//	Constraints :
//
//	1 <= nums.length <= 104
//	- 104 <= nums[i] <= 104
//	nums is sorted in non - decreasing order.
//
//
//	Follow up : Squaring each element and sorting the new array is very trivial, 
//	could you find an O(n) solution using a different approach ?
namespace Solution2022
{
	namespace SquaresofaSortedArray
	{
		vector<int> sortedSquares(vector<int>& nums) {
			int len = nums.size();

			int start = 0;
			int end = len - 1;
			int i = len - 1;
			vector<int> result(len);

			while (start <= end) {
				if (abs(nums[start]) > abs(nums[end])) {
					result[i] = nums[start] * nums[start];
					start++;
				}
				else {
					result[i] = nums[end] * nums[end];
					end--;
				}
				i--;
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			vector<int> input = { -7, -3, 2, 3, 11 };
			print(sortedSquares(input));
		}
	}
}
