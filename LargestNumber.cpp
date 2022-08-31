#include "stdafx.h"

//Given a list of non-negative integers nums, arrange them such that they form
//the largest number and return it.
//Since the result may be very large, so you need to return a string instead of
//an integer.
// 
//
//Example 1:
//Input: nums = [10,2]
//Output: "210"
//
//Example 2:
//Input: nums = [3,30,34,5,9]
//Output: "9534330"
// 
//Constraints:
//1 <= nums.length <= 100
//0 <= nums[i] <= 109

namespace Solution2022
{
	namespace LargestNumber
	{
		string largestNumber(vector<int>& nums) {
			vector<string> strs;
			for (int v : nums) { strs.push_back(to_string(v)); }

			auto comp = [](string& a, string& b) {return a + b > b + a; };
			sort(strs.begin(), strs.end(), comp);

			string result;
			for (string& s : strs) { result += s; }

			if (result[0] == '0') { result = "0"; }
			return result;
		}

		void Main() {
			vector<int> test = { 3,30,34,5,9 };
			print(largestNumber(test));
		}
	}
}
