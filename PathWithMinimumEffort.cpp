#include "stdafx.h"

//You are a hiker preparing for an upcoming hike. You are given heights, a 2D
//array of size rows x columns, where heights[row][col] represents the height of
//cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to
//travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can
//move up, down, left, or right, and you wish to find a route that requires the
//minimum effort.
//A route's effort is the maximum absolute difference in heights between two
//consecutive cells of the route.
//Return the minimum effort required to travel from the top-left cell to the
//bottom-right cell.
// 
//
//Example 1:
//Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
//Output: 2
//Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in
//consecutive cells.
//This is better than the route of [1,2,2,2,5], where the maximum absolute
//difference is 3.
//
//Example 2:
//Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
//Output: 1
//Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in
//consecutive cells, which is better than route [1,3,5,3,5].
//
//Example 3:
//Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
//Output: 0
//Explanation: This route does not require any effort.
// 
//Constraints:
//rows == heights.length
//columns == heights[i].length
//1 <= rows, columns <= 100
//1 <= heights[i][j] <= 106

namespace Solution2022
{
	namespace PathWithMinimumEffort
	{
	    int minimumEffortPath(vector<vector<int>>& heights) {
			int rowCount = heights.size();
			int colCount = heights[0].size();
			vector<pair<int, int>> dirs = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

			vector<vector<int>> efforts(rowCount, vector<int>(colCount, INT_MAX));
			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
			pq.push({ 0, 0 });  // First item is effort, second is row * 100 + col

			while (!pq.empty()) {
				auto [effort, index] = pq.top();
				pq.pop();
				int x = index / 100; 
				int y = index % 100;

				if (effort >= efforts[x][y]) { continue; }
				efforts[x][y] = effort;

				for (auto& [a, b] : dirs) {
					int xx = x + a;
					int yy = y + b;
					if (xx < 0 || xx >= rowCount || yy < 0 || yy >= colCount) { continue; }
					pq.push({ max(effort, abs(heights[x][y] - heights[xx][yy])), xx * 100 + yy });
				}
			}
			return efforts[rowCount - 1][colCount - 1];
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
