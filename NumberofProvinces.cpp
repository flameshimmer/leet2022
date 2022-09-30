#include "stdafx.h"

//There are n cities. Some of them are connected, while some are not. If city a
//is connected directly with city b, and city b is connected directly with city
//c, then city a is connected indirectly with city c.
//A province is a group of directly or indirectly connected cities and no other
//cities outside of the group.
//You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the
//ith city and the jth city are directly connected, and isConnected[i][j] = 0
//otherwise.
//Return the total number of provinces.
// 
//
//Example 1:
//Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
//Output: 2
//
//Example 2:
//Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
//Output: 3
// 
//Constraints:
//1 <= n <= 200
//n == isConnected.length
//n == isConnected[i].length
//isConnected[i][j] is 1 or 0.
//isConnected[i][i] == 1
//isConnected[i][j] == isConnected[j][i]

namespace Solution2022
{
	namespace NumberofProvinces
	{

		namespace DFS {

			void helper(int i, int len, vector<vector<int>>& isConnected, vector<bool>& visited) {
				visited[i] = true;

				for (int j = 0; j < len; j++) {
					if (i == j) { continue; }
					if (!visited[j] && isConnected[i][j]) {
						helper(j, len, isConnected, visited);
					}
				}
			}

			int findCircleNum(vector<vector<int>>& isConnected) {
				int len = isConnected.size();
				if (len == 0) { return 0; }

				vector<bool> visited(len, false);
				int result = 0;

				for (int i = 0; i < len; i++) {
					if (!visited[i]) {
						result++;
						helper(i, len, isConnected, visited);
					}
				}
				return result;
			}
		}


		namespace UnionFind {

			class UnionFind {
			private:
				vector<int> parent;
			public:
				UnionFind(int sz) {
					parent.resize(sz, -1);
				}

				int find(int x) {
					while (parent[x] != -1) {
						x = parent[x];
					}
					return x;
				}

				void join(int x, int y) {
					int px = find(x);
					int py = find(y);
					if (px != py) {
						parent[py] = px;
					}
				}
			};

			int findCircleNum(vector<vector<int>>& isConnected) {
				int len = isConnected.size();

				UnionFind uf(len);
				int result = len;
				for (int i = 0; i < len; i++) {
					for (int j = 0; j < len; j++) {
						if (isConnected[i][j]) {
							if (uf.find(i) != uf.find(j)) {
								result--;
								uf.join(i, j);
							}
						}
					}
				}
				return result;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
