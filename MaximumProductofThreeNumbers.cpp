#include "stdafx.h"

//Given an integer array nums, find three numbers whose product is maximum and
//return the maximum product.
// 
//
//Example 1:
//Input: nums = [1,2,3]
//Output: 6
//
//Example 2:
//Input: nums = [1,2,3,4]
//Output: 24
//
//Example 3:
//Input: nums = [-1,-2,-3]
//Output: -6
// 
//Constraints:
//3 <= nums.length <= 104
//-1000 <= nums[i] <= 1000

namespace Solution2022
{
	namespace MaximumProductofThreeNumbers
	{
		int maximumProduct(vector<int>& nums) {
			int max1 = INT_MIN;
			int max2 = INT_MIN;
			int max3 = INT_MIN;

			int min1 = INT_MAX;
			int min2 = INT_MAX;

			for (int v : nums) {
				if (v >= max1) {
					max3 = max2;
					max2 = max1;
					max1 = v;
				}
				else if (v >= max2) {
					max3 = max2;
					max2 = v;
				}
				else if (v >= max3) {
					max3 = v;
				}

				if (v <= min1) {
					min2 = min1;
					min1 = v;
				}
				else if (v <= min2) {
					min2 = v;
				}
			}
			return max(max1 * max2 * max3, min1 * min2 * max1);
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
