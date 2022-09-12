#include "stdafx.h"

//Given an integer array nums, handle multiple queries of the following types:
//Update the value of an element in nums.
//Calculate the sum of the elements of nums between indices left and right
//inclusive where left <= right.
//Implement the NumArray class:
//NumArray(int[] nums) Initializes the object with the integer array nums.
//void update(int index, int val) Updates the value of nums[index] to be val.
//int sumRange(int left, int right) Returns the sum of the elements of nums
//between indices left and right inclusive (i.e. nums[left] + nums[left + 1] +
//... + nums[right]).
// 
//
//Example 1:
//Input
//["NumArray", "sumRange", "update", "sumRange"]
//[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
//Output
//[null, 9, null, 8]
//Explanation
//NumArray numArray = new NumArray([1, 3, 5]);
//numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
//numArray.update(1, 2);   // nums = [1, 2, 5]
//numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
// 
//Constraints:
//1 <= nums.length <= 3 * 104
//-100 <= nums[i] <= 100
//0 <= index < nums.length
//-100 <= val <= 100
//0 <= left <= right < nums.length
//At most 3 * 104 calls will be made to update and sumRange.

namespace Solution2022
{
	namespace RangeSumQueryMutable
	{
		// Fenwick tree: https://www.youtube.com/watch?v=WbafSgetDDk
		class NumArray {
		private:
			class FenwickTree {
			private:
				vector<int> data;
				int lowBit(int i) { return i & -i; }
			public:
				FenwickTree(int size) {
					data.resize(size + 1, 0); // Note: this should be size+1 instead of size since Fenwick tree is 1 indexed!!!
				}

				void update(int i, int delta) {
					while (i < data.size()) {
						data[i] += delta;
						i += lowBit(i);
					}
				}

				int query(int i) {
					int result = 0;
					while (i > 0) { // Note: this should be > 0 instead of >= 0 since the tree is 1 indexed. 
						result += data[i];
						i -= lowBit(i);
					}
					return result;
				}
			};
			
			FenwickTree tree;
			vector<int> data;
		public:
			NumArray(vector<int>& nums): data(nums), tree(nums.size()) {
				for (int i = 0; i < nums.size(); i++) {
					tree.update(i + 1, nums[i]); // Note: this should be i+1 instead of i since Fenwick tree is 1 indexed!!!
				}
			}

			void update(int i, int val) {
				tree.update(i + 1, val - data[i]); // Note: this should be i+1 instead of i since Fenwick tree is 1 indexed!!!
				data[i] = val;
			}

			int sumRange(int left, int right) {
				return tree.query(right + 1) - tree.query(left);
			}
		};

		/**
		 * Your NumArray object will be instantiated and called as such:
		 * NumArray* obj = new NumArray(nums);
		 * obj->update(index,val);
		 * int param_2 = obj->sumRange(left,right);
		 */

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
