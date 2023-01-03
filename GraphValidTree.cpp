#include "stdafx.h"

//You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n
//and a list of edges where edges[i] = [ai, bi] indicates that there is an
//undirected edge between nodes ai and bi in the graph.
//Return true if the edges of the given graph make up a valid tree, and false
//otherwise.
// 
//
//Example 1:
//Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
//Output: true
//
//Example 2:
//Input: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
//Output: false
// 
//Constraints:
//1 <= n <= 2000
//0 <= edges.length <= 5000
//edges[i].length == 2
//0 <= ai, bi < n
//ai != bi
//There are no self-loops or repeated edges.

namespace Solution2022
{
	namespace GraphValidTree
	{
		namespace UnionFind {
			bool validTree(int n, vector<vector<int>>& edges) {
				vector<int> parent(n);
				iota(parent.begin(), parent.end(), 0);
				for (auto& e : edges) {
					int n1 = e[0];
					int n2 = e[1];
					while (n1 != parent[n1]) { n1 = parent[n1]; }
					while (n2 != parent[n2]) { n2 = parent[n2]; }
					if (n1 == n2) { return false; }
					parent[n1] = n2;
				}
				return edges.size() == n - 1;
			}
		}

		namespace DFS {
			bool hasCycle(int node, int from, vector<vector<int>>& adj, vector<bool>& visited) {
				if (visited[node]) { return true; }
				visited[node] = true;
				for (int child : adj[node]) {
					if (child == from) { continue; } // NOTE: don't forget to check the from!!!!
					if (hasCycle(child, node, adj, visited)) { return true; }
				}
				return false;
			}

			bool validTree(int n, vector<vector<int>>& edges) {
				vector<vector<int>> adj(n);
				for (auto& e : edges) {
					adj[e[0]].push_back(e[1]);
					adj[e[1]].push_back(e[0]);
				}

				vector<bool> visited(n, false);
				if (hasCycle(0, -1, adj, visited)) { return false; }
				for (bool v : visited) { if (!v) { return false; } }
				return true;
			}
		}


		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
