#include "stdafx.h"

//Given an integer array arr, and an integer target, return the number of tuples
//i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.
//As the answer can be very large, return it modulo 109 + 7.
// 
//
//Example 1:
//Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
//Output: 20
//Explanation: 
//Enumerating by the values (arr[i], arr[j], arr[k]):
//(1, 2, 5) occurs 8 times;
//(1, 3, 4) occurs 8 times;
//(2, 2, 4) occurs 2 times;
//(2, 3, 3) occurs 2 times.
//
//Example 2:
//Input: arr = [1,1,2,2,2,2], target = 5
//Output: 12
//Explanation: 
//arr[i] = 1, arr[j] = arr[k] = 2 occurs 12 times:
//We choose one 1 from [1,1] in 2 ways,
//and two 2s from [2,2,2,2] in 6 ways.
//
//Example 3:
//Input: arr = [2,1,3], target = 6
//Output: 1
//Explanation: (1, 2, 3) occured one time in the array so we return 1.
// 
//Constraints:
//3 <= arr.length <= 3000
//0 <= arr[i] <= 100
//0 <= target <= 300

namespace Solution2022
{
	namespace ThreeSumWithMultiplicity
	{
	    int threeSumMulti(vector<int>& arr, int target) {
			unordered_map<int, long> map;
			for (int v : arr) { map[v]++; }

			long result = 0;
			for (auto& [k1, v1] : map) {
				for (auto& [k2, v2] : map) {
					int k3 = target - k1 - k2;
					if (map.find(k3) == map.end()) { continue; }
					long v3 = map[k3];

					if (k1 == k2 && k2 == k3) {
						result += v1 * (v1 - 1) * (v1 - 2) / 6;
					}
					else if (k1 == k2 && k2 != k3) {
						result += v1 * (v1 - 1) / 2 * v3;
					}
					else if (k1 < k2 && k2 < k3) {
						result += v1 * v2 * v3;
					}				
				}				
			}
			return result % int(1e9 + 7);
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
