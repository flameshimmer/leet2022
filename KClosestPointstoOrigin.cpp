#include "stdafx.h"

//Given an array of points where points[i] = [xi, yi] represents a point on the
//X-Y plane and an integer k, return the k closest points to the origin (0, 0).
//The distance between two points on the X-Y plane is the Euclidean distance
//(i.e., √(x1 - x2)2 + (y1 - y2)2).
//You may return the answer in any order. The answer is guaranteed to be unique
//(except for the order that it is in).
// 
//
//Example 1:
//Input: points = [[1,3],[-2,2]], k = 1
//Output: [[-2,2]]
//Explanation:
//The distance between (1, 3) and the origin is sqrt(10).
//The distance between (-2, 2) and the origin is sqrt(8).
//Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
//We only want the closest k = 1 points from the origin, so the answer is just
//[[-2,2]].
//
//Example 2:
//Input: points = [[3,3],[5,-1],[-2,4]], k = 2
//Output: [[3,3],[-2,4]]
//Explanation: The answer [[-2,4],[3,3]] would also be accepted.
// 
//Constraints:
//1 <= k <= points.length <= 104
//-104 < xi, yi < 104

namespace Solution2022
{
	namespace KClosestPointstoOrigin
	{
	    // sort with existing data structure
		namespace SortWithCustomComparator {
			vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
				
				auto comp = [](vector<int>& a, vector<int>& b) {
					return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
				};

				sort(points.begin(), points.end(), comp);
				points.resize(k);
				return points;
			}
		}

		namespace PriorityQueue {
			vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
				auto comp = [](vector<int>& a, vector<int>& b) {
					return a[0] * a[0] + a[1] * a[1] > b[0] * b[0] + b[1] * b[1]; // note that priority queue by default is max queue, so the compartor function is reverse. 
				};

				priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(points.begin(), points.end(), comp);
				vector<vector<int>> result;

				for (int i = 0; i < k; i++) {
					result.push_back(pq.top());
					pq.pop();
				}
				return result;
			}
				
		}

		// sort by yourself
		namespace QuickSelect {

			int squareDistance(vector<int>& a) {
				return a[0] * a[0] + a[1] * a[1];
			}

			int partition(vector<vector<int>>& points, int left, int right) {
				vector<int> pivotPoint = points[left + (right - left) / 2];
				int pv = squareDistance(pivotPoint);

				while (left <= right) {
					if (squareDistance(points[left]) < pv) { 
						left++;
					}
					else {
						swap(points[left], points[right]);
						right--;
					}					
				}
				return left;
			}
	
			vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
				int left = 0;
				int right = points.size() - 1;
				int pivotIndex = points.size();

				while (pivotIndex != k) {
					pivotIndex = partition(points, left, right);
					if (pivotIndex < k) {
						left = pivotIndex;
					}
					else {
						right = pivotIndex;
					}
				}
				return vector<vector<int>>(points.begin(), points.begin() + k);
			}
		}
		

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
