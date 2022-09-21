#include "stdafx.h"

//Given an array nums which consists of non-negative integers and an integer m,
//you can split the array into m non-empty continuous subarrays.
//Write an algorithm to minimize the largest sum among these m subarrays.
// 
//
//Example 1:
//Input: nums = [7,2,5,10,8], m = 2
//Output: 18
//Explanation:
//There are four ways to split nums into two subarrays.
//The best way is to split it into [7,2,5] and [10,8],
//where the largest sum among the two subarrays is only 18.
//
//Example 2:
//Input: nums = [1,2,3,4,5], m = 2
//Output: 9
//
//Example 3:
//Input: nums = [1,4,4], m = 3
//Output: 4
// 
//Constraints:
//1 <= nums.length <= 1000
//0 <= nums[i] <= 106
//1 <= m <= min(50, nums.length)

namespace Solution2022
{
	namespace SplitArrayLargestSum
	{
		namespace BinarySearch {
			// if we have cut+1 chunk and every chunk's sum can be controlled under maxChunkSum
			// return true, otherwise returns false
			bool doable(vector<int>& nums, int cut, int maxChunkSum) {
				int curSum = 0;
				for (int v : nums) {
					if (curSum + v <= maxChunkSum) { curSum += v; }
					else {
						cut--;
						curSum = v;
						if (cut < 0) { return false; }
					}
				}
				return true;
			}

			int splitArray(vector<int>& nums, int m) {
				long long left = *max_element(nums.begin(), nums.end()); // binary search range left: maxElem in the array - if each chunk size is 1
				long long right = accumulate(nums.begin(), nums.end(), 0);  // binary search range right: sum of the array - if the entire array is a single chunk

				while (left < right) {
					long long mid = left + (right - left) / 2;
					if (doable(nums, m - 1, mid)) {
						right = mid;
					}
					else {
						left = mid + 1;
					}
				}
				return left;
			}
		}


		namespace DP {
			int splitArray(vector<int>& nums, int m) {
				const int len = nums.size();
				vector<long long> sum(len);
				// spliting nums from 0 ~ j index into i groups.
				vector<vector<int>> dp(m + 1, vector<int>(len, INT_MAX));

				sum[0] = nums[0];
				for (int i = 1; i < len; i++) { sum[i] = sum[i - 1] + nums[i]; }

				for (int i = 0; i < len; i++) {
					dp[1][i] = sum[i];
				}

				for (int i = 2; i <= m; i++) {
					for (int j = i - 1; j < len; j++) {
						for (int k = 0; k < j; k++) {
							dp[i][j] = min(dp[i][j], max(dp[i - 1][k], (int)(sum[j] - sum[k])));
						}
					}
				}
				return dp[m][len - 1];
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
