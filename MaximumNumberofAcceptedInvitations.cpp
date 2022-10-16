#include "stdafx.h"

//There are boyCount boys and girlCount girls in a class attending an upcoming party.
//You are given an boyCount x girlCount integer matrix grid, where grid[i][j] equals 0 or 1. If
//grid[i][j] == 1, then that means the ith boy can invite the jth girl to the
//party. A boy can invite at most one girl, and a girl can accept at most one
//invitation from a boy.
//Return the maximum possible number of accepted invitations.
// 
//
//Example 1:
//Input: grid = [[1,1,1],
//               [1,0,1],
//               [0,0,1]]
//Output: 3
//Explanation: The invitations are sent as follows:
//- The 1st boy invites the 2nd girl.
//- The 2nd boy invites the 1st girl.
//- The 3rd boy invites the 3rd girl.
//
//Example 2:
//Input: grid = [[1,0,1,0],
//               [1,0,0,0],
//               [0,0,1,0],
//               [1,1,1,0]]
//Output: 3
//Explanation: The invitations are sent as follows:
//-The 1st boy invites the 3rd girl.
//-The 2nd boy invites the 1st girl.
//-The 3rd boy invites no one.
//-The 4th boy invites the 2nd girl.
// 
//Constraints:
//grid.length == boyCount
//grid[i].length == girlCount
//1 <= boyCount, girlCount <= 200
//grid[i][j] is either 0 or 1.

namespace Solution2022
{
	namespace MaximumNumberofAcceptedInvitations
	{
		bool helper(const vector<vector<int>>& grid, int boy, vector<bool>& visited, vector<int>& girls) {
			// 对于当前男孩，循环所有女孩
			for (int girl = 0; girl < girls.size(); girl++) {
				// 如果不可能请到，或者之前这个男孩已经考虑过这个女孩了，就提前退出
				if (grid[boy][girl] == 0 || visited[girl]) { continue; }

				visited[girl] = true;
				// 如果当前女孩没有邀约，或者女孩有邀约了，但是可以叫原来的邀约对象另找，就可以约这个女孩
				// 注意这时候给原来男孩的是当前男孩的visited记录，让原来的男孩只看其他之前男孩没考虑过的对象
				if (girls[girl] == -1 || helper(grid, girls[girl], visited, girls)) {
					girls[girl] = boy;
					return true;
				}
			}
			return false;
		}

	    int maximumInvitations(vector<vector<int>>& grid) {
			int boyCount = grid.size();
			int girlCount = grid[0].size();
			vector<int> girls(girlCount, -1);

			int matches = 0;

			for (int boy = 0; boy < boyCount; boy++) {
				// visited 对每个男孩都会重新reset，记录的是对这个男孩，有没有考虑过某个女孩
				vector<bool> visited(girlCount, false);
				if (helper(grid, boy, visited, girls)) {
					matches++;
				}
			}
			return matches;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
