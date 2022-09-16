#include "stdafx.h"

//In this problem, a tree is an undirected graph that is connected and has no
//cycles.
//You are given a graph that started as a tree with n nodes labeled from 1 to n,
//with one additional edge added. The added edge has two different vertices
//chosen from 1 to n, and was not an edge that already existed. The graph is
//represented as an array edges of length n where edges[i] = [ai, bi] indicates
//that there is an edge between nodes ai and bi in the graph.
//Return an edge that can be removed so that the resulting graph is a tree of n
//nodes. If there are multiple answers, return the answer that occurs last in the
//input.
// 
//
//Example 1:
//Input: edges = [[1,2],[1,3],[2,3]]
//Output: [2,3]
//
//Example 2:
//Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
//Output: [1,4]
// 
//Constraints:
//n == edges.length
//3 <= n <= 1000
//edges[i].length == 2
//1 <= ai < bi <= edges.length
//ai != bi
//There are no repeated edges.
//The given graph is connected.

namespace Solution2022
{
	namespace RedundantConnection
	{
		class UnionFind {
		private:
			vector<int> parent;
		public:
			UnionFind(int sz) { parent.resize(sz, -1); }

			int find(int a) {
				while (parent[a] != -1) {
					a = parent[a];
				}
				return a;
			}

			void join(int a, int b) {
				int pa = find(a);
				int pb = find(b);
				parent[pa] = pb;
			}

		};

		vector<int> findRedundantConnection(vector<vector<int>>& edges) {
			int edgeCount = edges.size();
			int nodeCount = edgeCount + 1;
			UnionFind uf(nodeCount);

			for (vector<int>& e : edges) {
				int a = uf.find(e[0]);
				int b = uf.find(e[1]);
				if (a == b) { return e; }
				uf.join(e[0], e[1]);
			}
			return {};
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
