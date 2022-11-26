#include "stdafx.h"

//Given an integer array nums of size n, return the minimum number of moves
//required to make all array elements equal.
//In one move, you can increment n - 1 elements of the array by 1.
// 
//
//Example 1:
//Input: nums = [1,2,3]
//Output: 3
//Explanation: Only three moves are needed (remember each move increments two
//elements):
//[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
//
//Example 2:
//Input: nums = [1,1,1]
//Output: 0
// 
//Constraints:
//n == nums.length
//1 <= nums.length <= 105
//-109 <= nums[i] <= 109
//The answer is guaranteed to fit in a 32-bit integer.

namespace Solution2022
{
	namespace MinimumMovestoEqualArrayElements
	{
		//We have to increment n-1 elements by 1 to make them equal. This is equal to
		//decrementing only 1 element by 1. Since we need to make all the elements equal
		//we can consider he given problem to be equal to decrementing all the elements
		//by 1 in each move until they are equal to the minimum element in the array.
		//For example- [5,6,7,8] can be made equal if we decrement number 8, three times
		//and 7, two times and 6 one times. Decrementing 8 by 1 is equal to adding 1 to
		//all the other elements.
		//Conclusion - We are just reversing the problem to make it simpler :)

	    int minMoves(vector<int>& nums) {
			int minV = *min_element(nums.begin(), nums.end());
			int result = 0;
			for (int v : nums) { result += v - minV; }
			return result;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
