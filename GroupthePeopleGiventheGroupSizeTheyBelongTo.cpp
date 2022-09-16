#include "stdafx.h"

//There are n people that are split into some unknown number of groups. Each
//person is labeled with a unique ID from 0 to n - 1.
//You are given an integer array groupSizes, where groupSizes[i] is the size of
//the group that person i is in. For example, if groupSizes[1] = 3, then person 1
//must be in a group of size 3.
//Return a list of groups such that each person i is in a group of size
//groupSizes[i].
//Each person should appear in exactly one group, and every person must be in a
//group. If there are multiple answers, return any of them. It is guaranteed that
//there will be at least one valid solution for the given input.
// 
//
//Example 1:
//Input: groupSizes = [3,3,3,3,3,1,3]
//Output: [[5],[0,1,2],[3,4,6]]
//Explanation: 
//The first group is [5]. The size is 1, and groupSizes[5] = 1.
//The second group is [0,1,2]. The size is 3, and groupSizes[0] = groupSizes[1] =
//groupSizes[2] = 3.
//The third group is [3,4,6]. The size is 3, and groupSizes[3] = groupSizes[4] =
//groupSizes[6] = 3.
//Other possible solutions are [[2,1,6],[5],[0,4,3]] and [[5],[0,6,2],[4,3,1]].
//
//Example 2:
//Input: groupSizes = [2,1,3,3,3,2]
//Output: [[1],[0,5],[2,3,4]]
// 
//Constraints:
//groupSizes.length == n
//1 <= n <= 500
//1 <= groupSizes[i] <= n

namespace Solution2022
{
	namespace GroupthePeopleGiventheGroupSizeTheyBelongTo
	{
		namespace Map {

			vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
				vector<vector<int>> result;
				int len = groupSizes.size();
				if (len == 0) { return result; }

				unordered_map<int, vector<int>> map;
				for (int i = 0; i < len; i++) {
					int v = groupSizes[i];
					map[v].push_back(i);
					if (map[v].size() == v) {
						result.push_back(map[v]);
						map[v] = {};
					}
				}
				return result;
			}

		}

		namespace MultiMap {
			vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
				vector<vector<int>> result;
				int len = groupSizes.size();
				if (len == 0) { return result; }

				multimap<int, vector<int>> map;
				for (int i = 0; i < groupSizes.size(); i++) {
					int v = groupSizes[i];
					if (map.find(v) == map.end() || prev(map.equal_range(v).second)->second.size() >= v) {
						map.insert({ v, {i} });
					}
					else {
						prev(map.equal_range(v).second)->second.push_back(i);
					}
				}
				for (auto& [k, v] : map) {
					result.push_back(v);
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
