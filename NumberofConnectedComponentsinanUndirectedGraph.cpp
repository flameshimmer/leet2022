#include "stdafx.h"

//You have a graph of n nodes. You are given an integer n and an array edges
//where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in
//the graph.
//Return the number of connected components in the graph.
// 
//
//Example 1:
//Input: n = 5, edges = [[0,1],[1,2],[3,4]]
//Output: 2
//
//Example 2:
//Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
//Output: 1
// 
//Constraints:
//1 <= n <= 2000
//1 <= edges.length <= 5000
//edges[i].length == 2
//0 <= ai <= bi < n
//ai != bi
//There are no repeated edges.

namespace Solution2022
{
	namespace NumberofConnectedComponentsinanUndirectedGraph
	{
		int find(int x, vector<int>& parent) {
			while (parent[x] != x) {
				x = parent[x];
			}
			return parent[x];
		}

		int countComponents(int n, vector<vector<int>>& edges) {
			if (n < 2) { return n; }
			vector<int> parent(n);
			iota(parent.begin(), parent.end(), 0);
			int result = n;

			for (vector<int>& e : edges) {
				int px = find(e[0], parent);
				int py = find(e[1], parent);
				if (px != py) {
					parent[px] = py;
					result--;
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
