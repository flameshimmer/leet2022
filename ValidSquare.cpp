#include "stdafx.h"

//Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true
//if the four points construct a square.
//The coordinate of a point pi is represented as [xi, yi]. The input is not given
//in any order.
//A valid square has four equal sides with positive length and four equal angles
//(90-degree angles).
// 
//
//Example 1:
//Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
//Output: true
//
//Example 2:
//Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
//Output: false
//
//Example 3:
//Input: p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
//Output: true
// 
//Constraints:
//p1.length == p2.length == p3.length == p4.length == 2
//-104 <= xi, yi <= 104

namespace Solution2022
{
	namespace ValidSquare
	{
		int getDistance(vector<int>& p1, vector<int>& p2) {
			return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
		}

		bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
			map<int, int> edgeMap;
			edgeMap[getDistance(p1, p2)]++;
			edgeMap[getDistance(p1, p3)]++;
			edgeMap[getDistance(p1, p4)]++;
			edgeMap[getDistance(p2, p3)]++;
			edgeMap[getDistance(p2, p4)]++;
			edgeMap[getDistance(p3, p4)]++;
			
			if (edgeMap.size() != 2) { return false; } // only have 2 types of edges: side line and diameter line

			vector<pair<int, int>> data(edgeMap.begin(), edgeMap.end());
			if (data[0].second != 4) { return false; }
			return data[1].first = 2 * data[0].first;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
