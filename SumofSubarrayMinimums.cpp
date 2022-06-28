#include "stdafx.h"

//Given an array of integers arr, find the sum of min(b), where b ranges over
//every (contiguous) subarray of arr. Since the answer may be large, return the
//answer modulo 109 + 7.
// 
//
//Example 1:
//Input: arr = [3,1,2,4]
//Output: 17
//Explanation: 
//Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4],
//[3,1,2,4]. 
//Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
//Sum is 17.
//
//Example 2:
//Input: arr = [11,81,94,43,3]
//Output: 444
// 
//Constraints:
//1 <= arr.length <= 3 * 104
//1 <= arr[i] <= 3 * 104

namespace Solution2022
{
	namespace SumofSubarrayMinimums
	{
		int sumSubarrayMins(vector<int>& arr) {
			int len = arr.size();

			vector<int> left(len);
			stack<int> s; //index stack
			for (int i = 0; i < len; i++) {
				while (!s.empty() && arr[s.top()] > arr[i]) {
					s.pop();
				}

				left[i] = s.empty() ? (i + 1) : (i - s.top());
				s.push(i);
			}

			while (!s.empty()) { s.pop(); }

			vector<int> right(len);
			for (int i = len - 1; i >= 0; i--) {
				while (!s.empty() && arr[s.top()] >= arr[i]) { // note that this part is >= instead of >
					s.pop();
				}
				right[i] = s.empty() ? (len - i) : (s.top() - i);
				s.push(i);
			}

			int result = 0;
			int mod = (int)(1e9 + 7);
			for (int i = 0; i < len; i++) {
				long long tmp = (left[i] * right[i]) % mod;
				tmp = (tmp * arr[i]) % mod;
				result = (result + tmp) % mod;
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
