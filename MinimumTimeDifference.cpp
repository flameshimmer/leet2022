#include "stdafx.h"

//Given a list of 24-hour clock time points in "HH:MM" format, return the minimum
//minutes difference between any two time-points in the list.
// 
//
//Example 1:
//Input: timePoints = ["23:59","00:00"]
//Output: 1
//
//Example 2:
//Input: timePoints = ["00:00","23:59","00:00"]
//Output: 0
// 
//Constraints:
//2 <= timePoints.length <= 2 * 104
//timePoints[i] is in the format "HH:MM".

namespace Solution2022
{
	namespace MinimumTimeDifference
	{
	    int findMinDifference(vector<string>& timePoints) {
			int len = timePoints.size();
			if (len == 0) { return 0; }

			vector<int> times;
			for (string& t : timePoints) {
				int time = stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
				times.push_back(time);
			}
			sort(times.begin(), times.end());
			times.push_back(24 * 60 + times.front()); // Note: this needs 1440 to plus the first value!

			int result = INT_MAX;
			for (int i = 1; i < len + 1; i++) {
				result = min(result, times[i] - times[i - 1]);
			}
			return result;
	    }

		void Main() {
			vector<string> test = {"05:31", "22:08", "00:35"};
			print(findMinDifference(test));
		}
	}
}
