#include "stdafx.h"

//You are given an n x n integer matrix grid where each value grid[i][j]
//represents the elevation at that point (i, j).
//The rain starts to fall. At time t, the depth of the water everywhere is t. You
//can swim from a square to another 4-directionally adjacent square if and only
//if the elevation of both squares individually are at most t. You can swim
//infinite distances in zero time. Of course, you must stay within the boundaries
//of the grid during your swim.
//Return the least time until you can reach the bottom right square (n - 1, n -
//1) if you start at the top left square (0, 0).
// 
//
//Example 1:
//Input: grid = [[0,2],[1,3]]
//Output: 3
//Explanation:
//At time 0, you are in grid location (0, 0).
//You cannot go anywhere else because 4-directionally adjacent neighbors have a
//higher elevation than t = 0.
//You cannot reach point (1, 1) until time 3.
//When the depth of water is 3, we can swim anywhere inside the grid.
//
//Example 2:
//Input: grid =
//[[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
//Output: 16
//Explanation: The final route is shown.
//We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
// 
//Constraints:
//n == grid.length
//n == grid[i].length
//1 <= n <= 50
//0 <= grid[i][j] < n2
//Each value grid[i][j] is unique.

namespace Solution2022
{
	namespace SwiminRisingWater
	{
		struct T {
			int t, x, y;
			T(int a, int b, int c) : t(a), x(b), y(c) {}
			bool operator < (const T& d) const {
				return t > d.t;
			}
		};

		int swimInWater(vector<vector<int>>& grid) {
			int len = grid.size();
			int result = 0;
			vector<vector<int>> dirs = { {0, 1}, {1, 0}, {-1, 0}, {0, -1}};

			priority_queue<T> pq;
			vector<vector<int>> visited(len, vector<int>(len, 0));
			pq.push(T(grid[0][0], 0, 0));			
			visited[0][0] = 1;

			while (!pq.empty()) {
				auto [t, x, y] = pq.top();
				pq.pop();

				result = max(result, t);
				if (x == len - 1 && y == len - 1) { return result; }
				for (auto& dir : dirs) {
					int xx = x + dir[0];
					int yy = y + dir[1];
					if (xx >= 0 && xx < len && yy >= 0 && yy < len && !visited[xx][yy]) {
						visited[xx][yy] = 1; // don't forget to update visited!
						pq.push(T(grid[xx][yy], xx, yy));
					}
				}
			}
			return -1;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
