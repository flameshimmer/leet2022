#include "stdafx.h"

//Given two sparse vectors, compute their dot product.
//Implement class SparseVector:
//SparseVector(nums) Initializes the object with the vector nums
//dotProduct(vec) Compute the dot product between the instance of SparseVector
//and vec
//A sparse vector is a vector that has mostly zero values, you should store the
//sparse vector efficiently and compute the dot product between two SparseVector.
//Follow up: What if only one of the vectors is sparse?
// 
//
//Example 1:
//Input: nums1 = [1,0,0,2,3], nums2 = [0,3,0,4,0]
//Output: 8
//Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
//v1.dotProduct(v2) = 1*0 + 0*3 + 0*0 + 2*4 + 3*0 = 8
//
//Example 2:
//Input: nums1 = [0,1,0,0,0], nums2 = [0,0,0,0,2]
//Output: 0
//Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
//v1.dotProduct(v2) = 0*0 + 1*0 + 0*0 + 0*0 + 0*2 = 0
//
//Example 3:
//Input: nums1 = [0,1,0,0,2,0,0], nums2 = [1,0,0,0,3,0,4]
//Output: 6
// 
//Constraints:
//n == nums1.length == nums2.length
//1 <= n <= 10^5
//0 <= nums1[i], nums2[i] <= 100

namespace Solution2022
{
	namespace DotProductofTwoSparseVectors
	{
		class SparseVector {
		public:
			SparseVector(vector<int>& nums) {
				int len = nums.size();
				for (int i = 0; i < len; i++) {
					if (nums[i] == 0) { continue; }
					map[i] = nums[i];
				}
			}

			// Return the dotProduct of two sparse vectors
			int dotProduct(SparseVector& vec) {
				int result = 0;
				for (const auto& [key, value] : vec.map) {
					if (map[key] == 0) { continue; }
					result += map[key] * value;
				}
				return result;
			}
			unordered_map<int, int> map;
		};

		class SparseVectorIndexForwarding {
		public:
			vector<pair<int, int>> v; // {index, value}
			SparseVectorIndexForwarding(vector<int>& nums) {
				for (int i = 0; i < nums.size(); i++) {
					if (nums[i] == 0) { continue; }
					v.push_back({ i, nums[i] });
				}
			}

			// Return the dotProduct of two sparse vectors
			int dotProduct(SparseVectorIndexForwarding& vec) {
				int result = 0;
				for (int i = 0, j = 0; i < v.size() && j < vec.v.size();) {
					if (v[i].first < vec.v[j].first) { i++; }
					else if (v[i].first > vec.v[j].first) { j++; }
					else { result += v[i].second * vec.v[j].second; i++; j++; }
				}
				return result;
			}

		};
		// Your SparseVector object will be instantiated and called as such:
		// SparseVector v1(nums1);
		// SparseVector v2(nums2);
		// int ans = v1.dotProduct(v2);

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
