#include "stdafx.h"

//Given a zero-based permutation nums (0-indexed), build an array ans of the same
//length where ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.
//A zero-based permutation nums is an array of distinct integers from 0 to
//nums.length - 1 (inclusive).
// 
//
//Example 1:
//Input: nums = [0,2,1,5,3,4]
//Output: [0,1,2,4,5,3]
//Explanation: The array ans is built as follows: 
//ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]],
//nums[nums[4]], nums[nums[5]]]
//    = [nums[0], nums[2], nums[1], nums[5], nums[3], nums[4]]
//    = [0,1,2,4,5,3]
//
//Example 2:
//Input: nums = [5,0,1,2,3,4]
//Output: [4,5,0,1,2,3]
//Explanation: The array ans is built as follows:
//ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]],
//nums[nums[4]], nums[nums[5]]]
//    = [nums[5], nums[0], nums[1], nums[2], nums[3], nums[4]]
//    = [4,5,0,1,2,3]
// 
//Constraints:
//1 <= nums.length <= 1000
//0 <= nums[i] < nums.length
//The elements in nums are distinct.
// 
//Follow-up: Can you solve it without using an extra space (i.e., O(1) memory)?

namespace Solution2022
{
	namespace BuildArrayfromPermutation
	{
		namespace O1Space {
			//The idea is to store two numbers (nums[i] and nums[nums[i]]) at the same
			//location.
			//The important point to be noted is that all numbers in the array are less than
			//size of the array.
			//
			//Example - Lets say we have two numbers in the array a = 3 , b = 2 and the size
			//of the array is n = 5
			//We can store both 3 and 2 in a as follows:-
			//a = a + b * n
			//To get initial value of a we do a%n
			//To get the value of b we do a/n
			//a = a + b * n = 3 + 2*5 = 13
			//a % n = 13 % 5 = 3
			//a / n = 13 / 5 = 2
			//So we will use this technique to store two numbers in one location.
			//Why is it important that all numbers must be less than size of the array ?
			//Its because when we do
			//    for(int i=0;i<n;i++)
			//    {
			//        nums[i] = nums[i] + n*(nums[nums[i]]);
			//    }
			//There may be cases when we have lost the value of nums[i] as it has already
			//been replaced by nums[nums[i]].
			//So in such cases we need to get the previous values of nums[i] or a
			//This is done by finding nums[nums[i]] % n
			//    for(int i=0;i<n;i++)
			//    {
			//        nums[i] = nums[i] + n*(nums[nums[i]]%n);
			//    }
			//Once we have stored two numbers in each location we can simply divide each
			//number by n to get the desired output.

			vector<int> buildArray(vector<int>& nums) {
				int n = nums.size();
				for (int i = 0; i < n; i++) {
					nums[i] += n * (nums[nums[i]] % n);
				}
				
				for (int i = 0; i < n; i++) {
					nums[i] = nums[i] / n;
				}
				return nums;
			}		
		}
				
		namespace OnSpace {
			vector<int> buildArray(vector<int>& nums) {
				int len = nums.size();
				if (len == 0) { return {}; }

				vector<int> result(len);
				for (int i = 0; i < len; i++) {
					result[i] = nums[nums[i]];
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
