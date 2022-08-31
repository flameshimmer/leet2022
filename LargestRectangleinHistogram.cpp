#include "stdafx.h"

//Given an array of integers heights representing the histogram's bar height
//where the width of each bar is 1, return the area of the largest rectangle in
//the histogram.
// 
//
//Example 1:
//Input: heights = [2,1,5,6,2,3]
//Output: 10
//Explanation: The above is a histogram where width of each bar is 1.
//The largest rectangle is shown in the red area, which has an area = 10 units.
//
//Example 2:
//Input: heights = [2,4]
//Output: 4
// 
//Constraints:
//1 <= heights.length <= 105
//0 <= heights[i] <= 104

namespace Solution2022
{
	namespace LargestRectangleinHistogram
	{
		//https://www.youtube.com/watch?v=mesaogfSjD4
		int largestRectangleArea(vector<int>& heights) {
			stack<int> s;
			heights.push_back(0); // ensure the last iterator will clear out stack

			int result = 0;
			for (int i = 0; i < heights.size(); i++) {
				if (s.empty() || heights[s.top()] <= heights[i]) {
					s.push(i);
				}
				else {
					int tmp = s.top();
					s.pop();
					int startIndex = s.empty() ? -1 : s.top(); // previous index is -1 if stack is empty
					result = max(result, heights[tmp] * (i - startIndex - 1)); // height * (nextSmallerIndex - lastSmallerIndex - 1)
					i--; // since we didn't push i in this case, i--
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
