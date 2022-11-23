#include "stdafx.h"

//Write a program to count the number of days between two dates.
//The two dates are given as strings, their format is YYYY-MM-DD as shown in the
//examples.
// 
//
//Example 1:
//Input: date1 = "2019-06-29", date2 = "2019-06-30"
//Output: 1
//
//Example 2:
//Input: date1 = "2020-01-15", date2 = "2019-12-31"
//Output: 15
// 
//Constraints:
//The given dates are valid dates between the years 1971 and 2100.

namespace Solution2022
{
	namespace NumberofDaysBetweenTwoDates
	{

		bool isLeapYear(int year) {
			return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		}

		int daysInMonth(int month, int year) {
			if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) { return 31; }
			else if (month == 2) { return isLeapYear(year) ? 29 : 28; }
			else { return 30; }
		}

		int daysSinceEpoc(string date) {
			int year = stoi(date.substr(0, 4));
			int month = stoi(date.substr(5, 2));
			int day = stoi(date.substr(8, 2));

			int result = day;
			for (int i = 1971; i < year; i++) { result += isLeapYear(i) ? 366 : 365; }
			for (int i = 1; i < month; i++) { result += daysInMonth(i, year); }
			return result;
		}

		int daysBetweenDates(string date1, string date2) {
			return abs(daysSinceEpoc(date1) - daysSinceEpoc(date2));
		}



		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
