#include "stdafx.h"

//Given an array arr of positive integers sorted in a strictly increasing order,
//and an integer k.
//Return the kth positive integer that is missing from this array.
// 
//
//Example 1:
//Input: arr = [2,3,4,7,11], k = 5
//Output: 9
//Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The
//5th missing positive integer is 9.
//
//Example 2:
//Input: arr = [1,2,3,4], k = 2
//Output: 6
//Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing
//positive integer is 6.
// 
//Constraints:
//1 <= arr.length <= 1000
//1 <= arr[i] <= 1000
//1 <= k <= 1000
//arr[i] < arr[j] for 1 <= i < j <= arr.length
// 
//Follow up:
//Could you solve this problem in less than O(n) complexity?

namespace Solution2022
{
	namespace KthMissingPositiveNumber
	{
		namespace OLogN {

			int findKthPositiveAnother(vector<int>& A, int k) {
				int l = 0, r = A.size(), m;
				while (l < r) {
					m = (l + r) / 2;
					if (A[m] - 1 - m < k)
						l = m + 1;
					else
						r = m;
				}
				return l + k;
			}

			int findKthPositive(vector<int>& arr, int k) {
				int len = arr.size();
				int start = 0;
				int end = len - 1;
				while (start <= end) {
					int mid = start + (end - start) / 2;
					if (arr[mid] - mid - 1 < k) {
						start = mid + 1;
					}
					else {
						end = mid - 1;
					}
				}

				//return arr[end] + k - (arr[end] - end - 1);
				//This is arr[end] + (k - (missed number before end))
				return k + end + 1;
			}
		}

		namespace ON {
			int findKthPositive(vector<int>& arr, int k) {
				int last = 0;
				for (int i = 0; i < arr.size(); i++) {
					int diff = arr[i] - last - 1;
					if (diff < k) { k -= diff; }
					else {
						return last + k;
					}
					last = arr[i];
				}
				return last + k;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
