#include "stdafx.h"

//Given a sorted integer array arr, two integers k and x, return the k closest
//integers to x in the array. The result should also be sorted in ascending order.
//An integer a is closer to x than an integer b if:
//|a - x| < |b - x|, or
//|a - x| == |b - x| and a < b
// 
//
//Example 1:
//Input: arr = [1,2,3,4,5], k = 4, x = 3
//Output: [1,2,3,4]
//
//Example 2:
//Input: arr = [1,2,3,4,5], k = 4, x = -1
//Output: [1,2,3,4]
// 
//Constraints:
//1 <= k <= arr.length
//1 <= arr.length <= 104
//arr is sorted in ascending order.
//-104 <= arr[i], x <= 104

namespace Solution2022
{
	namespace FindKClosestElements
	{
		/*
				Assume we are taking A[i] ~A[i + k - 1].
					We can binary research i
					We compare the distance between x - A[mid] and A[mid + k] - x

					@vincent_gui listed the following cases :
				Assume A[mid] ~A[mid + k] is sliding window

				case 1: x - A[mid] < A[mid + k] - x, need to move window go left
							------ - x----A[mid]---------------- - A[mid + k]----------

				case 2: x - A[mid] < A[mid + k] - x, need to move window go left again
							------ - A[mid]----x---------------- - A[mid + k]----------

				case 3: x - A[mid] > A[mid + k] - x, need to move window go right
							------ - A[mid]------------------x-- - A[mid + k]----------

				case 4: x - A[mid] > A[mid + k] - x, need to move window go right
							------ - A[mid]-------------------- - A[mid + k]----x------

					If x - A[mid] > A[mid + k] - x,
					it means A[mid + 1] ~A[mid + k] is better than A[mid] ~A[mid + k - 1],
					and we have mid smaller than the right i.
					So assign left = mid + 1.
		*/
		vector<int> findClosestElements(vector<int>& arr, int k, int x) {
			int len = arr.size();
			int start = 0;
			int end = len - k;
			while (start < end) {
				int mid = start + (end - start) / 2;
				if (x - arr[mid] > arr[mid + k] - x) {
					start = mid + 1;
				}
				else {
					end = mid;
				}
			}
			return vector<int>(arr.begin() + start, arry.begin() + start + k);
		}

		namespace NotAsFast {
			vector<int> findClosestElements(vector<int>& arr, int k, int x) {
				vector<int> result;
				int len = arr.size();
				if (len == 0) { return result; }

				int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
				int l = pos - 1;
				int r = pos;
				while (result.size() < k) {
					int disL = INT_MAX;
					int disR = INT_MAX;
					if (l >= 0) { disL = abs(arr[l] - x); }
					if (r < len) { disR = abs(arr[r] - x); }
					if (disL <= disR) { result.insert(result.begin(), arr[l]); l--; }
					else { result.push_back(arr[r]); r++; }
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
