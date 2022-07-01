#include "stdafx.h"

//LeetCode company workers use key-cards to unlock office doors. Each time a
//worker uses their key-card, the security system saves the worker's name and the
//time when it was used. The system emits an alert if any worker uses the
//key-card three or more times in a one-hour period.
//You are given a list of strings keyName and keyTime where [keyName[i],
//keyTime[i]] corresponds to a person's name and the time when their key-card was
//used in a single day.
//Access times are given in the 24-hour time format "HH:MM", such as "23:51" and
//"09:49".
//Return a list of unique worker names who received an alert for frequent keycard
//use. Sort the names in ascending order alphabetically.
//Notice that "10:00" - "11:00" is considered to be within a one-hour period,
//while "22:51" - "23:52" is not considered to be within a one-hour period.
// 
//
//Example 1:
//Input: keyName = ["daniel","daniel","daniel","luis","luis","luis","luis"],
//keyTime = ["10:00","10:40","11:00","09:00","11:00","13:00","15:00"]
//Output: ["daniel"]
//Explanation: "daniel" used the keycard 3 times in a one-hour period
//("10:00","10:40", "11:00").
//
//Example 2:
//Input: keyName = ["alice","alice","alice","bob","bob","bob","bob"], keyTime =
//["12:01","12:00","18:00","21:00","21:20","21:30","23:00"]
//Output: ["bob"]
//Explanation: "bob" used the keycard 3 times in a one-hour period
//("21:00","21:20", "21:30").
// 
//Constraints:
//1 <= keyName.length, keyTime.length <= 105
//keyName.length == keyTime.length
//keyTime[i] is in the format "HH:MM".
//[keyName[i], keyTime[i]] is unique.
//1 <= keyName[i].length <= 10
//keyName[i] contains only lowercase English letters.

namespace Solution2022
{
	namespace AlertUsingSameKeyCardThreeorMoreTimesinaOneHourPeriod
	{
	    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
			vector<string> result;
			int len = keyName.size();
			if (len < 3) { return result; }

			map<string, vector<int>> data;

			for (int i = 0; i < len; i++) {
				string timeStr = keyTime[i];
				int timeInMin = ((timeStr[0] - '0') * 10 + (timeStr[1] - '0')) * 60 + ((timeStr[3] - '0') * 10 + (timeStr[4] - '0'));
				// above can also be stoi(timeStr[i].substr(0, 2)) * 60 + stoi(timeStr[i].substr(3))
				data[keyName[i]].push_back(timeInMin);
			}
			
			for (auto& [name, times] : data) {
				sort(times.begin(), times.end());
				for (int i = 0; i < times.size(); i++) {
					int j = std::upper_bound(times.begin(), times.end(), times[i] + 60) - times.begin();
					if (j - i >= 3) {
						result.push_back(name);
						break; 
					}
				}
			}
			return result;
	    }

		void Main() {
			vector<string> names = { "daniel", "daniel", "daniel", "luis", "luis", "luis", "luis" };
			vector<string> times = { "10:00", "10:40", "11:00", "09:00", "11:00", "13:00", "15:00" };
			//print(alertNames(names, times));

			names = { "a", "a", "a", "a", "a", "b", "b", "b", "b", "b", "b" };
			times = {"23:20", "11:09", "23:30", "23:02", "15:28", "22:57", "23:40", "03:43", "21:55", "20:38", "00:19"};
			print(alertNames(names, times));
		}
	}
}
