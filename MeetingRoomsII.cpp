#include "stdafx.h"

//Given an array of meeting time intervals intervals where intervals[i] =
//[starti, endi], return the minimum number of conference rooms required.
// 
//
//Example 1:
//Input: intervals = [[0,30],[5,10],[15,20]]
//Output: 2
//
//Example 2:
//Input: intervals = [[7,10],[2,4]]
//Output: 1
// 
//Constraints:
//1 <= intervals.length <= 104
//0 <= starti < endi <= 106

namespace Solution2022
{
	namespace MeetingRoomsII
	{
	    int minMeetingRooms(vector<vector<int>>& intervals) {
			vector<pair<int, int>> meetings;
			for (vector<int>& in : intervals) {
				meetings.push_back({in[0], 1});
				meetings.push_back({ in[1], -1 });
			}
			sort(meetings.begin(), meetings.end());
			
			int room = 0;
			int maxRoom = 0;
			for (pair<int, int>& p : meetings) {
				room += p.second;
				maxRoom = max(maxRoom, room);
			}
			return maxRoom;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
