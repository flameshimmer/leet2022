#include "stdafx.h"

//You may recall that an array arr is a mountain array if and only if:
//arr.length >= 3
//There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
//arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
//arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
//Given an integer array nums​​​, return the minimum number of elements to remove
//to make nums​​​ a mountain array.
// 
//
//Example 1:
//Input: nums = [1,3,1]
//Output: 0
//Explanation: The array itself is a mountain array so we do not need to remove
//any elements.
//
//Example 2:
//Input: nums = [2,1,1,5,6,2,3,1]
//Output: 3
//Explanation: One solution is to remove the elements at indices 0, 1, and 5,
//making the array nums = [1,5,6,3,1].
// 
//Constraints:
//3 <= nums.length <= 1000
//1 <= nums[i] <= 109
//It is guaranteed that you can make a mountain array out of nums.

namespace Solution2022
{
	namespace MinimumNumberofRemovalstoMakeMountainArray
	{
		//Intuition
		//Assume we pick A[i] as the peak of the mountain, then we are looking for the
		//longest increasing subsequence to the left of A[i], and the longest decreasing
		//subsequence to the right of A[i].
		//We can reuse the O(NlogN) time binary search solution to 300. Longest
		//Increasing Subsequence (Medium).
		//For the binary search solution to problem 300, please checkout my explanation.

		//Algorithm
		//Let a[i] be the length of the longest increasing subsequence in A[0..(i-1)]
		//that can has A[i] appended to it, and b[i] be the length of the longest
		//decreasing subsequence in A[(i+1)..(N-1)] that can has A[i] prepended to it.
		//We can scan from left to right to set the a[i] values, and scan from right to
		//left to set the b[i] values.
		//For 1 <= i <= N - 2, the longest mountain size is a[i] + b[i] + 1.
		//So the answer is the minimum N - (a[i] + b[i] + 1).
		
		//
		//Note that we need to skip cases where either a[i] or b[i] is zero because it's
		//invalid.
		//Test cases that should be added:
		//[1,2,1,2,3,4] and [4,3,2,1,2,1]. Correct answer is 3.
		//[1,2,1,1,2,3,4,5] and [5,4,3,2,1,1,2,1]. Correct answer is 5.
		int minimumMountainRemovals(vector<int>& nums) {
			int len = nums.size();
			if (len < 2) { return 0; }

			vector<int> A(len, 0);
			vector<int> tmp;
			for (int i = 0; i < len; i++) {
				int v = nums[i];
				auto it = lower_bound(tmp.begin(), tmp.end(), v);
				A[i] = it - tmp.begin();
				if (it == tmp.end()) { tmp.push_back(v); }
				else { *it = v; }
			}


			vector<int> B(len, 0);
			tmp.clear();
			for (int i = len - 1; i >= 0; i--) {
				int v = nums[i];
				auto it = lower_bound(tmp.begin(), tmp.end(), v);
				B[i] = it - tmp.begin();
				if (it == tmp.end()) { tmp.push_back(v); }
				else { *it = v; }
			}

			int result = len;
			for (int i = 0; i < len; i++) {
				if (A[i] && B[i]) {
					result = min(result, len - (A[i] + B[i] + 1));
				}
			}
			return result;
		}

		void Main() {
			vector<int> test = { 1, 3, 1 };
			print(minimumMountainRemovals(test));
		}
	}
}
