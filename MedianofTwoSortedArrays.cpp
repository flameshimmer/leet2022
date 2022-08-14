#include "stdafx.h"

//Given two sorted arrays nums1 and nums2 of size m and n respectively, return
//the median of the two sorted arrays.
//The overall run time complexity should be O(log (m+n)).
// 
//
//Example 1:
//Input: nums1 = [1,3], nums2 = [2]
//Output: 2.00000
//Explanation: merged array = [1,2,3] and median is 2.
//
//Example 2:
//Input: nums1 = [1,2], nums2 = [3,4]
//Output: 2.50000
//Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
// 
//Constraints:
//nums1.length == m
//nums2.length == n
//0 <= m <= 1000
//0 <= n <= 1000
//1 <= m + n <= 2000
//-106 <= nums1[i], nums2[i] <= 106

namespace Solution2022
{
	namespace MedianofTwoSortedArrays
	{
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			int len1 = nums1.size();
			int len2 = nums2.size();
			if (len1 > len2) { return findMedianSortedArrays(nums2, nums1); }

			int k = (len1 + len2 + 1) / 2;

			int l = 0;
			int r = len1;
			while (l < r) {
				int m1 = l + (r - l) / 2;
				int m2 = k - m1;
				if (nums1[m1] < nums2[m2 - 1]) {
					l = m1 + 1;
				}
				else {
					r = m1;
				}
			}
			int m1 = l;
			int m2 = k - m1;

			int c1 = max(m1 <= 0 ? INT_MIN : nums1[m1 - 1], m2 <= 0 ? INT_MIN : nums2[m2 - 1]);
			if ((len1 + len2) % 2 == 1) { return c1; }

			int c2 = min(m1 >= len1 ? INT_MAX : nums1[m1], m2 >= len2 ? INT_MAX : nums2[m2]);
			return (c1 + c2) * 0.5; // use *0.5 instead of /2 to ensure the return value is double and not clipped. 
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
