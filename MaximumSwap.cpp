#include "stdafx.h"

//You are given an integer num. You can swap two digits at most once to get the
//maximum valued number.
//Return the maximum valued number you can get.
// 
//
//Example 1:
//Input: num = 2736
//Output: 7236
//Explanation: Swap the number 2 and the number 7.
//
//Example 2:
//Input: num = 9973
//Output: 9973
//Explanation: No swap.
// 
//Constraints:
//0 <= num <= 108

namespace Solution2022
{
	namespace MaximumSwap
	{
	    int maximumSwap(int num) {
			string s = to_string(num);
			int len = s.size();
			vector<int> bucket(10, -1);

			for (int i = 0; i < len; i++) {
				bucket[s[i] - '0'] = i;
			}

			for (int i = 0; i < len; i++) {
				for (int j = 9; j > s[i] - '0'; j--) {
					if (bucket[j] > i) {
						swap(s[i], s[bucket[j]]);
						return stoi(s);
					}
				}
			}
			return num;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
