#include "stdafx.h"

//In a town, there are n people labeled from 1 to n. There is a rumor that one of
//these people is secretly the town judge.
//If the town judge exists, then:
//The town judge trusts nobody.
//Everybody (except for the town judge) trusts the town judge.
//There is exactly one person that satisfies properties 1 and 2.
//You are given an array trust where trust[i] = [ai, bi] representing that the
//person labeled ai trusts the person labeled bi.
//Return the label of the town judge if the town judge exists and can be
//identified, or return -1 otherwise.
// 
//
//Example 1:
//Input: n = 2, trust = [[1,2]]
//Output: 2
//
//Example 2:
//Input: n = 3, trust = [[1,3],[2,3]]
//Output: 3
//
//Example 3:
//Input: n = 3, trust = [[1,3],[2,3],[3,1]]
//Output: -1
// 
//Constraints:
//1 <= n <= 1000
//0 <= trust.length <= 104
//trust[i].length == 2
//All the pairs of trust are unique.
//ai != bi
//1 <= ai, bi <= n

namespace Solution2022
{
	namespace FindtheTownJudge
	{
		int findJudge(int n, vector<vector<int>>& trust) {
			vector<int> indegree(n + 1, 0);
			vector<int> outdegree(n + 1, 0);

			for (vector<int>& t : trust) {
				indegree[t[1]] ++;
				outdegree[t[0]] --;
			}

			for (int i = 1; i < n + 1; i++) {
				if (outdegree[i] == 0 && indegree[i] == n - 1) { return i; }
			}
			return -1;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
