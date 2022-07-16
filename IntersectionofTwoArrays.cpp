#include "stdafx.h"
#include <iterator>
//Given two integer arrays nums1 and nums2, return an array of their
//intersection. Each element in the result must be unique and you may return the
//result in any order.
// 
//
//Example 1:
//Input: nums1 = [1,2,2,1], nums2 = [2,2]
//Output: [2]
//
//Example 2:
//Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//Output: [9,4]
//Explanation: [4,9] is also accepted.
// 
//Constraints:
//1 <= nums1.length, nums2.length <= 1000
//0 <= nums1[i], nums2[i] <= 1000

namespace Solution2022
{
	namespace IntersectionofTwoArrays
	{
	    		
		vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
			if (nums1.size() > nums2.size()) {
				return intersection(nums2, nums1);
			}

			unordered_set<int> s1(nums1.begin(), nums1.end());
			unordered_set<int> s2(nums2.begin(), nums2.end());

			vector<int> result;
			for (int v : s1) {
				if (s2.find(v) != s2.end()) { result.push_back(v); }
			}
			return result;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
