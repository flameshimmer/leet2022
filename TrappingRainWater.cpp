#include "stdafx.h"

//Given n non-negative integers representing an elevation map where the width of
//each bar is 1, compute how much water it can trap after raining.
// 
//
//Example 1:
//Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
//Output: 6
//Explanation: The above elevation map (black section) is represented by array
//[0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section)
//are being trapped.
//
//Example 2:
//Input: height = [4,2,0,3,2,5]
//Output: 9
// 
//Constraints:
//n == height.length
//1 <= n <= 2 * 104
//0 <= height[i] <= 105

namespace Solution2022
{
	namespace TrappingRainWater
	{
	    int trap(vector<int>& height) {
			int len = height.size();
			if (len < 2) { return 0; }

			vector<int> left(len, 0);
			vector<int> right(len, 0);
			int maxL = 0;
			int maxR = 0;
			for (int i = 0; i < len; i++) {
				left[i] = maxL;
				maxL = max(maxL, height[i]);
				right[len - 1 - i] = maxR;
				maxR = max(maxR, height[len - 1 - i]);
			}
			int result = 0;
			for (int i = 0; i < len; i++) {
				result += max(0, min(left[i], right[i]) - height[i]);
			}
			return result;
	    }

		int trapMoveEdges(vector<int>& height) {
			int len = height.size();
			if (len < 2) { return 0; }

			int l = 0;
			int r = len - 1;
			int result = 0;
			while (l < r) {
				int lower = min(height[l], height[r]);
				if (lower == height[l]) {
					l++;
					while (l < r && height[l] < lower) {
						result += lower - height[l];
						l++;
					}
				}
				else {
					r--;
					while (l < r && height[r] < lower) {
						result += lower - height[r];
						r--;
					}					
				}						
			}
			return result;
		}

		void Main() {
			vector<int> test = { 0,1,0,2,1,0,1,3,2,1,2,1 };
			print(trapMoveEdges(test));
		}
	}
}
