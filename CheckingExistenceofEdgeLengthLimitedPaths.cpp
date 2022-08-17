#include "stdafx.h"

//An undirected graph of n nodes is defined by edgeList, where edgeList[i] = [ui,
//vi, disi] denotes an edge between nodes ui and vi with distance disi. 
//Note that
//there may be multiple edges between two nodes.
//Given an array queries, where queries[j] = [pj, qj, limitj], your task is to
//determine for each queries[j] whether there is a path between pj and qj such
//that each edge on the path has a distance strictly less than limitj .
//Return a boolean array answer, where answer.length == queries.length and the
//jth value of answer is true if there is a path for queries[j] is true, and
//false otherwise.
// 
//
//Example 1:
//Input: n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries =
//[[0,1,2],[0,2,5]]
//Output: [false,true]
//Explanation: The above figure shows the given graph. 
//Note that there are two
//overlapping edges between 0 and 1 with distances 2 and 16.
//For the first query, between 0 and 1 there is no path where each distance is
//less than 2, thus we return false for this query.
//For the second query, there is a path (0 -> 1 -> 2) of two edges with distances
//less than 5, thus we return true for this query.
//
//Example 2:
//Input: n = 5, edgeList = [[0,1,10],[1,2,5],[2,3,9],[3,4,13]], queries =
//[[0,4,14],[1,4,13]]
//Output: [true,false]
//Exaplanation: The above figure shows the given graph.
// 
//Constraints:
//2 <= n <= 105
//1 <= edgeList.length, queries.length <= 105
//edgeList[i].length == 3
//queries[j].length == 3
//0 <= ui, vi, pj, qj <= n - 1
//ui != vi
//pj != qj
//1 <= disi, limitj <= 109
//There may be multiple edges between two nodes.

namespace Solution2022
{
	namespace CheckingExistenceofEdgeLengthLimitedPaths
	{
		class UnionFind {
		private:
			vector<int> parent;
		public:
			UnionFind(int n) {
				parent.resize(n);
				iota(parent.begin(), parent.end(), 0);
			}

			void join(int a, int b) {
				int pa = find(a);
				int pb = find(b);
				if (pa == pb) { return; }
				parent[pa] = pb;
			}

			int find(int a) {
				while (parent[a] != a) { a = parent[a]; }
				return a;
			}

			bool isConnected(int a, int b) { return find(a) == find(b); }
		};

	    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
			int len = queries.size();
			vector<bool> result(len);

			for (int i = 0; i < len; i++) { queries[i].push_back(i); } // the index 3 is the vector's position in the array

			sort(queries.begin(), queries.end(), [&](auto& a, auto& b) {return a[2] < b[2]; }); // sort queries incrementally by cost
			sort(edgeList.begin(), edgeList.end(), [&](auto& a, auto& b) {return a[2] < b[2]; }); // sort edges incrementally by cost

			UnionFind uf(n);
			int i = 0;
			for (vector<int>& q : queries) {
				int u = q[0];
				int v = q[1];
				int limit = q[2];
				int index = q[3];

				for (; i < edgeList.size() && edgeList[i][2] < limit; i++) {
					uf.join(edgeList[i][0], edgeList[i][1]);
				}

				result[index] = uf.isConnected(u, v);
			}
			return result;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
