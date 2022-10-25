#include "stdafx.h"

//As the ruler of a kingdom, you have an army of wizards at your command.
//You are given a 0-indexed integer array strength, where strength[i] denotes the
//strength of the ith wizard. For a contiguous group of wizards (i.e. the
//wizards' strengths form a subarray of strength), the total strength is defined
//as the product of the following two values:
//The strength of the weakest wizard in the group.
//The total of all the individual strengths of the wizards in the group.
//Return the sum of the total strengths of all contiguous groups of wizards.
//Since the answer may be very large, return it modulo 109 + 7.
//A subarray is a contiguous non-empty sequence of elements within an array.
// 
//
//Example 1:
//Input: strength = [1,3,1,2]
//Output: 44
//Explanation: The following are all the contiguous groups of wizards:
//- [1] from [1,3,1,2] has a total strength of min([1]) * sum([1]) = 1 * 1 = 1
//- [3] from [1,3,1,2] has a total strength of min([3]) * sum([3]) = 3 * 3 = 9
//- [1] from [1,3,1,2] has a total strength of min([1]) * sum([1]) = 1 * 1 = 1
//- [2] from [1,3,1,2] has a total strength of min([2]) * sum([2]) = 2 * 2 = 4
//- [1,3] from [1,3,1,2] has a total strength of min([1,3]) * sum([1,3]) = 1 * 4
//= 4
//- [3,1] from [1,3,1,2] has a total strength of min([3,1]) * sum([3,1]) = 1 * 4
//= 4
//- [1,2] from [1,3,1,2] has a total strength of min([1,2]) * sum([1,2]) = 1 * 3
//= 3
//- [1,3,1] from [1,3,1,2] has a total strength of min([1,3,1]) * sum([1,3,1]) =
//1 * 5 = 5
//- [3,1,2] from [1,3,1,2] has a total strength of min([3,1,2]) * sum([3,1,2]) =
//1 * 6 = 6
//- [1,3,1,2] from [1,3,1,2] has a total strength of min([1,3,1,2]) *
//sum([1,3,1,2]) = 1 * 7 = 7
//The sum of all the total strengths is 1 + 9 + 1 + 4 + 4 + 4 + 3 + 5 + 6 + 7 =
//44.
//
//Example 2:
//Input: strength = [5,4,6]
//Output: 213
//Explanation: The following are all the contiguous groups of wizards: 
//- [5] from [5,4,6] has a total strength of min([5]) * sum([5]) = 5 * 5 = 25
//- [4] from [5,4,6] has a total strength of min([4]) * sum([4]) = 4 * 4 = 16
//- [6] from [5,4,6] has a total strength of min([6]) * sum([6]) = 6 * 6 = 36
//- [5,4] from [5,4,6] has a total strength of min([5,4]) * sum([5,4]) = 4 * 9 =
//36
//- [4,6] from [5,4,6] has a total strength of min([4,6]) * sum([4,6]) = 4 * 10 =
//40
//- [5,4,6] from [5,4,6] has a total strength of min([5,4,6]) * sum([5,4,6]) = 4
//* 15 = 60
//The sum of all the total strengths is 25 + 16 + 36 + 36 + 40 + 60 = 213.
// 
//Constraints:
//1 <= strength.length <= 105
//1 <= strength[i] <= 109

namespace Solution2022
{
	namespace SumofTotalStrengthofWizards
	{
		//https://www.youtube.com/results?search_query=Sum+of+Total+Strength+of+Wizards
		using LL = long long;
		LL M = 1e9 + 7;

		int totalStrength(vector<int>& nums)
		{
			int n = nums.size();
			nums.insert(nums.begin(), 0);

			vector<LL>presum(n + 2, 0);
			for (int i = 1; i <= n; i++)
				presum[i] = (presum[i - 1] + (LL)nums[i]) % M;

			vector<LL>presum2(n + 2, 0);
			for (int i = 1; i <= n; i++)
				presum2[i] = (presum2[i - 1] + (LL)nums[i] * i) % M;

			stack<int>Stack;
			vector<int>nextSmaller(n + 2, n + 1);
			vector<int>prevSmaller(n + 2, 0);
			for (int i = 1; i <= n; i++)
			{
				while (!Stack.empty() && nums[Stack.top()] > nums[i])
				{
					nextSmaller[Stack.top()] = i;
					Stack.pop();
				}
				if (!Stack.empty())
					prevSmaller[i] = Stack.top();
				Stack.push(i);
			}

			LL ret = 0;
			for (int i = 1; i <= n; i++)
			{
				LL a = prevSmaller[i], b = nextSmaller[i];
				LL x = i - a, y = b - i;
				LL first = ((presum2[i - 1] - presum2[a]) - (presum[i - 1] - presum[a]) * a % M + M) % M;
				first = first * y % M;
				LL second = ((presum[b - 1] - presum[i]) * (b - 1 + 1) - (presum2[b - 1] - presum2[i]) + M) % M;
				second = second * x % M;
				LL mid = (LL)nums[i] * x * y % M;

				ret = (ret + (first + second + mid) * nums[i]) % M;
			}

			return ret;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
