#include "stdafx.h"

//Given an integer n, return the number of prime numbers that are strictly less
//than n.
// 
//
//Example 1:
//Input: n = 10
//Output: 4
//Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
//
//Example 2:
//Input: n = 0
//Output: 0
//
//Example 3:
//Input: n = 1
//Output: 0
// 
//Constraints:
//0 <= n <= 5 * 106

namespace Solution2022
{
	namespace CountPrimes
	{
		// If a number is prime, then its multiplication cannot be prime
	    //https://www.youtube.com/watch?v=Kwo2jkHOyPY
		
		int countPrimes(int n) {
			if (n < 2) { return 0; }

			vector<int> isPrime(n, true);
			isPrime[0] = false;
			isPrime[1] = false;

			for (int i = 2; i < sqrt(n); i++) {
				if (isPrime[i]) {
					for (int j = 2; i * j < n; j++) {
						isPrime[i * j] = false;
					}
				}
			}

			int result = 0;
			for (int i = 0; i < n; i++) {
				if (isPrime[i]) { result++; }
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
