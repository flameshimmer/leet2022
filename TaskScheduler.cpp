#include "stdafx.h"

//Given a characters array tasks, representing the tasks a CPU needs to do, where
//each letter represents a different task. Tasks could be done in any order. Each
//task is done in one unit of time. For each unit of time, the CPU could complete
//either one task or just be idle.
//However, there is a non-negative integer n that represents the cooldown period
//between two same tasks (the same letter in the array), that is that there must
//be at least n units of time between any two same tasks.
//Return the least number of units of times that the CPU will take to finish all
//the given tasks.
// 
//
//Example 1:
//Input: tasks = ["A","A","A","B","B","B"], n = 2
//Output: 8
//Explanation: 
//A -> B -> idle -> A -> B -> idle -> A -> B
//There is at least 2 units of time between any two same tasks.
//
//Example 2:
//Input: tasks = ["A","A","A","B","B","B"], n = 0
//Output: 6
//Explanation: On this case any permutation of size 6 would work since n = 0.
//["A","A","A","B","B","B"]
//["A","B","A","B","A","B"]
//["B","B","B","A","A","A"]
//...
//And so on.
//
//Example 3:
//Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
//Output: 16
//Explanation: 
//One possible solution is
//A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle ->
//idle -> A
// 
//Constraints:
//1 <= task.length <= 104
//tasks[i] is upper-case English letter.
//The integer n is in the range [0, 100].

namespace Solution2022
{
	namespace TaskScheduler
	{
		//https://www.youtube.com/watch?v=YCD_iYxyXoo
		int leastInterval(vector<char>& tasks, int n) {
			vector<int> count(26, 0);
			for (const char task : tasks) {
				count[task - 'A']++;
			}

			int maxCount = *max_element(count.begin(), count.end());
			int result = (maxCount - 1) * (n + 1);
			for (int v : count) {
				if (v == maxCount) { result++; }
			}
			return max(result, (int)tasks.size());
		}


		namespace Another {
			int leastInterval(vector<char>& tasks, int n) {
				vector<int> count(26);
				for (char c : tasks) {
					count[c - 'A']++;
				}
				sort(count.begin(), count.end());
				int result = 0;

				while (count[25]) {
					int i = 0;
					while (i <= n) {
						if (count[25] == 0) { break; }
						if (25 - i >= 0 && count[25 - i] > 0) { count[25 - i]--; }
						result++;
						i++;
					}
					sort(count.begin(), count.end());
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
