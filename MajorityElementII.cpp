#include "stdafx.h"

//Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
// 
//
//Example 1:
//Input: nums = [3,2,3]
//Output: [3]
//
//Example 2:
//Input: nums = [1]
//Output: [1]
//
//Example 3:
//Input: nums = [1,2]
//Output: [1,2]
// 
//Constraints:
//1 <= nums.length <= 5 * 104
//-109 <= nums[i] <= 109
// 
//Follow up: Could you solve the problem in linear time and in O(1) space?

namespace Solution2022
{
	namespace MajorityElementII
	{
		vector<int> majorityElement(vector<int>& nums) {
			vector<int> result;
			int len = nums.size();
			if (len == 0) { return result; }

			int n1 = nums[0];
			int n2 = nums[0];
			int c1 = 0;
			int c2 = 0;
			for (int v : nums) {
				if (v == n1) { c1++; }
				else if (v == n2) { c2++; }
				else if (c1 == 0) { n1 = v; c1++; }
				else if (c2 == 0) { n2 = v; c2++; }
				else { c1--; c2--; }
			}

			// If don't do the recheck, we can only know those are top 2 frequent element 
			// in the array, but we can't guarantee their counts are more than 1/3.
			// Eg: 3,2,3
			c1 = 0;
			c2 = 0;
			for (int v : nums) {
				if (v == n1) { c1++; }
				else if (v == n2) { c2++; }
			}

			if (c1 > len / 3) { result.push_back(n1); }
			if (c2 > len / 3) { result.push_back(n2); }
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
