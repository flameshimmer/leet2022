#include "stdafx.h"

//There is an m x n rectangular island that borders both the Pacific Ocean and
//Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and
//the Atlantic Ocean touches the island's right and bottom edges.
//The island is partitioned into a grid of square cells. You are given an m x n
//integer matrix heights where heights[r][c] represents the height above sea
//level of the cell at coordinate (r, c).
//The island receives a lot of rain, and the rain water can flow to neighboring
//cells directly north, south, east, and west if the neighboring cell's height is
//less than or equal to the current cell's height. Water can flow from any cell
//adjacent to an ocean into the ocean.
//Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes
//that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic
//oceans.
// 
//
//Example 1:
//Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
//Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
//
//Example 2:
//Input: heights = [[2,1],[1,2]]
//Output: [[0,0],[0,1],[1,0],[1,1]]
// 
//Constraints:
//m == heights.length
//n == heights[r].length
//1 <= m, n <= 200
//0 <= heights[r][c] <= 105

namespace Solution2022
{
	namespace PacificAtlanticWaterFlow
	{
		void helper(int i, int j, int rowCount, int colCount, vector<vector<int>>& heights, vector<vector<bool>>& map) { // NOTE: over here the map serves two purpose, 1 for result, the other for visited map. 
			if (i < 0 || i >= rowCount || j < 0 || j >= colCount) { return; }
			map[i][j] = true;

			if (i - 1 >= 0 && !map[i - 1][j] && heights[i - 1][j] >= heights[i][j]) { helper(i - 1, j, rowCount, colCount, heights, map); }
			if (i + 1 < rowCount && !map[i + 1][j] && heights[i + 1][j] >= heights[i][j]) { helper(i + 1, j, rowCount, colCount, heights, map); }
			if (j - 1 >= 0 && !map[i][j - 1] && heights[i][j - 1] >= heights[i][j]) { helper(i, j - 1, rowCount, colCount, heights, map); }
			if (j + 1 < colCount && !map[i][j + 1] && heights[i][j + 1] >= heights[i][j]) { helper(i, j + 1, rowCount, colCount, heights, map); }
		}

		vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
			int rowCount = heights.size();
			int colCount = heights[0].size();

			vector<vector<bool>> pacific(rowCount, vector<bool>(colCount, false));
			vector<vector<bool>> atlantic(rowCount, vector<bool>(colCount, false));
			vector<vector<int>> result;

			for (int i = 0; i < rowCount; i++) {
				helper(i, 0, rowCount, colCount, heights, pacific);
				helper(i, colCount - 1, rowCount, colCount, heights, atlantic);
			}

			for (int j = 0; j < colCount; j++) {
				helper(0, j, rowCount, colCount, heights, pacific);
				helper(rowCount - 1, j, rowCount, colCount, heights, atlantic);
			}

			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					if (pacific[i][j] && atlantic[i][j]) { result.push_back({ i, j }); }
				}
			}
			return result;
		}

		void Main() {
			vector<vector<int>> test = { {1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4} };
			print(pacificAtlantic(test));
		}
	}
}
