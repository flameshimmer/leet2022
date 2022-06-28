#include "stdafx.h"

//You are given an integer array nums. The range of a subarray of nums is the
//difference between the largest and smallest element in the subarray.
//Return the sum of all subarray ranges of nums.
//A subarray is a contiguous non-empty sequence of elements within an array.
// 
//
//Example 1:
//Input: nums = [1,2,3]
//Output: 4
//Explanation: The 6 subarrays of nums are the following:
//[1], range = largest - smallest = 1 - 1 = 0 
//[2], range = 2 - 2 = 0
//[3], range = 3 - 3 = 0
//[1,2], range = 2 - 1 = 1
//[2,3], range = 3 - 2 = 1
//[1,2,3], range = 3 - 1 = 2
//So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
//
//Example 2:
//Input: nums = [1,3,3]
//Output: 4
//Explanation: The 6 subarrays of nums are the following:
//[1], range = largest - smallest = 1 - 1 = 0
//[3], range = 3 - 3 = 0
//[3], range = 3 - 3 = 0
//[1,3], range = 3 - 1 = 2
//[3,3], range = 3 - 3 = 0
//[1,3,3], range = 3 - 1 = 2
//So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
//
//Example 3:
//Input: nums = [4,-2,-3,4,1]
//Output: 59
//Explanation: The sum of all subarray ranges of nums is 59.
// 
//Constraints:
//1 <= nums.length <= 1000
//-109 <= nums[i] <= 109
// 
//Follow-up: Could you find a solution with O(n) time complexity?

namespace Solution2022
{
	namespace SumofSubarrayRanges
	{
		long long sumSubarrayMin(vector<int>& arr) {
			int len = arr.size();

			vector<int> left(len);
			stack<int> s; //index stack
			for (int i = 0; i < len; i++) {
				while (!s.empty() && arr[s.top()] > arr[i]) {
					s.pop();
				}

				left[i] = s.empty() ? (i + 1) : (i - s.top());
				s.push(i);
			}

			while (!s.empty()) { s.pop(); }

			vector<int> right(len);
			for (int i = len - 1; i >= 0; i--) {
				while (!s.empty() && arr[s.top()] >= arr[i]) { // note that this part is >= instead of >
					s.pop();
				}
				right[i] = s.empty() ? (len - i) : (s.top() - i);
				s.push(i);
			}


			long long result = 0;
			for (int i = 0; i < len; i++) {
				result += (long long)left[i] * (long long)right[i] * (long long)arr[i];
			}
			return result;
		}

		long long sumSubarrayMax(vector<int>& arr) {
			int len = arr.size();

			vector<int> left(len);
			stack<int> s; //index stack
			for (int i = 0; i < len; i++) {
				while (!s.empty() && arr[s.top()] < arr[i]) {
					s.pop();
				}

				left[i] = s.empty() ? (i + 1) : (i - s.top());
				s.push(i);
			}

			while (!s.empty()) { s.pop(); }

			vector<int> right(len);
			for (int i = len - 1; i >= 0; i--) {
				while (!s.empty() && arr[s.top()] <= arr[i]) { // note that this part is >= instead of >
					s.pop();
				}
				right[i] = s.empty() ? (len - i) : (s.top() - i);
				s.push(i);
			}


			long long result = 0;
			for (int i = 0; i < len; i++) {
				result += (long long)left[i] * (long long)right[i] * (long long)arr[i];
			}
			return result;
		}

	    long long subArrayRanges(vector<int>& nums) {
			return sumSubarrayMax(nums) - sumSubarrayMin(nums);
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
