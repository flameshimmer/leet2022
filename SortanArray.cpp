#include "stdafx.h"

//Given an array of integers nums, sort the array in ascending order.
// You must solve the problem without using any built-in functions in O(nlog(n))
// time complexity and with the smallest space complexity possible.
//
//Example 1:
//Input: nums = [5,2,3,1]
//Output: [1,2,3,5]
//
//Example 2:
//Input: nums = [5,1,1,2,0,0]
//Output: [0,0,1,1,2,5]
// 
//Constraints:
//1 <= nums.length <= 5 * 104
//-5 * 104 <= nums[i] <= 5 * 104

namespace Solution2022
{
	namespace SortanArray
	{
		namespace MergeSort {

			void merge(vector<int>& A, int l, int m, int r) {
				vector<int> tmp(r - l + 1);
				int i = l;
				int j = m + 1;
				int k = 0;
				while (i <= m && j <= r) {
					if (A[i] <= A[j]) {
						tmp[k] = A[i];
						i++;
					}
					else {
						tmp[k] = A[j];
						j++;
					}
					k++;
				}
				while (i <= m) { tmp[k] = A[i]; i++; k++; }
				while (j <= r) { tmp[k] = A[j]; j++; k++; }
				for (int i = 0; i < k; i++) { A[l + i] = tmp[i]; }
			}


			void mergeSort(vector<int>& nums, int l, int r) {
				if (l >= r) { return; }
				int mid = l + (r - l) / 2;
				mergeSort(nums, l, mid);
				mergeSort(nums, mid + 1, r);
				merge(nums, l, mid, r);
			}

			vector<int> sortArray(vector<int>& nums) {
				int len = nums.size();
				if (len < 2) { return nums; }
				mergeSort(nums, 0, len - 1);
				return nums;
			}
		}

		namespace QuickSort {
			void quickSort(vector<int>& A, int start, int end) {
				if (start >= end) { return; }

				int pivot = start + (end - start) / 2;
				int pv = A[pivot];
				swap(A[pivot], A[end]);

				int i = start;
				for (int j = start; j < end; j++) {
					if (A[j] <= pv) {
						swap(A[j], A[i]);
						i++;
					}
				}
				swap(A[i], A[end]);

				quickSort(A, start, i - 1); // NOTE: this is i, not pivot!!! Since pivot index has changed
				quickSort(A, i + 1, end);
			}

			vector<int> sortArray(vector<int>& nums) {
				int len = nums.size();
				if (len < 2) { return nums; }
				quickSort(nums, 0, len - 1);
				return nums;
			}
		}
		void Main() {
			vector<int> test = { 5,1,1,2,0,0 };
			//print(sortArray(test));
		}
	}
}
