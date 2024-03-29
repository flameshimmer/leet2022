#include "stdafx.h"

//Alice and Bob have a different total number of candies. You are given two
//integer arrays aliceSizes and bobSizes where aliceSizes[i] is the number of
//candies of the ith box of candy that Alice has and bobSizes[j] is the number of
//candies of the jth box of candy that Bob has.
//Since they are friends, they would like to exchange one candy box each so that
//after the exchange, they both have the same total amount of candy. The total
//amount of candy a person has is the sum of the number of candies in each box
//they have.
//Return an integer array answer where answer[0] is the number of candies in the
//box that Alice must exchange, and answer[1] is the number of candies in the box
//that Bob must exchange. If there are multiple answers, you may return any one
//of them. It is guaranteed that at least one answer exists.
// 
//
//Example 1:
//Input: aliceSizes = [1,1], bobSizes = [2,2]
//Output: [1,2]
//
//Example 2:
//Input: aliceSizes = [1,2], bobSizes = [2,3]
//Output: [1,2]
//
//Example 3:
//Input: aliceSizes = [2], bobSizes = [1,3]
//Output: [2,3]
// 
//Constraints:
//1 <= aliceSizes.length, bobSizes.length <= 104
//1 <= aliceSizes[i], bobSizes[j] <= 105
//Alice and Bob have a different total number of candies.
//There will be at least one valid answer for the given input.

namespace Solution2022
{
	namespace FairCandySwap
	{
		vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
			int aSum = accumulate(A.begin(), A.end(), 0);
			int bSum = accumulate(B.begin(), B.end(), 0);
			int sum = (aSum + bSum) / 2;
			int aDiff = sum - aSum;
			unordered_set<int> set(B.begin(), B.end());

			for (int v : A) {
				if (set.find(v + aDiff) != set.end()) { return { v, v + aDiff }; }
			}
			return {};
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
