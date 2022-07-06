#include "stdafx.h"

//Given an unsorted integer array nums, return the smallest missing positive
//integer.
//You must implement an algorithm that runs in O(n) time and uses constant extra
//space.
// 
//
//Example 1:
//Input: nums = [1,2,0]
//Output: 3
//
//Example 2:
//Input: nums = [3,4,-1,1]
//Output: 2
//
//Example 3:
//Input: nums = [7,8,9,11,12]
//Output: 1
// 
//Constraints:
//1 <= nums.length <= 5 * 105
//-231 <= nums[i] <= 231 - 1

namespace Solution2022
{
	namespace FirstMissingPositive
	{
		namespace Swap {
			int firstMissingPositive(vector<int>& A) {
				int len = A.size();

				for (int i = 0; i < len; i++) {
					// Need to ensure A[i] - 1 is within the legal range of index!!!
					while (A[i] >= 1 && A[i] <= len && A[i] != A[A[i] - 1]) {
						swap(A[i], A[A[i] - 1]);
					}
				}

				for (int i = 0; i < len; i++) {
					if (A[i] != i + 1) {
						return i + 1;
					}
				}
				return len + 1;
			}
		}

		namespace NegativeNumberMarking {
			int firstMissingPositive(vector<int>& A) {
				int len = A.size();
				if (len == 0) { return 1; }

				bool foundOne = false;
				for (int v : A) {
					if (v == 1) { foundOne = true; break; }
				}

				if (!foundOne) { return 1; }

				for (int i = 0; i < len; i++) {
					if (A[i] <= 0 || A[i] > len) { A[i] = 1; }
				}

				for (int i = 0; i < len; i++) {
					int v = abs(A[i]);
					if (v == len) { A[0] = -abs(A[0]); }
					else { A[v] = -abs(A[v]); }
				}

				for (int i = 1; i < len; i++) {
					if (A[i] > 0) { return i; }
				}
				if (A[0] > 0) { return len; }
				return len + 1;
			}
		}


		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
