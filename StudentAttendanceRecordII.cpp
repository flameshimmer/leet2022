#include "stdafx.h"

//An attendance record for a student can be represented as a string where each
//character signifies whether the student was absent, late, or present on that
//day. The record only contains the following three characters:
//'A': Absent.
//'L': Late.
//'P': Present.
//Any student is eligible for an attendance award if they meet both of the
//following criteria:
//The student was absent ('A') for strictly fewer than 2 days total.
//The student was never late ('L') for 3 or more consecutive days.
//Given an integer n, return the number of possible attendance records of length
//n that make a student eligible for an attendance award. The answer may be very
//large, so return it modulo 109 + 7.
// 
//
//Example 1:
//Input: n = 2
//Output: 8
//Explanation: There are 8 records with length 2 that are eligible for an award:
//"PP", "AP", "PA", "LP", "PL", "AL", "LA", "LL"
//Only "AA" is not eligible because there are 2 absences (there need to be fewer
//than 2).
//
//Example 2:
//Input: n = 1
//Output: 3
//
//Example 3:
//Input: n = 10101
//Output: 183236316
// 
//Constraints:
//1 <= n <= 105

namespace Solution2022
{
	namespace StudentAttendanceRecordII
	{
		// video: https://www.youtube.com/watch?v=O9CymZDAe8M
	    int checkRecord(int n) {
			int dp[2][3] = { 0 }; // index: count of Absense (can be 0, 2), count of Late (can be 0, 1, 2)
			dp[0][0] = 1;
			int MOD = 1000000007;

			for (int i = 0; i < n; i++) {
				int tmpDp[2][3] = { 0 };
				// if today is P
				for (int j = 0; j < 2; j++) {
					for (int k = 0; k < 3; k++) {
						tmpDp[j][0] = (tmpDp[j][0] + dp[j][k]) % MOD;
					}
				}
				// if today is A
				for (int k = 0; k < 3; k++) {
					tmpDp[1][0] = (tmpDp[1][0] + dp[0][k]) % MOD;
				}
				// if today is L
				for (int j = 0; j < 2; j++) {
					for (int k = 1; k < 3; k++) {
						tmpDp[j][k] = (tmpDp[j][k] + dp[j][k - 1]) % MOD;
					}
				}
				std::copy(&tmpDp[0][0], &tmpDp[0][0] + 2 * 3, &dp[0][0]); // deep copy 2 dimensional array
			}

			int result = 0;
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 3; k++) {
					result = (result + dp[j][k]) % MOD;
				}
			}
			return result;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
