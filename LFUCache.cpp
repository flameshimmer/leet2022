#include "stdafx.h"

//Design and implement a data structure for a Least Frequently Used (LFU) cache.
//Implement the LFUCache class:
//LFUCache(int capacity) Initializes the object with the capacity of the data
//structure.
//int get(int key) Gets the value of the key if the key exists in the cache.
//Otherwise, returns -1.
//void put(int key, int value) Update the value of the key if present, or inserts
//the key if not already present. When the cache reaches its capacity, it should
//invalidate and remove the least frequently used key before inserting a new
//item. For this problem, when there is a tie (i.e., two or more keys with the
//same frequency), the least recently used key would be invalidated.
//To determine the least frequently used key, a use counter is maintained for
//each key in the cache. The key with the smallest use counter is the least
//frequently used key.
//When a key is first inserted into the cache, its use counter is set to 1 (due
//to the put operation). The use counter for a key in the cache is incremented
//either a get or put operation is called on it.
//The functions get and put must each run in O(1) average time complexity.
// 
//
//Example 1:
//Input
//["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get",
//"get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
//Output
//[null, null, null, 1, null, -1, 3, null, -1, 3, 4]
//Explanation
//// cnt(x) = the use counter for key x
//// cache=[] will show the last used order for tiebreakers (leftmost element is 
//most recent)
//LFUCache lfu = new LFUCache(2);
//lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
//lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
//lfu.get(1);      // return 1
//                 // cache=[1,2], cnt(2)=1, cnt(1)=2
//lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest,
//invalidate 2.
//                 // cache=[3,1], cnt(3)=1, cnt(1)=2
//lfu.get(2);      // return -1 (not found)
//lfu.get(3);      // return 3
//                 // cache=[3,1], cnt(3)=2, cnt(1)=2
//lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
//                 // cache=[4,3], cnt(4)=1, cnt(3)=2
//lfu.get(1);      // return -1 (not found)
//lfu.get(3);      // return 3
//                 // cache=[3,4], cnt(4)=1, cnt(3)=3
//lfu.get(4);      // return 4
//                 // cache=[4,3], cnt(4)=2, cnt(3)=3
// 
//Constraints:
//0 <= capacity <= 104
//0 <= key <= 105
//0 <= value <= 109
//At most 2 * 105 calls will be made to get and put.
// 

namespace Solution2022
{
	namespace LFUCache
	{
		class LFUCache {
		private:
			int cap;
			int size;
			int minFreq;
			unordered_map<int, pair<int, int>> map;
			unordered_map<int, list<int>> fm;
			unordered_map<int, list<int>::iterator> itMap;

			void update(int key) {
				int oldFreq = map[key].second;
				auto it = itMap[key];
				fm[oldFreq].erase(it);
				int newFreq = oldFreq + 1;
				fm[newFreq].push_back(key);

				map[key].second = newFreq;

				itMap[key] = prev(fm[newFreq].end());

				while (fm[minFreq].empty()) { minFreq++; }
			}


		public:
			LFUCache(int capacity) {
				cap = capacity;
				size = 0;
				minFreq = 0;
			}

			int get(int key) {
				if (map.find(key) == map.end()) { return -1; }
				update(key);
				return map[key].first;
			}

			void put(int key, int value) {
				if (cap <= 0) { return; }

				if (map.find(key) != map.end()) {
					map[key].first = value;
					update(key);
					return;
				}

				if (size == cap) {
					int keyToRemove = fm[minFreq].front();
					fm[minFreq].pop_front();
					map.erase(keyToRemove);
					itMap.erase(keyToRemove);
				}
				else {
					size++;
				}

				map[key] = { value, 1 };
				minFreq = 1; // NOTE: Don't forget to reset minFreq!!!
				fm[1].push_back(key);
				itMap[key] = prev(fm[1].end());
			}
		};


		/**
		 * Your LFUCache object will be instantiated and called as such:
		 * LFUCache* obj = new LFUCache(capacity);
		 * int param_1 = obj->get(key);
		 * obj->put(key,value);
		 */

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
