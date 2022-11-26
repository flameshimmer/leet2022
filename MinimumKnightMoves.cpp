#include "stdafx.h"

//In an infinite chess board with coordinates from -infinity to +infinity, you
//have a knight at square [0, 0].
//A knight has 8 possible moves it can make, as illustrated below. Each move is
//two squares in a cardinal direction, then one square in an orthogonal direction.
//Return the minimum number of steps needed to move the knight to the square [x,
//y]. It is guaranteed the answer exists.
// 
//
//Example 1:
//Input: x = 2, y = 1
//Output: 1
//Explanation: [0, 0] → [2, 1]
//
//Example 2:
//Input: x = 5, y = 5
//Output: 4
//Explanation: [0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]
// 
//Constraints:
//-300 <= x, y <= 300
//0 <= |x| + |y| <= 300

namespace Solution2022
{
	namespace MinimumKnightMoves
	{
		int minKnightMoves(int x, int y) {
			if (x == 0 && y == 0) { return 0; }
			x = abs(x);
			y = abs(y);
			if (x < y) { swap(x, y); }

			vector<pair<int, int>> dirs = { {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1} };
			queue<pair<int, int>> q;
			q.push({ 0, 0 });
			unordered_set<int> visited;
			visited.insert({ 0 });

			int level = 0;
			while (!q.empty()) {
				int sz = q.size();
				while (sz) {
					sz--;
					auto [curX, curY] = q.front();
					q.pop();

					if (curX == x && curY == y) { return level; }

					for (auto [a, b] : dirs) {
						int r = curX + a;
						int c = curY + b;
						if (r < c) { swap(r, c); }
						int key = r * 1024 + c;
						if (visited.find(key) != visited.end()) { continue; }
						q.push({ r, c });
						visited.insert(key);
					}
				}
				level++;
			}
			return -1;
		}

		void Main() {
			print(minKnightMoves(2, 112));
		}
	}
}
