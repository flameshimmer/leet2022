﻿#include "stdafx.h"

//Given two sparse matrices mat1 of size m x k and mat2 of size k x n, return the
//result of mat1 x mat2. You may assume that multiplication is always possible.
// 
//
//Example1:
//Input:
//A = [
//  [ 1, 0, 0],
//  [-1, 0, 3]
//]
//B = [
//  [ 7, 0, 0 ],
//  [ 0, 0, 0 ],
//  [ 0, 0, 1 ]
//]
//Output:
//     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
//AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
//  
//
//Example 2:
//Input: mat1 = [[0]], mat2 = [[0]]
//Output: [[0]]
// 
//Constraints:
//m == mat1.length
//k == mat1[i].length == mat2.length
//n == mat2[i].length
//1 <= m, n, k <= 100
//-100 <= mat1[i][j], mat2[i][j] <= 100

namespace Solution2022
{
	namespace SparseMatrixMultiplication
	{
		/*
		面试官先问每个vector很大，不能在内存中存下怎么办，我说只需存下非零元素和他们的下标就行，然后问面试官是否可用预处理后的
		这两个vector非零元素的index和value作为输入，面试官同意后写完O(M*N)的代码(输入未排序，只能一个个找)，MN分别是两个vector长度。

		又问这两个输入如果是根据下标排序好的怎么办，是否可以同时利用两个输入都是排序好这一个特性，最后写出了O(M + N)的双指针方法，
		每次移动pair里index0较小的指针，如果相等则进行计算，再移动两个指针。

		又问如果一个向量比另一个长很多怎么办，我说可以遍历长度短的那一个，然后用二分搜索的方法在另一个vector中找index相同的那个元素，
		相乘加入到结果中，这样的话复杂度就是O(M*logN)。

		又问如果两个数组一样长，且一会sparse一会dense怎么办。他说你可以在two pointer的扫描中内置一个切换二分搜索的机制。
		看差值我说过，设计个反馈我说过，他说不好。他期待的解答是，two pointers找到下个位置需要m次比较，而直接二分搜需要log(n)次比较。
		那么在你用two pointers方法移动log(n)次以后，就可以果断切换成二分搜索模式了。

		Binary search如果找到了一个元素index，那就用这次的index作为下次binary search的开始。可以节约掉之前的东西，不用search了。
		然后问，如果找不到呢，如何优化。说如果找不到，也返回上次search结束的index，然后下次接着search。
		就是上一次找到了，就用这个index继续找这次的；如果找不到，也有一个ending index，就用那个index当starting index。
		比如[1, 89，100]，去找90；如果不存在，那么binary search的ending index应该是89，所以下次就从那个index开始。
		如果找不到，会返回要插入的位置index + 1，index是要插入的位置，我写的就是返回要插入的index的。
		但是不管返回89还是100的index都无所谓，反正只差一个，对performance没有明显影响的。
		*/

		namespace CompressWithMap {
			vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
				unordered_map<int, unordered_map<int, int>> m1;
				for (int i = 0; i < mat1.size(); i++) {
					for (int j = 0; j < mat1[0].size(); j++) {
						if (mat1[i][j] != 0) { m1[i][j] = mat1[i][j]; }
					}
				}

				unordered_map<int, unordered_map<int, int>> m2;
				for (int i = 0; i < mat2.size(); i++) {
					for (int j = 0; j < mat2[0].size(); j++) {
						if (mat2[i][j] != 0) { m2[j][i] = mat2[i][j]; } // Note: it is j, i, not i, j!
					}
				}
				
				int rowCount1 = mat1.size();
				int colCount2 = mat2[0].size();
				vector<vector<int>> result(rowCount1, vector<int>(colCount2, 0));
				for (int i = 0; i <= rowCount1; i++) {
					for (int j = 0; j <= colCount2; j++) {
						if (m1.count(i) && m2.count(j)) {
							for (auto [col1 , v1] : m1[i]) {
								if (m2[j].count(col1)) { result[i][j] += v1 * m2[j][col1]; }
							}
						}
					}
				}
				return result;
			}
		
		}

		namespace BruteForce {
			vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
				int rowCount1 = mat1.size();
				if (rowCount1 == 0) { return mat2; }

				int colCount1 = mat1[0].size();
				if (colCount1 == 0) { return {}; }

				int colCount2 = mat2[0].size();
				if (colCount2 == 0) { return mat1; }

				vector<vector<int>> result(rowCount1, vector<int>(colCount2, 0));

				for (int i = 0; i < rowCount1; i++) {
					for (int k = 0; k < colCount1; k++) {
						if (mat1[i][k] != 0) {
							for (int j = 0; j < colCount2; j++) {
								if (mat2[k][j] != 0) {
									result[i][j] += mat1[i][k] * mat2[k][j];
								}
							}
						}
					}
				}
				return result;
			}
		}


		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
