#include "stdafx.h"

//Design a hit counter which counts the number of hits received in the past 5
//minutes (i.e., the past 300 seconds).
//Your system should accept a timestamp parameter (in seconds granularity), and
//you may assume that calls are being made to the system in chronological order
//(i.e., timestamp is monotonically increasing). Several hits may arrive roughly
//at the same time.
//Implement the HitCounter class:
//HitCounter() Initializes the object of the hit counter system.
//void hit(int timestamp) Records a hit that happened at timestamp (in seconds).
//Several hits may happen at the same timestamp.
//int getHits(int timestamp) Returns the number of hits in the past 5 minutes
//from timestamp (i.e., the past 300 seconds).
// 
//
//Example 1:
//Input
//["HitCounter", "hit", "hit", "hit", "getHits", "hit", "getHits", "getHits"]
//[[], [1], [2], [3], [4], [300], [300], [301]]
//Output
//[null, null, null, null, 3, null, 4, 3]
//Explanation
//HitCounter hitCounter = new HitCounter();
//hitCounter.hit(1);       // hit at timestamp 1.
//hitCounter.hit(2);       // hit at timestamp 2.
//hitCounter.hit(3);       // hit at timestamp 3.
//hitCounter.getHits(4);   // get hits at timestamp 4, return 3.
//hitCounter.hit(300);     // hit at timestamp 300.
//hitCounter.getHits(300); // get hits at timestamp 300, return 4.
//hitCounter.getHits(301); // get hits at timestamp 301, return 3.
// 
//Constraints:
//1 <= timestamp <= 2 * 109
//All the calls are being made to the system in chronological order (i.e.,
//timestamp is monotonically increasing).
//At most 300 calls will be made to hit and getHits.
// 
//Follow up: What if the number of hits per second could be huge? Does your
//design scale?

namespace Solution2022
{
	namespace DesignHitCounter
	{
		// O(1) space O(1) time
		namespace UseConstantArray {
			class HitCounter {
			private:
				vector<int> time;
				vector<int> count;
				int total;
			public:
				HitCounter() {
					time.resize(300, 0);
					count.resize(300, 0);
				}

				void hit(int timestamp) {
					int index = timestamp % 300;
					if (time[index] == timestamp) { count[index] ++; }
					else {						
						time[index] = timestamp;
						count[index] = 1;
					}
				}

				int getHits(int timestamp) {
					int result = 0;
					for (int i = 0; i < 300; i++) {
						if (timestamp - time[i] < 300) { result += count[i]; }
					}
					return result;
				}
			};
		}

		namespace UseHashMap {
			class HitCounter {
			private:
				map<int, int> m;
				int totalCount;

				void updateMap(int timestamp) {
					for (auto& [time, count] : m) {
						if (timestamp - time >= 300) {
							totalCount -= count;
							m.erase(time);							
						}
						else {
							break;
						}
					}
				}

			public:
				HitCounter() {
					totalCount = 0;
				}

				void hit(int timestamp) {
					m[timestamp]++;
					totalCount++;
					updateMap(timestamp);
				}

				int getHits(int timestamp) {
					updateMap(timestamp);
					return totalCount;
				}
			};
		
		}


		// Depending on the fact that the events arrive in chronological order
		namespace ONSpaceONTime {
			class HitCounter {
			private:
				queue<int> q;
			public:
				HitCounter() {

				}

				void hit(int timestamp) {
					if (q.empty() || q.back() <= timestamp) {
						q.push(timestamp);
						while (!q.empty() && timestamp - q.front() >= 300) { q.pop(); }
					}
				}

				int getHits(int timestamp) {
					while (!q.empty() && timestamp - q.front() >= 300) { q.pop(); }
					return q.size();
				}
			};
		}


		/**
		 * Your HitCounter object will be instantiated and called as such:
		 * HitCounter* obj = new HitCounter();
		 * obj->hit(timestamp);
		 * int param_2 = obj->getHits(timestamp);
		 */

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
