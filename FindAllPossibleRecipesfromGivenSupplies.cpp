#include "stdafx.h"

//You have information about n different recipes. You are given a string array
//recipes and a 2D string array ingredients. The ith recipe has the name
//recipes[i], and you can create it if you have all the needed ingredients from
//ingredients[i]. Ingredients to a recipe may need to be created from other
//recipes, i.e., ingredients[i] may contain a string that is in recipes.
//You are also given a string array supplies containing all the ingredients that
//you initially have, and you have an infinite supply of all of them.
//Return a list of all the recipes that you can create. You may return the answer
//in any order.
//
//Note that two recipes may contain each other in their ingredients.
// 
//
//Example 1:
//Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies =
//["yeast","flour","corn"]
//Output: ["bread"]
//Explanation:
//We can create "bread" since we have the ingredients "yeast" and "flour".
//
//Example 2:
//Input: recipes = ["bread","sandwich"], ingredients =
//[["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
//Output: ["bread","sandwich"]
//Explanation:
//We can create "bread" since we have the ingredients "yeast" and "flour".
//We can create "sandwich" since we have the ingredient "meat" and can create the
//ingredient "bread".
//
//Example 3:
//Input: recipes = ["bread","sandwich","burger"], ingredients =
//[["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies =
//["yeast","flour","meat"]
//Output: ["bread","sandwich","burger"]
//Explanation:
//We can create "bread" since we have the ingredients "yeast" and "flour".
//We can create "sandwich" since we have the ingredient "meat" and can create the
//ingredient "bread".
//We can create "burger" since we have the ingredient "meat" and can create the
//ingredients "bread" and "sandwich".
// 
//Constraints:
//n == recipes.length == ingredients.length
//1 <= n <= 100
//1 <= ingredients[i].length, supplies.length <= 100
//1 <= recipes[i].length, ingredients[i][j].length, supplies[k].length <= 10
//recipes[i], ingredients[i][j], and supplies[k] consist only of lowercase
//English letters.
//All the values of recipes and supplies combined are unique.
//Each ingredients[i] does not contain any duplicate values.

namespace Solution2022
{
	namespace FindAllPossibleRecipesfromGivenSupplies
	{
		vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& sup) {
			unordered_set<string> set(sup.begin(), sup.end());
			unordered_map<string, int> indegree;
			for (string& r : rec) { indegree[r] = 0; } // NOTE: don't forget to set indegree to explict 0!

			unordered_map<string, vector<string>> children;
			for (int i = 0; i < rec.size(); i++) {
				string& r = rec[i];
				vector<string>& in = ing[i];
				for (string& item : in) {
					if (set.find(item) == set.end()) {
						children[item].push_back(r);
						indegree[r]++;
					}
				}			
			}

			queue<string> q;
			for (auto& [r, count] : indegree) {
				if (count == 0) { q.push(r); }
			}

			vector<string> result;
			while (!q.empty()) {
				string top = q.front();
				q.pop();

				result.push_back(top);
				for (auto& child : children[top]) {
					indegree[child]--;
					if (indegree[child] == 0) { q.push(child); }
				}			
			}
			return result;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
