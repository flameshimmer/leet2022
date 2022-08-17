#include "stdafx.h"

//Your music player contains n different songs. You want to listen to goal songs
//(not necessarily different) during your trip. To avoid boredom, you will create
//a playlist so that:
//Every song is played at least once.
//A song can only be played again only if k other songs have been played.
//Given n, goal, and k, return the number of possible playlists that you can
//create. Since the answer can be very large, return it modulo 109 + 7.
// 
//
//Example 1:
//Input: n = 3, goal = 3, k = 1
//Output: 6
//Explanation: There are 6 possible playlists: [1, 2, 3], [1, 3, 2], [2, 1, 3],
//[2, 3, 1], [3, 1, 2], and [3, 2, 1].
//
//Example 2:
//Input: n = 2, goal = 3, k = 0
//Output: 6
//Explanation: There are 6 possible playlists: [1, 1, 2], [1, 2, 1], [2, 1, 1],
//[2, 2, 1], [2, 1, 2], and [1, 2, 2].
//
//Example 3:
//Input: n = 2, goal = 3, k = 1
//Output: 2
//Explanation: There are 2 possible playlists: [1, 2, 1] and [2, 1, 2].
// 
//Constraints:
//0 <= k < n <= goal <= 100

namespace Solution2022
{
	namespace NumberofMusicPlaylists
	{
		//dp[i][j] denotes the solution of i songs with j different songs.So the final answer should be dp[L][N]

		//Think one step before the last one, there are only cases for the answer of dp[i][j]
		//case 1 (the last added one is new song) : listen i - 1 songs with j - 1 different songs, then the last one is definitely new song with the choices of N - (j - 1).
		//Case 2 (the last added one is old song) : listen i - 1 songs with j different songs, then the last one is definitely old song with the choices of j
		//if without the constraint of K, the status equation will be
		//	dp[i][j] = dp[i - 1][j - 1] * (N - (j - 1)) + dp[i - 1][j] * j

		//If with the constaint of K, there are also two cases
		//Case 1 : no changes since the last added one is new song.Hence, there is no conflict
		//Case 2 : now we don't have choices of j for the last added old song. It should be updated j - k because k songs can't be chosed from j - 1 to j - k.
		//	However, if j <= K, this case will be 0 because only after choosing K different other songs, old song can be chosen.

		//if (j > k)
		//	dp[i][j] = dp[i - 1][j - 1] * (N - (j - 1)) + dp[i - 1][j] * (j - k)
		//else
		//	dp[i][j] = dp[i - 1][j - 1] * (N - (j - 1))

	    int numMusicPlaylists(int n, int goal, int k) {
			int mod = 1e9 + 7;
			vector<vector<long long>> dp(goal + 1, vector<long long>(n + 1, 0));
			dp[0][0] = 1;

			for (int i = 1; i <= goal; i++) {
				for (int j = 1; j <= n; j++) {
					dp[i][j] = dp[i - 1][j - 1] * (n - (j - 1)) % mod;
					if (j > k) {
						dp[i][j] = (dp[i][j] + (dp[i - 1][j] * (j - k)) % mod) % mod;
					}
				}
			}
			return (int)dp[goal][n];
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
