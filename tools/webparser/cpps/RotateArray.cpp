#include "stdafx.h"

//Given an array, rotate the array to the right by k steps, where k is
//non-negative.
// 
//
//Example 1:
//Input: nums = [1,2,3,4,5,6,7], k = 3
//Output: [5,6,7,1,2,3,4]
//Explanation:
//rotate 1 steps to the right: [7,1,2,3,4,5,6]
//rotate 2 steps to the right: [6,7,1,2,3,4,5]
//rotate 3 steps to the right: [5,6,7,1,2,3,4]
//
//Example 2:
//Input: nums = [-1,-100,3,99], k = 2
//Output: [3,99,-1,-100]
//Explanation: 
//rotate 1 steps to the right: [99,-1,-100,3]
//rotate 2 steps to the right: [3,99,-1,-100]
// 
//Constraints:
//1 <= nums.length <= 105
//-231 <= nums[i] <= 231 - 1
//0 <= k <= 105
// 
//Follow up:
//Try to come up with as many solutions as you can. There are at least three
//different ways to solve this problem.
//Could you do it in-place with O(1) extra space?

namespace Solution2022
{
	namespace RotateArray
	{
	        void reverseArray(vector<int>& a, int start, int end) {
	            while (start < end) {
	                int temp = a[start];
	                a[start] = a[end];
	                a[end] = temp;
	                start++;
	                end--;
	            }           
	        }
	​
	        void rotate(vector<int>& nums, int k) {
	            int len = nums.size();
	            if (len == 0 || k == 0) { return; }
	​
	            int t = len - k%len;
	            reverseArray(nums, 0, t - 1);
	            reverseArray(nums, t, len - 1);
	            reverseArray(nums, 0, len - 1);
	        }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
