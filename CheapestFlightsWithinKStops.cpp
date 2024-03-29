#include "stdafx.h"

//There are n cities connected by some number of flights. You are given an array
//flights where flights[i] = [fromi, toi, pricei] indicates that there is a
//flight from city fromi to city toi with cost pricei.
//You are also given three integers src, dst, and k, return the cheapest price
//from src to dst with at most k stops. If there is no such route, return -1.
// 
//
//Example 1:
//Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]],
//src = 0, dst = 3, k = 1
//Output: 700
//Explanation:
//The graph is shown above.
//The optimal path with at most 1 stop from city 0 to 3 is marked in red and has
//cost 100 + 600 = 700.
//
//Note that the path through cities [0,1,2,3] is cheaper but is invalid because
//it uses 2 stops.
//
//Example 2:
//Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
//Output: 200
//Explanation:
//The graph is shown above.
//The optimal path with at most 1 stop from city 0 to 2 is marked in red and has
//cost 100 + 100 = 200.
//
//Example 3:
//Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
//Output: 500
//Explanation:
//The graph is shown above.
//The optimal path with no stops from city 0 to 2 is marked in red and has cost
//500.
// 
//Constraints:
//1 <= n <= 100
//0 <= flights.length <= (n * (n - 1) / 2)
//flights[i].length == 3
//0 <= fromi, toi < n
//fromi != toi
//1 <= pricei <= 104
//There will not be any multiple flights between two cities.
//0 <= src, dst, k < n
//src != dst

namespace Solution2022
{
	namespace CheapestFlightsWithinKStops
	{

		namespace Dijkstra {
			int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
				vector<vector<pair<int, int>>>adj(n);
				for (vector<int>& f : flights) { adj[f[0]].push_back({ f[1], f[2] }); }

				vector<int> stops(n, INT_MAX);
				stops[src] = 0;

				typedef tuple<int, int, int> ti;
				priority_queue<ti, vector<ti>, greater<ti>> pq;
				pq.push({ 0, src, 0 });

				while (!pq.empty()) {
					auto [cost, u, stop] = pq.top();
					pq.pop();

					if (stop > k + 1 || stop > stops[u]) { continue; }
					stops[u] = stop;

					if (u == dst) { return cost; }

					for (auto [v, c] : adj[u]) {
						pq.push({ cost + c, v, stop + 1 });
					}
				}
				return -1;
			}
		}

		namespace BellmanFord {
			int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
				vector<long long> c(n, INT_MAX);
				c[src] = 0;

				for (int i = 0; i <= k; i++) {
					vector<long long> C(c);
					for (auto& f : flights) {
						C[f[1]] = min(C[f[1]], c[f[0]] + f[2]);
					}
					c = C;
				}
				return c[dst] == INT_MAX ? -1 : c[dst];
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
