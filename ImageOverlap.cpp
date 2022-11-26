#include "stdafx.h"

//You are given two images, img1 and img2, represented as binary, square matrices
//of size n x n. A binary matrix has only 0s and 1s as values.
//We translate one image however we choose by sliding all the 1 bits left, right,
//up, and/or down any number of units. We then place it on top of the other
//image. We can then calculate the overlap by counting the number of positions
//that have a 1 in both images.
//
//Note also that a translation does not include any kind of rotation. Any 1 bits
//that are translated outside of the matrix borders are erased.
//Return the largest possible overlap.
// 
//
//Example 1:
//Input: img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
//Output: 3
//Explanation: We translate img1 to right by 1 unit and down by 1 unit.
//The number of positions that have a 1 in both images is 3 (shown in red).
//
//Example 2:
//Input: img1 = [[1]], img2 = [[1]]
//Output: 1
//
//Example 3:
//Input: img1 = [[0]], img2 = [[0]]
//Output: 0
// 
//Constraints:
//n == img1.length == img1[i].length
//n == img2.length == img2[i].length
//1 <= n <= 30
//img1[i][j] is either 0 or 1.
//img2[i][j] is either 0 or 1.

namespace Solution2022
{
	namespace ImageOverlap
	{
		int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
			vector<pair<int, int>> g1;
			vector<pair<int, int>> g2;
			int len = img1.size();

			for (int i = 0; i < len; i++) {
				for (int j = 0; j < len; j++) {
					if (img1[i][j]) { g1.push_back({ i, j }); }
					if (img2[i][j]) { g2.push_back({ i, j }); }
				}
			}

			map<pair<int, int>, int> map;
			int result = 0;
			for (auto [x1, y1] : g1) {
				for (auto [x2, y2] : g2) {
					pair<int, int> key = { x1 - x2, y1 - y2 };
					map[key]++;
					result = max(result, map[key]);
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
