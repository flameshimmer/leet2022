#include "stdafx.h"

//Given an integer array nums, return the number of reverse pairs in the array.
//A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2
//* nums[j].
// 
//
//Example 1:
//Input: nums = [1,3,2,3,1]
//Output: 2
//
//Example 2:
//Input: nums = [2,4,3,5,1]
//Output: 3
// 
//Constraints:
//1 <= nums.length <= 5 * 104
//-231 <= nums[i] <= 231 - 1

namespace Solution2022
{
	namespace ReversePairs
	{
		void merge(vector<int>& A, int start, int mid, int end, int& count) {
			int i = start;
			int j = mid + 1;
			while (i <= mid && j <= end) {
				if ((long long)A[i] > (long long)2 * A[j]) {
					count += mid - i + 1;
					j++;
				}
				else {
					i++;
				}
			}
			sort(A.begin() + start, A.begin() + end + 1);
		}

		void mergeSort(vector<int>& nums, int start, int end, int& count) {
			if (start >= end) { return; }
			int mid = start + (end - start) / 2;
			mergeSort(nums, start, mid, count);
			mergeSort(nums, mid + 1, end, count);
			merge(nums, start, mid, end, count);
		}

		int reversePairs(vector<int>& nums) {
			int len = nums.size();
			int count = 0;
			mergeSort(nums, 0, len - 1, count);
			return count;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
