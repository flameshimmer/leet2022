#include "stdafx.h"

//Given an integer array nums and an integer k, return the number of good
//subarrays of nums.
//A good array is an array where the number of different integers in that array
//is exactly k.
//For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
//A subarray is a contiguous part of an array.
// 
//
//Example 1:
//Input: nums = [1,2,1,2,3], k = 2
//Output: 7
//Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1],
//[1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
//
//Example 2:
//Input: nums = [1,2,1,3,4], k = 3
//Output: 3
//Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3],
//[2,1,3], [1,3,4].
// 
//Constraints:
//1 <= nums.length <= 2 * 104
//1 <= nums[i], k <= nums.length

namespace Solution2022
{
	namespace SubarrayswithKDifferentIntegers
	{
		// use sliding window to solve the problem
		int atMostK(vector<int>& A, int k) {
			int start = 0;
			int result = 0;
			unordered_map<int, int> map;
			for (int end = 0; end < A.size(); end++) {
				if (map[A[end]] == 0) { k--; }
				map[A[end]]++;
				while (k < 0) {
					map[A[start]]--;
					if (map[A[start]] == 0) { k++; }
					start++;
				}
				result += end - start + 1;
				//I can explain ret += end - start + 1 :)
				//
				//suppose initial window[a] then subarrays that ends with this element are[a]-- > 1
				//now we expand our window[a, b] then subarrays that ends with this new element are[b], [a, b] -- > 2
				//now we expand our window[a, b, c] then subarrays that ends with this new element are[c], [b, c], [a, b, c] -- > 3
				//now we expand our window[a, b, c, d] and let suppose this is not valid window so we compress window from left side to make it valid window
				//[b, c, d] then subarrays that ends with this new element are[d], [c, d], [b, c, d] -- > 3
				//
				//You can observe that we are only considering subarrays with new element in it which auto.eliminate the counting of duplicate subarrays that we already considered previously.
				//And surprisingly the number of sub - arrays with this new element in it is equal to the length of current window.
			}
			return result;
		}


		int subarraysWithKDistinct(vector<int>& A, int k) {
			return atMostK(A, k) - atMostK(A, k - 1);
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
