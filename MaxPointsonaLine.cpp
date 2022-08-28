#include "stdafx.h"

//Given an array of points where points[i] = [xi, yi] represents a point on the
//X-Y plane, return the maximum number of points that lie on the same straight
//line.
// 
//
//Example 1:
//Input: points = [[1,1],[2,2],[3,3]]
//Output: 3
//
//Example 2:
//Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
//Output: 4
// 
//Constraints:
//1 <= points.length <= 300
//points[i].length == 2
//-104 <= xi, yi <= 104
//All the points are unique.

namespace Solution2022
{
	namespace MaxPointsonaLine
	{
		int GCD(int a, int b) { // note: this is different imp than the std::gcd and will return different value.
			if (b == 0) { return a; }
			return GCD(b, a % b);
		}

		int maxPoints(vector<vector<int>>& points) {
			int len = points.size();
			if (len < 2) { return len; }

			int x, y, gcd;
			string key;
			int result = 0;

			for (int i = 0; i < points.size(); i++) {
				unordered_map<string, int> map;
				int dup = 1;
				int verCount = 0;
				int maxNonVerCount = 0;

				vector<int> cur = points[i];
				for (int j = i + 1; j < len; j++) {
					vector<int> next = points[j];
					if (cur[0] == next[0] && cur[1] == next[1]) { dup++; }
					else if (cur[0] == next[0]) { verCount++; }
					else {
						x = next[0] - cur[0];
						y = next[1] - cur[1];
						gcd = GCD(x, y);
						key = to_string(y / gcd) + "_" + to_string(x / gcd);
						map[key]++;
						maxNonVerCount = max(maxNonVerCount, map[key]);
					}
				}
				int curResult = max(verCount, maxNonVerCount) + dup;
				result = max(result, curResult);
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
