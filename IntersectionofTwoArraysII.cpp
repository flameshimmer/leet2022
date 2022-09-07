#include "stdafx.h"

//Given two integer arrays nums1 and nums2, return an array of their
//intersection. Each element in the result must appear as many times as it shows
//in both arrays and you may return the result in any order.
// 
//
//Example 1:
//Input: nums1 = [1,2,2,1], nums2 = [2,2]
//Output: [2,2]
//
//Example 2:
//Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//Output: [4,9]
//Explanation: [9,4] is also accepted.
// 
//Constraints:
//1 <= nums1.length, nums2.length <= 1000
//0 <= nums1[i], nums2[i] <= 1000
// 
//Follow up:
//What if the given array is already sorted? How would you optimize your
//algorithm?
//What if nums1's size is small compared to nums2's size? Which algorithm is
//better?
//What if elements of nums2 are stored on disk, and the memory is limited such
//that you cannot load all elements into the memory at once?

namespace Solution2022
{
	namespace IntersectionofTwoArraysII
	{
		//If nums1 fits into the memory, we can use Approach 1 which stores all elements of nums1 in the HashMap.Then, we can sequentially loadand process nums2.
		//	If neither nums1 nor nums2 fits into the memory, we split the numeric range into numeric sub - ranges that fit into the memory.
		//	We modify Approach 1 to count only elements which belong to the given numeric sub - range.
		//	We process each numeric sub - ranges one by one, util we process all numeric sub - ranges.
		//	For example :
		//Input constraint :
		//1 <= nums1.length, nums2.length <= 10 ^ 10.
		//	0 <= nums1[i], nums2[i] < 10 ^ 5
		//	Our memory can store up to 1000 elements.
		//	Then we split numeric range into numeric sub - ranges[0...999], [1000...1999], ..., [99000...99999], then call Approach 1 to process 100 numeric sub - ranges.

	    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
			vector<int> result;
			unordered_map<int, int> map;

			for (int v : nums1) { map[v]++; }
			
			for (int v : nums2) {
				if (map[v] > 0) { 
					result.push_back(v); 
					map[v]--;
				}
			}
			return result;
	    }

		namespace BinarySearch {
			int findStartIndex(vector<int>& A, int target) {
				auto it = lower_bound(A.begin(), A.end(), target);
				if (it!= A.end() && *it == target) { return it - A.begin(); }
				else { return -1; }
			}

			int findLen(vector<int>& A, int i) {
				auto it1 = lower_bound(A.begin(), A.end(), A[i]);
				auto it2 = upper_bound(A.begin(), A.end(), A[i]);
				return it2 - it1;
			}

			vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
				vector<int> result;
				if (nums1.size() == 0 || nums2.size() == 0) { return result; }
				sort(nums1.begin(), nums1.end());
				sort(nums2.begin(), nums2.end());
				for (int i = 0; i < nums1.size(); i++) {
					int target = nums1[i];
					int j = findStartIndex(nums2, target);
					if (j == -1) { continue; }

					int len1 = findLen(nums1, i);
					int len2 = findLen(nums2, j);
					for (int k = 0; k < min(len1, len2); k++) {
						result.push_back(target);
					}
					i += len1 - 1;
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
