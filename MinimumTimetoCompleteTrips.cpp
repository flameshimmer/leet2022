#include "stdafx.h"

//You are given an array time where time[i] denotes the time taken by the ith bus
//to complete one trip.
//Each bus can make multiple trips successively; that is, the next trip can start
//immediately after completing the current trip. Also, each bus operates
//independently; that is, the trips of one bus do not influence the trips of any
//other bus.
//You are also given an integer totalTrips, which denotes the number of trips all
//buses should make in total. Return the minimum time required for all buses to
//complete at least totalTrips trips.
// 
//
//Example 1:
//Input: time = [1,2,3], totalTrips = 5
//Output: 3
//Explanation:
//- At time t = 1, the number of trips completed by each bus are [1,0,0]. 
//  The total number of trips completed is 1 + 0 + 0 = 1.
//- At time t = 2, the number of trips completed by each bus are [2,1,0]. 
//  The total number of trips completed is 2 + 1 + 0 = 3.
//- At time t = 3, the number of trips completed by each bus are [3,1,1]. 
//  The total number of trips completed is 3 + 1 + 1 = 5.
//So the minimum time needed for all buses to complete at least 5 trips is 3.
//
//Example 2:
//Input: time = [2], totalTrips = 1
//Output: 2
//Explanation:
//There is only one bus, and it will complete its first trip at t = 2.
//So the minimum time needed to complete 1 trip is 2.
// 
//Constraints:
//1 <= time.length <= 105
//1 <= time[i], totalTrips <= 107

namespace Solution2022
{
	namespace MinimumTimetoCompleteTrips
	{
		long long getTrips(vector<int>& cost, long long time) {
			long long result = 0;
			for (auto c : cost) {
				result += time / (long long)c;
			}
			return result;
		}

	    long long minimumTime(vector<int>& cost, int totalTrips) {
			long long l = 1;
			long long r = 1e14;
			while (l < r) {
				long long mid = l + (r - l) / 2;
				if (getTrips(cost, mid) >= totalTrips) {
					r = mid;
				}else {
					l = mid + 1;
				}
			}
			return l;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
