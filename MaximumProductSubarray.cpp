#include "stdafx.h"

//Given an integer array nums, find a contiguous non-empty subarray within the
//array that has the largest product, and return the product.
//The test cases are generated so that the answer will fit in a 32-bit integer.
//A subarray is a contiguous subsequence of the array.
// 
//
//Example 1:
//Input: nums = [2,3,-2,4]
//Output: 6
//Explanation: [2,3] has the largest product 6.
//
//Example 2:
//Input: nums = [-2,0,-1]
//Output: 0
//Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
// 
//Constraints:
//1 <= nums.length <= 2 * 104
//-10 <= nums[i] <= 10
//The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
//integer.

namespace Solution2022
{
	namespace MaximumProductSubarray
	{
	    int maxProduct(vector<int>& nums) {
			int result = nums[0];
			int maxR = nums[0];
			int minR = nums[0];
			
			for (int i = 1; i < nums.size(); i++) {
				if (nums[i] < 0) { swap(maxR, minR); }

				maxR = max(maxR * nums[i], nums[i]);
				minR = min(maxR * nums[i], nums[i]);
				result = max(result, maxR);
			}
			return result;
	    }

		namespace Another {
			int maxProduct(vector<int>& nums) {
				int len = nums.size();
				if (len == 0) { return 0; }

				int frontProduct = 1;
				int backProduct = 1;
				int result = INT_MIN;
				for (int i = 0; i < len; i++) {
					frontProduct *= nums[i];
					backProduct *= nums[len - 1 - i];
					result = max(result, max(frontProduct, backProduct));
					if (frontProduct == 0) { frontProduct = 1; }
					if (backProduct == 0) { backProduct = 1; }
				}
				return result;
			}		
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
