#include "stdafx.h"

//Given an integer array nums and an integer k, return the kth largest element in
//the array.
//
//Note that it is the kth largest element in the sorted order, not the kth
//distinct element.
// 
//
//Example 1:
//Input: nums = [3,2,1,5,6,4], k = 2
//Output: 5
//
//Example 2:
//Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
//Output: 4
// 
//Constraints:
//1 <= k <= nums.length <= 104
//-104 <= nums[i] <= 104

namespace Solution2022
{
	namespace KthLargestElementinanArray
	{
		
		int partition(vector<int>& nums, int start, int end, int partitionLen) {
			int pV = nums[start + partitionLen];
			swap(nums[start + partitionLen], nums[end]);

			int copy = start;
			for (int i = start; i <= end; i++) {
				if (nums[i] < pV) {
					swap(nums[i], nums[copy]);
					copy++;
				}
			}
			swap(nums[copy], nums[end]);

			if (copy - start == partitionLen) { return nums[copy]; }
			else if (copy - start < partitionLen) {
				return partition(nums, copy + 1, end, partitionLen - (copy + 1 - start));
			}
			else {
				return partition(nums, start, copy - 1, partitionLen);
			}
		}


	    int findKthLargest(vector<int>& nums, int k) {
			int len = nums.size();
			if (len < k) { return -1; }
			return partition(nums, 0, len - 1, len - k);
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
