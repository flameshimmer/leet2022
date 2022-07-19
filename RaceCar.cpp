#include "stdafx.h"

//Your car starts at position 0 and speed +1 on an infinite number line. Your car
//can go into negative positions. Your car drives automatically according to a
//sequence of instructions 'A' (accelerate) and 'R' (reverse):
//When you get an instruction 'A', your car does the following:
//position += speed
//speed *= 2
//When you get an instruction 'R', your car does the following:
//If your speed is positive then speed = -1
//otherwise speed = 1
//Your position stays the same.
//For example, after commands "AAR", your car goes to positions 0 --> 1 --> 3 -->
//3, and your speed goes to 1 --> 2 --> 4 --> -1.
//Given a target position target, return the length of the shortest sequence of
//instructions to get there.
// 
//
//Example 1:
//Input: target = 3
//Output: 2
//Explanation: 
//The shortest instruction sequence is "AA".
//Your position goes from 0 --> 1 --> 3.
//
//Example 2:
//Input: target = 6
//Output: 5
//Explanation: 
//The shortest instruction sequence is "AAARA".
//Your position goes from 0 --> 1 --> 3 --> 7 --> 7 --> 6.
// 
//Constraints:
//1 <= target <= 104

namespace Solution2022
{
	namespace RaceCar
	{
		namespace BFS {

			int racecar(int target) {
				queue<pair<int, int>> q; // {pos, speed}
				q.push({ 0, 1 });
				unordered_set<string> v;
				v.insert("0_1");
				v.insert("0,-1");

				int result = 0;
				while (!q.empty()) {
					int sz = q.size();
					while (sz) {
						sz--;

						auto [pos, speed] = q.front();
						q.pop();

						// option 1: accelarate
						int pos1 = pos + speed;
						int speed1 = speed * 2;
						if (pos1 == target) { return result + 1; }
						if (pos1 > 0 && pos1 < 2 * target) {
							q.push({ pos1, speed1 });
						}

						// option 2: reverse
						int speed2 = speed > 0 ? -1 : 1;
						string key = to_string(pos) + "_" + to_string(speed2);
						if (v.find(key) == v.end()) {
							q.push({ pos, speed2 });
							v.insert(key);
						}
					}
					result++;
				}
				return -1;
			}


		}

		namespace DP {
			// explaination: https://www.youtube.com/watch?v=HzlEkUt2TYs
			vector<int> dp;

			int helper(int target) {
				if (dp[target] > 0) return dp[target];
				int n = ceil(log2(target + 1));
				// AA...A (nA) best case
				if (1 << n == target + 1) return dp[target] = n;

				// AA...AR (nA + 1R) + helper(left) 
				dp[target] = n + 1 + helper((1 << n) - 1 - target);
				
				for (int m = 0; m < n - 1; ++m) {
					int cur = (1 << (n - 1)) - (1 << m);
					//AA...ARA...AR (n-1A + 1R + mA + 1R) + helper(left) 
					dp[target] = min(dp[target], n + m + 1 + helper(target - cur));
				}
				return dp[target];
			}

			int racecar(int target) {
				dp.resize(target + 1, 0);
				return helper(target);
			}
		}

		void Main() {
			print(BFS::racecar(4));
		}
	}
}
