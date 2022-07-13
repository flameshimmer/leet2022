#include "stdafx.h"

//Given a date string in the form Day Month Year, where:
//Day is in the set {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"}.
//Month is in the set {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug",
//"Sep", "Oct", "Nov", "Dec"}.
//Year is in the range [1900, 2100].
//Convert the date string to the format YYYY-MM-DD, where:
//YYYY denotes the 4 digit year.
//MM denotes the 2 digit month.
//DD denotes the 2 digit day.
// 
//
//Example 1:
//Input: date = "20th Oct 2052"
//Output: "2052-10-20"
//
//Example 2:
//Input: date = "6th Jun 1933"
//Output: "1933-06-06"
//
//Example 3:
//Input: date = "26th May 1960"
//Output: "1960-05-26"
// 
//Constraints:
//The given dates are guaranteed to be valid, so no error handling is necessary.

namespace Solution2022
{
	namespace ReformatDate
	{
		string getMonthName(string m) {
			if (m == "Jan") { return "01"; }
			if (m == "Feb") { return "02"; }
			if (m == "Mar") { return "03"; }
			if (m == "Apr") { return "04"; }
			if (m == "May") { return "05"; }
			if (m == "Jun") { return "06"; }
			if (m == "Jul") { return "07"; }
			if (m == "Aug") { return "08"; }
			if (m == "Sep") { return "09"; }
			if (m == "Oct") { return "10"; }
			if (m == "Nov") { return "11"; }
			if (m == "Dec") { return "12"; }
			return "";
		}

	    string reformatDate(string date) {
			if (date.size() == 13) {
				return date.substr(9, 4) + "-" + getMonthName(date.substr(5, 3)) + "-" + date.substr(0, 2);
			}
			else {
				return date.substr(8, 4) + "-" + getMonthName(date.substr(4, 3)) + "-0" + date.substr(0, 1);
			}
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
