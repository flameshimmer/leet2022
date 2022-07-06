#include "stdafx.h"

//Given an integer array nums and an integer k, return the k most frequent
//elements. You may return the answer in any order.
// 
//
//Example 1:
//Input: nums = [1,1,1,2,2,3], k = 2
//Output: [1,2]
//
//Example 2:
//Input: nums = [1], k = 1
//Output: [1]
// 
//Constraints:
//1 <= nums.length <= 105
//k is in the range [1, the number of unique elements in the array].
//It is guaranteed that the answer is unique.
// 
//Follow up: Your algorithm's time complexity must be better than O(n log n),
//where n is the array's size.

namespace Solution2022
{
	namespace TopKFrequentElements
	{
		namespace BucketSort {

			vector<int> topKFrequent(vector<int>& nums, int k) {
				int len = nums.size();
				if (len == 0) { return {}; }

				unordered_map<int, int> map;
				for (int v : nums) { map[v]++; }

				vector<vector<int>> freq(len + 1);
				for (auto& [key, val] : map) {
					freq[val].push_back(key);
				}

				vector<int> result;
				for (int i = len; i > 0 && k > 0; i--) {
					int count = min(k, (int)freq[i].size());
					result.insert(result.end(), freq[i].begin(), freq[i].begin() + count);
					k -= count;
				}
				return result;
			}

		}


		namespace PriorityQueue {
			vector<int> topKFrequent(vector<int>& nums, int k) {
				unordered_map<int, int> map;
				for (int v : nums) { map[v]++; }

				auto comp = [](pair<int, int>& a, pair<int, int>& b) {
					return a.second > b.second;
				};

				priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);

				for (auto& p : map) {
					pq.push(p);
					if (pq.size() > k) { pq.pop(); }
				}

				vector<int> result;
				while (!pq.empty()) {
					result.push_back(pq.top().first);
					pq.pop();
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
