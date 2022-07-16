#include "stdafx.h"

//Given an integer n, return any array containing n unique integers such that
//they add up to 0.
// 
//
//Example 1:
//Input: n = 5
//Output: [-7,-1,1,3,4]
//Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
//
//Example 2:
//Input: n = 3
//Output: [-1,0,1]
//
//Example 3:
//Input: n = 1
//Output: [0]
// 
//Constraints:
//1 <= n <= 1000

namespace Solution2022
{
	namespace FindNUniqueIntegersSumuptoZero
	{
	    vector<int> sumZero(int n) {
			vector<int> result;
			if (n % 2 == 1) {
				result.push_back(0);
				n--;
			}
			
			for (int i = 0; i < n / 2; i++) {
				result.push_back(i + 1);
				result.push_back(-(i + 1));
			}
			return result;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
