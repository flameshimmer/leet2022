#include "stdafx.h"

//You are given an integer array nums and you have to return a new counts array.
//The counts array has the property where counts[i] is the number of smaller
//elements to the right of nums[i].
// 
//
//Example 1:
//Input: nums = [5,2,6,1]
//Output: [2,1,1,0]
//Explanation:
//To the right of 5 there are 2 smaller elements (2 and 1).
//To the right of 2 there is only 1 smaller element (1).
//To the right of 6 there is 1 smaller element (1).
//To the right of 1 there is 0 smaller element.
//
//Example 2:
//Input: nums = [-1]
//Output: [0]
//
//Example 3:
//Input: nums = [-1,-1]
//Output: [0,0]
// 
//Constraints:
//1 <= nums.length <= 105
//-104 <= nums[i] <= 104

namespace Solution2022
{
	namespace CountofSmallerNumbersAfterSelf
	{
		void helper(vector<pair<int, int>>::iterator begin, vector<pair<int, int>>::iterator end, vector<int>& result) {
			if (end - begin <= 1) { return; } // no mid element to process here, directly return.

			auto mid = begin + (end - begin) / 2;
			helper(begin, mid, result);
			helper(mid, end, result);

			auto j = mid;
			for (auto i = begin; i < mid; i++) {
				while (j < end && i->first > j->first) { j++; }
				result[i->second] += j - mid;
			}
			inplace_merge(begin, mid, end);
		}

	    vector<int> countSmaller(vector<int>& nums) {
			int len = nums.size();
			vector<int> result(len);
			vector<pair<int, int>> A;

			for (int i = 0; i < len; i++) {
				A.push_back({nums[i], i});
			}
			helper(A.begin(), A.end(), result);
			return result;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
