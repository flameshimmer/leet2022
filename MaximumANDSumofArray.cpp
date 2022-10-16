#include "stdafx.h"

//You are given an integer array nums of length n and an integer numSlots such
//that 2 * numSlots >= n. There are numSlots slots numbered from 1 to numSlots.
//You have to place all n integers into the slots such that each slot contains at
//most two numbers. The AND sum of a given placement is the sum of the bitwise
//AND of every number with its respective slot number.
//For example, the AND sum of placing the numbers [1, 3] into slot 1 and [4, 6]
//into slot 2 is equal to (1 AND 1) + (3 AND 1) + (4 AND 2) + (6 AND 2) = 1 + 1 +
//0 + 2 = 4.
//Return the maximum possible AND sum of nums given numSlots slots.
// 
//
//Example 1:
//Input: nums = [1,2,3,4,5,6], numSlots = 3
//Output: 9
//Explanation: One possible placement is [1, 4] into slot 1, [2, 6] into slot 2,
//and [3, 5] into slot 3. 
//This gives the maximum AND sum of (1 AND 1) + (4 AND 1) + (2 AND 2) + (6 AND 2)
//+ (3 AND 3) + (5 AND 3) = 1 + 0 + 2 + 2 + 3 + 1 = 9.
//
//Example 2:
//Input: nums = [1,3,10,4,7,1], numSlots = 9
//Output: 24
//Explanation: One possible placement is [1, 1] into slot 1, [3] into slot 3, [4]
//into slot 4, [7] into slot 7, and [10] into slot 9.
//This gives the maximum AND sum of (1 AND 1) + (1 AND 1) + (3 AND 3) + (4 AND 4)
//+ (7 AND 7) + (10 AND 9) = 1 + 1 + 3 + 4 + 7 + 8 = 24.
//
//Note that slots 2, 5, 6, and 8 are empty which is permitted.
// 
//Constraints:
//n == nums.length
//1 <= numSlots <= 9
//1 <= n <= 2 * numSlots
//1 <= nums[i] <= 15

namespace Solution2022
{
	namespace MaximumANDSumofArray
	{
	    //https://www.youtube.com/watch?v=RHp1Owj_QaU&t=1574s
		
		
		// Check out in the "state", whether the kth value is larger than 0. 
		// since the state is 三进制， using divide by 3 will help us get rid of the last digit
		bool filled(int state, int k) {
			for (int i = 0; i < k; i++) { state /= 3; } // everytime divide by 3 is getting rid of the last value;
			return state % 3;
		}

	    int maximumANDSum(vector<int>& nums, int numSlots) {
			int n = nums.size();
			nums.insert(nums.begin(), 0);
			int m = pow(3, numSlots);
			vector<vector<int>> dp(n + 1, vector<int>(m, INT_MIN / 2));
			dp[0][0] = 0;

			int result = 0;
			for (int i = 1; i <= n; i++) {
				for (int state = 0; state < m; state++) {
					for (int j = 0; j < numSlots; j++) {
						if (filled(state, j) >= 1) { // ensure there is at least one number that can be moved from this slow
							dp[i][state] = max(dp[i][state], dp[i - 1][state - pow(3, j)] + (nums[i] & (j + 1)));
						}
					}
					if (i == n) {
						result = max(result, dp[i][state]);
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
