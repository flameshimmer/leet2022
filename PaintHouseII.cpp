#include "stdafx.h"

//There are a row of n houses, each house can be painted with one of the k
//colors. The cost of painting each house with a certain color is different. You
//have to paint all the houses such that no two adjacent houses have the same
//color.
//The cost of painting each house with a certain color is represented by an n x k
//cost matrix costs.
//For example, costs[0][0] is the cost of painting house 0 with color 0;
//costs[1][2] is the cost of painting house 1 with color 2, and so on...
//Return the minimum cost to paint all houses.
// 
//
//Example 1:
//Input: costs = [[1,5,3],[2,9,4]]
//Output: 5
//Explanation:
//Paint house 0 into color 0, paint house 1 into color 2. Minimum cost: 1 + 4 =
//5; 
//Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 + 2
//= 5.
//
//Example 2:
//Input: costs = [[1,3],[2,4]]
//Output: 5
// 
//Constraints:
//costs.length == n
//costs[i].length == k
//1 <= n <= 100
//2 <= k <= 20
//1 <= costs[i][j] <= 20
// 
//Follow up: Could you solve it in O(nk) runtime?

namespace Solution2022
{
	namespace PaintHouseII
	{
	    int minCostII(vector<vector<int>>& costs) {
			int len = costs.size();
			if (len == 0) { return 0; }

			int houseCount = costs.size();
			int paintCount = costs[0].size();

			int min1Color = -1;
			int min2Color = -1;

			for (int i = 0; i < houseCount; i++) {
				int lastMin1Color = min1Color;
				int lastMin2Color = min2Color;
				min1Color = -1;
				min2Color = -1;

				for (int j = 0; j < paintCount; j++) {
					if (j != lastMin1Color) {
						costs[i][j] += (lastMin1Color == -1) ? 0 : costs[i - 1][lastMin1Color];
					}
					else {
						costs[i][j] += (lastMin2Color == -1) ? 0 : costs[i - 1][lastMin2Color];
					}
					
					if (min1Color == -1 || costs[i][j] < costs[i][min1Color]) {
						min2Color = min1Color;
						min1Color = j;
					}
					else if (min2Color == -1 || costs[i][j] < costs[i][min2Color]) {
						min2Color = j;
					}
				}				
			}
			return costs[len - 1][min1Color];
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
