#include "stdafx.h"

//You are given an array of variable pairs equations and an array of real numbers
//values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai /
//Bi = values[i]. Each Ai or Bi is a string that represents a single variable.
//You are also given some queries, where queries[j] = [Cj, Dj] represents the jth
//query where you must find the answer for Cj / Dj = ?.
//Return the answers to all queries. If a single answer cannot be determined,
//return -1.0.
//
//Note: The input is always valid. You may assume that evaluating the queries
//will not result in division by zero and that there is no contradiction.
// 
//
//Example 1:
//Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries =
//[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
//Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
//Explanation: 
//Given: a / b = 2.0, b / c = 3.0
//queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
//return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
//
//Example 2:
//Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0],
//queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
//Output: [3.75000,0.40000,5.00000,0.20000]
//
//Example 3:
//Input: equations = [["a","b"]], values = [0.5], queries =
//[["a","b"],["b","a"],["a","c"],["x","y"]]
//Output: [0.50000,2.00000,-1.00000,-1.00000]
// 
//Constraints:
//1 <= equations.length <= 20
//equations[i].length == 2
//1 <= Ai.length, Bi.length <= 5
//values.length == equations.length
//0.0 < values[i] <= 20.0
//1 <= queries.length <= 20
//queries[i].length == 2
//1 <= Cj.length, Dj.length <= 5
//Ai, Bi, Cj, Dj consist of lower case English letters and digits.

namespace Solution2022
{
	namespace EvaluateDivision
	{
		bool helper(string& start, string& end, unordered_map<string, vector<pair<string, double>>>& children, unordered_map<string, bool>& visited, double result, vector<double>& results) {
			if (start == end) {
				results.push_back(result);
				return true;
			}

			bool found = false;
			visited[start] = true;
			for (auto& [child, weight] : children[start]) {
				if (!visited[child]) {
					if (helper(child, end, children, visited, result * weight, results)) { found = true; break; }
				}
			}
			visited[start] = false;
			return found;
		}

		vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
			int len1 = equations.size();
			int len2 = queries.size();
			if (len1 == 0 || len2 == 0) { return {}; }

			vector<double> results;
			unordered_map<string, vector<pair<string, double>>> children;
			unordered_map<string, bool> visited;

			for (int i = 0; i < len1; i++) {
				children[equations[i][0]].push_back({ equations[i][1], values[i] });
				children[equations[i][1]].push_back({ equations[i][0], 1 / values[i] });
				visited[equations[i][0]] = false;
				visited[equations[i][1]] = false;
			}

			for (auto& q : queries) {
				if ((children.find(q[0]) == children.end() || children.find(q[1]) == children.end()) 
					|| !helper(q[0], q[1], children, visited, 1, results)) {
					results.push_back(-1);
				}
			}
			return results;
		}

		void Main() {
			vector<vector<string>> equations = { { "a", "b" }, { "c", "d" } };
			vector<vector<string>> queries = { {"x", "x"} };
			vector<double> values = { 1, 1 };
			calcEquation(equations, values, queries);
		}
	}
}
