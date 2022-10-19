#include "stdafx.h"

//You are given an m x n matrix of characters box representing a side-view of a
//box. Each cell of the box is one of the following:
//A stone '#'
//A stationary obstacle '*'
//Empty '.'
//The box is rotated 90 degrees clockwise, causing some of the stones to fall due
//to gravity. Each stone falls down until it lands on an obstacle, another stone,
//or the bottom of the box. Gravity does not affect the obstacles' positions, and
//the inertia from the box's rotation does not affect the stones' horizontal
//positions.
//It is guaranteed that each stone in box rests on an obstacle, another stone, or
//the bottom of the box.
//Return an n x m matrix representing the box after the rotation described above.
// 
//
//Example 1:
//Input: box = [["#",".","#"]]
//Output: [["."],
//         ["#"],
//         ["#"]]
//
//Example 2:
//Input: box = [["#",".","*","."],
//              ["#","#","*","."]]
//Output: [["#","."],
//         ["#","#"],
//         ["*","*"],
//         [".","."]]
//
//Example 3:
//Input: box = [["#","#","*",".","*","."],
//              ["#","#","#","*",".","."],
//              ["#","#","#",".","#","."]]
//Output: [[".","#","#"],
//         [".","#","#"],
//         ["#","#","*"],
//         ["#","*","."],
//         ["#",".","*"],
//         ["#",".","."]]
// 
//Constraints:
//m == box.length
//n == box[i].length
//1 <= m, n <= 500
//box[i][j] is either '#', '*', or '.'.

namespace Solution2022
{
	namespace RotatingtheBox
	{
		// https://www.youtube.com/watch?v=fGVXiDr-djI&t=571s
		vector<vector<char>> rotateTheBox(vector<vector<char>>& box)
		{
			int rowCount = box.size();
			int colCount = box[0].size();

			auto result = vector<vector<char>>(colCount, vector<char>(rowCount, '.'));

			for (int i = 0; i < rowCount; i++)
			{
				for (int j = 0; j < colCount; j++)
				{
					int count = 0;
					int k = j;
					while (k < colCount && box[i][k] != '*')
					{
						if (box[i][k] == '#')
							count++;
						k++;
					}

					int col = rowCount - 1 - i;
					if (k != colCount)
						result[k][col] = '*';

					for (int s = 0; s < count; s++)
						result[k - 1 - s][col] = '#';

					j = k;
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
