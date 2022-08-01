#include "stdafx.h"

//Given an array of meeting time intervals where intervals[i] = [starti, endi],
//determine if a person could attend all meetings.
// 
//
//Example 1:
//Input: intervals = [[0,30],[5,10],[15,20]]
//Output: false
//
//Example 2:
//Input: intervals = [[7,10],[2,4]]
//Output: true
// 
//Constraints:
//0 <= intervals.length <= 104
//intervals[i].length == 2
//0 <= starti < endi <= 106

namespace Solution2022
{
	namespace MeetingRooms
	{
		namespace HashMap {
			bool canAttendMeetings(vector<vector<int>>& intervals) {
				map<int, int> map;
				for (vector<int>& in : intervals) {
					map[in[0]] ++;
					map[in[1]] --;
				}

				int count = 0;
				for (auto& [k, v] : map) {
					count += v;
					if (count > 1) { return false; }
				}
				return true;
			}
		}

		namespace Sorting {
			bool canAttendMeetings(vector<vector<int>>& intervals) {
				auto comp = [](vector<int>& a, vector<int>& b) {
					if (a[0] == b[0]) { return a[1] < b[1]; }
					return a[0] < b[0];
				};

				sort(intervals.begin(), intervals.end(), comp);

				for (int i = 1; i < intervals.size(); i++) {
					if (intervals[i - 1][1] > intervals[i][0]) { return false; }
				}
				return true;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
