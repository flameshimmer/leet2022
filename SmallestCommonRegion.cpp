#include "stdafx.h"

//You are given some lists of regions where the first region of each list
//includes all other regions in that list.
//Naturally, if a region x contains another region y then x is bigger than y.
//Also, by definition, a region x contains itself.
//Given two regions: region1 and region2, return the smallest region that
//contains both of them.
//If you are given regions r1, r2, and r3 such that r1 includes r3, it is
//guaranteed there is no r2 such that r2 includes r3.
//It is guaranteed the smallest region exists.
// 
//
//Example 1:
//Input:
//regions = [["Earth","North America","South America"],
//["North America","United States","Canada"],
//["United States","New York","Boston"],
//["Canada","Ontario","Quebec"],
//["South America","Brazil"]],
//region1 = "Quebec",
//region2 = "New York"
//Output: "North America"
//
//Example 2:
//Input: regions = [["Earth", "North America", "South America"],["North America",
//"United States", "Canada"],["United States", "New York", "Boston"],["Canada",
//"Ontario", "Quebec"],["South America", "Brazil"]], region1 = "Canada", region2
//= "South America"
//Output: "Earth"
// 
//Constraints:
//2 <= regions.length <= 104
//2 <= regions[i].length <= 20
//1 <= regions[i][j].length, region1.length, region2.length <= 20
//region1 != region2
//regions[i][j], region1, and region2 consist of English letters.

namespace Solution2022
{
	namespace SmallestCommonRegion
	{
/*
	    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
	        
	    }

*/

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
