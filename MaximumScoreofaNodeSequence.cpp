#include "stdafx.h"

//There is an undirected graph with n nodes, numbered from 0 to n - 1.
//You are given a 0-indexed integer array scores of length n where scores[i]
//denotes the score of node i. You are also given a 2D integer array edges where
//edges[i] = [ai, bi] denotes that there exists an undirected edge connecting
//nodes ai and bi.
//A node sequence is valid if it meets the following conditions:
//There is an edge connecting every pair of adjacent nodes in the sequence.
//No node appears more than once in the sequence.
//The score of a node sequence is defined as the sum of the scores of the nodes
//in the sequence.
//Return the maximum score of a valid node sequence with a length of 4. If no
//such sequence exists, return -1.
// 
//
//Example 1:
//Input: scores = [5,2,9,8,4], edges = [[0,1],[1,2],[2,3],[0,2],[1,3],[2,4]]
//Output: 24
//Explanation: The figure above shows the graph and the chosen node sequence
//[0,1,2,3].
//The score of the node sequence is 5 + 2 + 9 + 8 = 24.
//It can be shown that no other node sequence has a score of more than 24.
//
//Note that the sequences [3,1,2,0] and [1,0,2,3] are also valid and have a score
//of 24.
//The sequence [0,3,2,4] is not valid since no edge connects nodes 0 and 3.
//
//Example 2:
//Input: scores = [9,20,6,4,11,12], edges = [[0,3],[5,3],[2,4],[1,3]]
//Output: -1
//Explanation: The figure above shows the graph.
//There are no valid node sequences of length 4, so we return -1.
// 
//Constraints:
//n == scores.length
//4 <= n <= 5 * 104
//1 <= scores[i] <= 108
//0 <= edges.length <= 5 * 104
//edges[i].length == 2
//0 <= ai, bi <= n - 1
//ai != bi
//There are no duplicate edges.

namespace Solution2022
{
	namespace MaximumScoreofaNodeSequence
	{
		//https://www.youtube.com/watch?v=7eVhDmozOTE
		int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
			// For each node, maintain a set of top 3 largest score neibours. 
			vector<set<pair<int, int>>> top3(scores.size(), set<pair<int, int>>()); //nodeIndex, {score, neighbore index} of top 3 largest
			for (vector<int>& e : edges) {
				int end0 = e[0];
				int end1 = e[1];

				set<pair<int, int>>& set0 = top3[end0];
				set<pair<int, int>>& set1 = top3[end1];

				set0.insert({ scores[end1], end1 }); // inserting the neighbours, not themselves!!
				set1.insert({ scores[end0], end0 });
				if (set0.size() > 3) { set0.erase(set0.begin()); }
				if (set1.size() > 3) { set1.erase(set1.begin()); }
			}
			// Since the problem only wants to know the 4 node sum, we can iterate any connected two nodes A and B.
			// Once we confirmed A connects to B,  A<--->B, then just look at A's largetest neighbour i and B's largest neighbour j, 
			// while ensurinb i and B are not the same, and j and A are not the same, and A and B are not the same. 
			int result = -1;
			for (vector<int>& e : edges) {
				int end0 = e[0];
				int end1 = e[1];
				for (auto [score0, n0] : top3[end0]) {
					for (auto [score1, n1] : top3[end1]) {
						if (n0 != n1 && n0 != end1 && n1 != end0) { // ensure the 4 points are not the same. 
							result = max(result, score0 + score1 + scores[end0] + scores[end1]);
						}
					}
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
