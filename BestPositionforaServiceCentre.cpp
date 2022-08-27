#include "stdafx.h"

//A delivery company wants to build a new service center in a new city. The
//company knows the positions of all the customers in this city on a 2D-Map and
//wants to build the new center in a position such that the sum of the euclidean
//distances to all customers is minimum.
//Given an array positions where positions[i] = [xi, yi] is the position of the
//ith customer on the map, return the minimum sum of the euclidean distances to
//all customers.
//In other words, you need to choose the position of the service center [xcentre,
//ycentre] such that the following formula is minimized:
//Answers within 10-5 of the actual value will be accepted.
// 
//
//Example 1:
//Input: positions = [[0,1],[1,0],[1,2],[2,1]]
//Output: 4.00000
//Explanation: As shown, you can see that choosing [xcentre, ycentre] = [1, 1]
//will make the distance to each customer = 1, the sum of all distances is 4
//which is the minimum possible we can achieve.
//
//Example 2:
//Input: positions = [[1,1],[3,3]]
//Output: 2.82843
//Explanation: The minimum possible sum of distances = sqrt(2) + sqrt(2) = 2.82843
// 
//Constraints:
//1 <= positions.length <= 50
//positions[i].length == 2
//0 <= xi, yi <= 100

namespace Solution2022
{
	namespace BestPositionforaServiceCentre
	{
		double dist(vector<int>& a, vector<double>& b) {
			return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
		}

		double all(vector<vector<int>>& A, vector<double>& point) {
			double result = 0;
			for (vector<int>& a : A) { result += dist(a, point); }
			return result;
		}

		double getMinDistSum(vector<vector<int>>& A) {
			vector<pair<int, int>> dirs = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
			double result = DBL_MAX;

			vector<double> p(2, 0);

			double step = 100;
			double eps = 1e-6;

			while (step > eps) {
				bool found = false;
				for (auto [x, y] : dirs) {
					vector<double> next = {p[0] + step * x, p[1] + step * y};
					double d = all(A, next);
					if (d < result) {
						result = d;
						p = next;
						found = true;
						break;
					}
				}
				if (!found) { step /= 2; }
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
