#include "stdafx.h"

//Given two integer arrays nums1 and nums2, return the maximum length of a
//subarray that appears in both arrays.
// 
//
//Example 1:
//Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
//Output: 3
//Explanation: The repeated subarray with maximum length is [3,2,1].
//
//Example 2:
//Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
//Output: 5
// 
//Constraints:
//1 <= nums1.length, nums2.length <= 1000
//0 <= nums1[i], nums2[i] <= 100

namespace Solution2022
{
	namespace MaximumLengthofRepeatedSubarray
	{

		int findLength(vector<int>& a, vector<int>& b) {
			int lena = a.size();
			int lenb = b.size();
			if (lena == 0 || lenb == 0) { return 0; }

			int result = 0;
			vector<vector<int>> dp(lena + 1, vector<int>(lenb + 1, 0));
			for (int i = 1; i < lena + 1; i++) { // NOTE: i and j should start with 1 instead of 0!!!
				for (int j = 1; j < lenb + 1; j++) {
					if (a[i - 1] == b[j - 1]) {
						dp[i][j] = dp[i - 1][j - 1] + 1;
						result = max(result, dp[i][j]);
					}
				}
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
