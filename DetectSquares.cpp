#include "stdafx.h"

//You are given a stream of points on the X-Y plane. Design an algorithm that:
//Adds new points from the stream into a data structure. Duplicate points are
//allowed and should be treated as different points.
//Given a query point, counts the number of ways to choose three points from the
//data structure such that the three points and the query point form an
//axis-aligned square with positive area.
//An axis-aligned square is a square whose edges are all the same length and are
//either parallel or perpendicular to the x-axis and y-axis.
//Implement the DetectSquares class:
//DetectSquares() Initializes the object with an empty data structure.
//void add(int[] point) Adds a new point point = [x, y] to the data structure.
//int count(int[] point) Counts the number of ways to form axis-aligned squares
//with point point = [x, y] as described above.
// 
//
//Example 1:
//Input
//["DetectSquares", "add", "add", "add", "count", "count", "add", "count"]
//[[], [[3, 10]], [[11, 2]], [[3, 2]], [[11, 10]], [[14, 8]], [[11, 2]], [[11,
//10]]]
//Output
//[null, null, null, null, 1, 0, null, 2]
//Explanation
//DetectSquares detectSquares = new DetectSquares();
//detectSquares.add([3, 10]);
//detectSquares.add([11, 2]);
//detectSquares.add([3, 2]);
//detectSquares.count([11, 10]); // return 1. You can choose:
//                               //   - The first, second, and third points
//detectSquares.count([14, 8]);  // return 0. The query point cannot form a
//square with any points in the data structure.
//detectSquares.add([11, 2]);    // Adding duplicate points is allowed.
//detectSquares.count([11, 10]); // return 2. You can choose:
//                               //   - The first, second, and third points
//                               //   - The first, third, and fourth points
// 
//Constraints:
//point.length == 2
//0 <= x, y <= 1000
//At most 3000 calls in total will be made to add and count.

namespace Solution2022
{
	namespace DetectSquares
	{
		class DetectSquares {
			vector<vector<int>> map; // map[x][y], value is number of points of (x, y)
			vector<pair<int, int>> data;
		public:
			DetectSquares() {
				map.resize(1001, vector<int>(1001, 0));
			}

			void add(vector<int> point) {
				map[point[0]][point[1]]++;
				data.push_back({ point[0], point[1] });
			}

			int count(vector<int> point) {
				int x1 = point[0];
				int y1 = point[1];
				int result = 0;
				for (auto& [x3, y3] : data) {
					if (x1 == x3 || abs(x1 - x3) != abs(y1 - y3)) { continue; }
					result += map[x1][y3] * map[x3][y1]; // Note: x, y's position won't change!
				}
				return result;
			}
		};

		/**
		 * Your DetectSquares object will be instantiated and called as such:
		 * DetectSquares* obj = new DetectSquares();
		 * obj->add(point);
		 * int param_2 = obj->count(point);
		 */

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
