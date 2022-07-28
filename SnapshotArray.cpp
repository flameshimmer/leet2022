#include "stdafx.h"

//Implement a SnapshotArray that supports the following interface:
//SnapshotArray(int length) initializes an array-like data structure with the
//given length.  Initially, each element equals 0.
//void set(index, val) sets the element at the given index to be equal to val.
//int snap() takes a snapshot of the array and returns the snap_id: the total
//number of times we called snap() minus 1.
//int get(index, snap_id) returns the value at the given index, at the time we
//took the snapshot with the given snap_id
// 
//
//Example 1:
//Input: ["SnapshotArray","set","snap","set","get"]
//[[3],[0,5],[],[0,6],[0,0]]
//Output: [null,null,0,null,5]
//Explanation: 
//SnapshotArray snapshotArr = new SnapshotArray(3); // set the length to be 3
//snapshotArr.set(0,5);  // Set array[0] = 5
//snapshotArr.snap();  // Take a snapshot, return snap_id = 0
//snapshotArr.set(0,6);
//snapshotArr.get(0,0);  // Get the value of array[0] with snap_id = 0, return 5
// 
//Constraints:
//1 <= length <= 50000
//At most 50000 calls will be made to set, snap, and get.
//0 <= index < length
//0 <= snap_id < (the total number of times we call snap())
//0 <= val <= 10^9

namespace Solution2022
{
	namespace SnapshotArray
	{
		namespace UseHashMap {
			class SnapshotArray {
			private:
				int curSnap;
				unordered_map<int, unordered_map<int, int>> map; // index, (version, value)
			public:
				SnapshotArray(int length) {
					curSnap = 0;
				}

				void set(int index, int val) {
					map[index][curSnap] = val;
				}

				int snap() {
					curSnap++;
					return curSnap;
				}

				int get(int index, int snap_id) {
					auto it = map[index].upper_bound(snap_id);
					if (it == map[index].begin()) { return 0; }
					return prev(it)->second;
				}
			};
		}
		
		/**
		 * Your SnapshotArray object will be instantiated and called as such:
		 * SnapshotArray* obj = new SnapshotArray(length);
		 * obj->set(index,val);
		 * int param_2 = obj->snap();
		 * int param_3 = obj->get(index,snap_id);
		 */

		void Main() {
			//SnapshotArray* obj = new SnapshotArray(2);
			////obj->set(0, 15);
			////int param_2 = obj->snap();
			////int param_3 = obj->snap();
			////int param_4 = obj->snap();
			////int param_5 = obj->get(0, 2);
			////int param_6 = obj->snap();
			////int param_7 = obj->snap();
			////int param_8 = obj->get(0, 0);

			//int param_1 = obj->snap();
			//int param_2 = obj->get(1, 0);
			//int param_3 = obj->get(0, 0);
			//obj->set(1, 8);
			//int param_5 = obj->get(1, 0);
			//obj->set(0, 20);
			//int param_4 = obj->get(0, 0);
			//obj->set(0, 7);

		}
	}
}
