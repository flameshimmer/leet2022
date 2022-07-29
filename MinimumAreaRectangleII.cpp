#include "stdafx.h"

//You are given an array of points in the X-Y plane points where points[i] = [xi,
//yi].
//Return the minimum area of any rectangle formed from these points, with sides
//not necessarily parallel to the X and Y axes. If there is not any such
//rectangle, return 0.
//Answers within 10-5 of the actual answer will be accepted.
// 
//
//Example 1:
//Input: points = [[1,2],[2,1],[1,0],[0,1]]
//Output: 2.00000
//Explanation: The minimum area rectangle occurs at [1,2],[2,1],[1,0],[0,1], with
//an area of 2.
//
//Example 2:
//Input: points = [[0,1],[2,1],[1,1],[1,0],[2,0]]
//Output: 1.00000
//Explanation: The minimum area rectangle occurs at [1,0],[1,1],[2,1],[2,0], with
//an area of 1.
//
//Example 3:
//Input: points = [[0,3],[1,2],[3,1],[1,3],[2,1]]
//Output: 0
//Explanation: There is no possible rectangle to form from these points.
// 
//Constraints:
//1 <= points.length <= 50
//points[i].length == 2
//0 <= xi, yi <= 4 * 104
//All the given points are unique.

namespace Solution2022
{
	namespace MinimumAreaRectangleII
	{
	    double minAreaFreeRect(vector<vector<int>>& points) {
			map<pair<int, int>, vector<pair<int, int>>> map;
			int len = points.size();

			for (int i = 0; i < len; i++) {
				for (int j = 0; j < len; j++) {
					if (i == j) { continue; }
					int deltaX = points[i][0] - points[j][0];
					int deltaY = points[i][1] - points[j][1];
					map[{deltaX, deltaY}].push_back({ i, j });
				}
			}

			double result = INT_MAX;
			for (auto& item : map) {
				int size = item.second.size();
				for (int m = 0; m < size; m++) {
					for (int n = m + 1; n < size; n++) {
						int i = item.second[m].first;
						int j = item.second[m].second;
						int k = item.second[n].first;

						int dx1 = points[i][0] - points[j][0];
						int dy1 = points[i][1] - points[j][1];
						int dx2 = points[i][0] - points[k][0];
						int dy2 = points[i][1] - points[k][1];

						if (dx1 * dx2 + dy1 * dy2 != 0) { continue; }

						double side1 = sqrt((points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]));
						double side2 = sqrt((points[i][0] - points[k][0]) * (points[i][0] - points[k][0]) + (points[i][1] - points[k][1]) * (points[i][1] - points[k][1]));
						double area = side1 * side2;
						result = min(result, area);
					}
				}
			}
			return result == INT_MAX ? 0 : result;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
