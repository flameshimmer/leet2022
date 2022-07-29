#include "stdafx.h"

//You are given an array of points in the X-Y plane points where points[i] = [xi,
//yi].
//Return the minimum area of a rectangle formed from these points, with sides
//parallel to the X and Y axes. If there is not any such rectangle, return 0.
// 
//
//Example 1:
//Input: points = [[1,1],[1,3],[3,1],[3,3],[2,2]]
//Output: 4
//
//Example 2:
//Input: points = [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
//Output: 2
// 
//Constraints:
//1 <= points.length <= 500
//points[i].length == 2
//0 <= xi, yi <= 4 * 104
//All the given points are unique.

namespace Solution2022
{
	namespace MinimumAreaRectangle
	{
	    int minAreaRect(vector<vector<int>>& points) {
			unordered_map<int, set<int>> data;
			for (vector<int>& p : points) { data[p[0]].insert(p[1]); }

			int result = INT_MAX;
			for (auto i = data.begin(); i != data.end(); i++) {
				for (auto j = next(i); j != data.end(); j++) {
					int x1 = i->first;
					auto y1s = i->second;
					int x2 = j->first;
					auto y2s = j->second;

					if (y1s.size() < 2 || y2s.size() < 2) { continue; }
					vector<int> commonY;
					set_intersection(y1s.begin(), y1s.end(), y2s.begin(), y2s.end(), back_inserter(commonY));
					for (int k = 1; k < commonY.size(); k++) {
						result = min(result, abs(x1 - x2) * (commonY[k] - commonY[k - 1]));
					}
				}
			}
			return result == INT_MAX ? 0 : result;
	    }

		void Main() {
			vector<vector<int>> test = { {1,1},{1,3},{3,1},{3,3},{2,2} };
			print(minAreaRect(test));
		}
	}
}
