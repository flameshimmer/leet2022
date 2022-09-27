#include "stdafx.h"

//You are given two integer arrays nums and multipliers of size n and m
//respectively, where n >= m. The arrays are 1-indexed.
//You begin with a score of 0. You want to perform exactly m operations. On the
//ith operation (1-indexed), you will:
//Choose one integer x from either the start or the end of the array nums.
//Add multipliers[i] * x to your score.
//Remove x from the array nums.
//Return the maximum score after performing m operations.
// 
//
//Example 1:
//Input: nums = [1,2,3], multipliers = [3,2,1]
//Output: 14
//Explanation: An optimal solution is as follows:
//- Choose from the end, [1,2,3], adding 3 * 3 = 9 to the score.
//- Choose from the end, [1,2], adding 2 * 2 = 4 to the score.
//- Choose from the end, [1], adding 1 * 1 = 1 to the score.
//The total score is 9 + 4 + 1 = 14.
//
//Example 2:
//Input: nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
//Output: 102
//Explanation: An optimal solution is as follows:
//- Choose from the start, [-5,-3,-3,-2,7,1], adding -5 * -10 = 50 to the score.
//- Choose from the start, [-3,-3,-2,7,1], adding -3 * -5 = 15 to the score.
//- Choose from the start, [-3,-2,7,1], adding -3 * 3 = -9 to the score.
//- Choose from the end, [-2,7,1], adding 1 * 4 = 4 to the score.
//- Choose from the end, [-2,7], adding 7 * 6 = 42 to the score. 
//The total score is 50 + 15 - 9 + 4 + 42 = 102.
// 
//Constraints:
//n == nums.length
//m == multipliers.length
//1 <= m <= 103
//m <= n <= 105
//-1000 <= nums[i], multipliers[i] <= 1000

namespace Solution2022
{
	namespace MaximumScorefromPerformingMultiplicationOperations
	{
		// begin index, end index, len, nums, multiplier begin index, multiplie len, multipliers, memory table
		int helper(int i, int k, int n, vector<int>& nums, int j, int m, vector<int>& multipliers, vector<vector<int>>& M) {
			if (i + (n - 1 - k) == m) { return 0; }
			if (M[i][j] != INT_MIN) { return M[i][j]; }

			int left = helper(i + 1, k, n, nums, j + 1, m, multipliers, M) + nums[i] * multipliers[j];
			int right = helper(i, k - 1, n, nums, j + 1, m, multipliers, M) + nums[k] * multipliers[j];
			M[i][j] = max(left, right);
			return M[i][j];
		}


		int maximumScore(vector<int>& nums, vector<int>& multipliers) {
			int n = nums.size();
			int m = multipliers.size();
			vector<vector<int>> M(m + 1, vector<int>(m + 1, INT_MIN));
			return helper(0, n - 1, n, nums, 0, m, multipliers, M);
		}

		void Main() {
			vector<int> test1 = { 1, 2, 3 };
			vector<int> test2 = { 3, 2, 1 };
			print(maximumScore(test1, test2));
		}
	}
}
