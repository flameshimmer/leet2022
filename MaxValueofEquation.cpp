#include "stdafx.h"

//You are given an array points containing the coordinates of points on a 2D
//plane, sorted by the x-values, where points[i] = [xi, yi] such that xi < xj for
//all 1 <= i < j <= points.length. You are also given an integer k.
//Return the maximum value of the equation yi + yj + |xi - xj| where |xi - xj| <=
//k and 1 <= i < j <= points.length.
//It is guaranteed that there exists at least one pair of points that satisfy the
//constraint |xi - xj| <= k.
// 
//
//Example 1:
//Input: points = [[1,3],[2,0],[5,10],[6,-10]], k = 1
//Output: 4
//Explanation: The first two points satisfy the condition |xi - xj| <= 1 and if
//we calculate the equation we get 3 + 0 + |1 - 2| = 4. Third and fourth points
//also satisfy the condition and give a value of 10 + -10 + |5 - 6| = 1.
//No other pairs satisfy the condition, so we return the max of 4 and 1.
//
//Example 2:
//Input: points = [[0,0],[3,0],[9,2]], k = 3
//Output: 3
//Explanation: Only the first two points have an absolute difference of 3 or less
//in the x-values, and give the value of 0 + 0 + |0 - 3| = 3.
// 
//Constraints:
//2 <= points.length <= 105
//points[i].length == 2
//-108 <= xi, yi <= 108
//0 <= k <= 2 * 108
//xi < xj for all 1 <= i < j <= points.length
//xi form a strictly increasing sequence.

namespace Solution2022
{
	namespace MaxValueofEquation
	{
		//Suppose i < j, then we can translate yi + yj + | xi - xj | to (yi - xi) + (yj + xj).
		//For a given point_j, since(yj + xj) is fixed, we only need to maximize the(yi - xi) among the previously seen point_i.
		//What data structure to use to efficiently find the biggest previously yi - xi for each point_j = (xj, yj) ? MaxHeap!

		int findMaxValueOfEquation(vector<vector<int>>& p, int k) {
			priority_queue<pair<int, int>> pq;
			pq.push({ p[0][1] - p[0][0], p[0][0] });

			int result = INT_MIN;
			for (int i = 1; i < p.size(); i++) {
				int sum = p[i][0] + p[i][1]; // i here maps to point j in the problem
				while (!pq.empty() && p[i][0] - pq.top().second > k) { pq.pop(); }
				if (!pq.empty()) { result = max(result, sum + pq.top().first); } // pq.top() here maps to point i in the problem 
				pq.push({ p[i][1] - p[i][0] , p[i][0] });
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
