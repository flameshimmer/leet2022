#include "stdafx.h"

//Given an array of integers arr, you are initially positioned at the first index
//of the array.
//In one step you can jump from index i to index:
//i + 1 where: i + 1 < arr.length.
//i - 1 where: i - 1 >= 0.
//j where: arr[i] == arr[j] and i != j.
//Return the minimum number of steps to reach the last index of the array.
//Notice that you can not jump outside of the array at any time.
// 
//
//Example 1:
//Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
//Output: 3
//Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. 
//Note that
//index 9 is the last index of the array.
//
//Example 2:
//Input: arr = [7]
//Output: 0
//Explanation: Start index is the last index. You do not need to jump.
//
//Example 3:
//Input: arr = [7,6,9,6,9,6,9,7]
//Output: 1
//Explanation: You can jump directly from index 0 to index 7 which is last index
//of the array.
// 
//Constraints:
//1 <= arr.length <= 5 * 104
//-108 <= arr[i] <= 108

namespace Solution2022
{
	namespace JumpGameIV
	{
	    int minJumps(vector<int>& arr) {
			int len = arr.size();
			unordered_map<int, vector<int>> map; // value, list of indexes with this value
			for (int i = 0; i < len; i++) {
				map[arr[i]].push_back(i);
			}

			vector<bool> visited(len, false);
			visited[0] = true;

			queue<int> q; // a queue of indexes
			q.push(0);
			int result = 0;

			while (!q.empty()) {
				int sz = q.size();
				while (sz) {
					sz--;
					int top = q.front();
					q.pop();

					if (top == len - 1) { return result; }
					vector<int>& children = map[arr[top]]; // use reference here to clear out the candidates. 
					children.push_back(top - 1);
					children.push_back(top + 1);
					
					for (auto& i : children) {
						if (i >= 0 && i < len && !visited[i]) {
							q.push(i);
							visited[i] = true;
						}						
					}
					children.clear(); // without this line will exceed timelimit
				}
				result++;
			}
			return 0;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
