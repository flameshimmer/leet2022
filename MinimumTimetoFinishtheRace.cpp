#include "stdafx.h"

//You are given a 0-indexed 2D integer array tires where tires[i] = [fi, ri]
//indicates that the ith tire can finish its xth successive lap in fi * ri(x-1)
//seconds.
//For example, if fi = 3 and ri = 2, then the tire would finish its 1st lap in 3
//seconds, its 2nd lap in 3 * 2 = 6 seconds, its 3rd lap in 3 * 2 * 2 = 12 seconds,
//etc.
//You are also given an integer changeTime and an integer numLaps.
//The race consists of numLaps laps and you may start the race with any tire. You
//have an unlimited supply of each tire and after every lap, you may change to
//any given tire (including the current tire type) if you wait changeTime seconds.
//Return the minimum time to finish the race.
// 
//
//Example 1:
//Input: tires = [[2,3],[3,4]], changeTime = 5, numLaps = 4
//Output: 21
//Explanation: 
//Lap 1: Start with tire 0 and finish the lap in 2 seconds.
//Lap 2: Continue with tire 0 and finish the lap in 2 * 3 = 6 seconds.
//Lap 3: Change tires to a new tire 0 for 5 seconds and then finish the lap in
//another 2 seconds.
//Lap 4: Continue with tire 0 and finish the lap in 2 * 3 = 6 seconds.
//Total time = 2 + 6 + 5 + 2 + 6 = 21 seconds.
//The minimum time to complete the race is 21 seconds.
//
//Example 2:
//Input: tires = [[1,10],[2,2],[3,4]], changeTime = 6, numLaps = 5
//Output: 25
//Explanation: 
//Lap 1: Start with tire 1 and finish the lap in 2 seconds.
//Lap 2: Continue with tire 1 and finish the lap in 2 * 2 = 4 seconds.
//Lap 3: Change tires to a new tire 1 for 6 seconds and then finish the lap in
//another 2 seconds.
//Lap 4: Continue with tire 1 and finish the lap in 2 * 2 = 4 seconds.
//Lap 5: Change tires to tire 0 for 6 seconds then finish the lap in another 1
//second.
//Total time = 2 + 4 + 6 + 2 + 4 + 6 + 1 = 25 seconds.
//The minimum time to complete the race is 25 seconds. 
// 
//Constraints:
//1 <= tires.length <= 105
//tires[i].length == 2
//1 <= fi, changeTime <= 105
//2 <= ri <= 105
//1 <= numLaps <= 1000

namespace Solution2022
{
//Intuition: We have a lot of tires, but the number of laps is limited to 1000.
//
//We first compute how long it takes to finish n laps with each tire without changing it.
//
//Optimization : it only makes sense to use a tire while the lap time is less than fi + changeTime.
//
//We track the best time to complete i laps, across all tires, in the best array.
//
//After that, we run DFS, memoising it by the number of laps to race(dp) :
//
//For remaining laps, we find the best time by trying to race i laps, change a tire, and recurse on laps - i remaining laps.
//For i laps, we pick the best time to finish those laps.
	
	namespace MinimumTimetoFinishtheRace
	{	
		long long  dp[1001] = {};
		long long  best[1001] = {};
		int maxLapsBeforeHavingToChangingTire = 0;

		int dfs(int laps, int changeTime) {
			if (laps == 0) { return -changeTime; }
			if (dp[laps] != 0) { return dp[laps]; }

			dp[laps] = INT_MAX;
			for (int i = 1; i <= min(laps, maxLapsBeforeHavingToChangingTire); i++) { // Note where does i start and ends!!!
				dp[laps] = min(dp[laps], best[i] + changeTime + dfs(laps - i, changeTime));
			}
			return dp[laps];
		}

	    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {			
			for (auto& t : tires) {				
				long long lapTime = t[0];
				long long sumTime = t[0];

				for (int lap = 1; lap <= numLaps && lapTime < t[0] + changeTime; lap++) {
					maxLapsBeforeHavingToChangingTire = max(maxLapsBeforeHavingToChangingTire, lap);
					if (best[lap] == 0 || best[lap] > sumTime) {
						best[lap] = sumTime;
					}
					lapTime *= t[1];
					sumTime += lapTime;
				}
			}
			return dfs(numLaps, changeTime);
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
