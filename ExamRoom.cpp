#include "stdafx.h"

//There is an exam room with n seats in a single row labeled from 0 to n - 1.
//When a student enters the room, they must sit in the seat that maximizes the
//distance to the closest person. If there are multiple such seats, they sit in
//the seat with the lowest number. If no one is in the room, then the student
//sits at seat number 0.
//Design a class that simulates the mentioned exam room.
//Implement the ExamRoom class:
//ExamRoom(int n) Initializes the object of the exam room with the number of the
//seats n.
//int seat() Returns the label of the seat at which the next student will set.
//void leave(int p) Indicates that the student sitting at seat p will leave the
//room. It is guaranteed that there will be a student sitting at seat p.
// 
//
//Example 1:
//Input
//["ExamRoom", "seat", "seat", "seat", "seat", "leave", "seat"]
//[[10], [], [], [], [], [4], []]
//Output
//[null, 0, 9, 4, 2, null, 5]
//Explanation
//ExamRoom examRoom = new ExamRoom(10);
//examRoom.seat(); // return 0, no one is in the room, then the student sits at
//seat number 0.
//examRoom.seat(); // return 9, the student sits at the last seat number 9.
//examRoom.seat(); // return 4, the student sits at the last seat number 4.
//examRoom.seat(); // return 2, the student sits at the last seat number 2.
//examRoom.leave(4);
//examRoom.seat(); // return 5, the student sits at the last seat number 5.
// 
//Constraints:
//1 <= n <= 109
//It is guaranteed that there is a student sitting at seat p.
//At most 104 calls will be made to seat and leave.

namespace Solution2022
{
	namespace ExamRoom
	{

		class ExamRoom {	
		private:
			int capacity;
			list<int> seats;
			unordered_map<int, list<int>::iterator> map; // seatId, the seatId's iterator in linked list
		public:
			ExamRoom(int N): capacity(N) {			
			}

			int seat() {
				if (seats.empty()) {
					seats.push_back(0);
					map[0] = seats.begin();
					return 0;
				}

				int lastSeat = -1; // last scanned value in linkedlist
				int distanceToNeighbour = 0; // distance to its neighbors
				int newSeat = 0; // the number to sit on
				list<int>::iterator insertPos; // insert position in linked list

				for (auto it = seats.begin(); it != seats.end(); it++) {
					if (lastSeat == -1) {
						distanceToNeighbour = *it;
						insertPos = it;
						newSeat = 0;
					}
					else if ((*it - lastSeat) / 2 > distanceToNeighbour) {
						distanceToNeighbour = (*it - lastSeat) / 2;
						insertPos = it;
						newSeat = (*it + lastSeat) / 2;
					}
					lastSeat = *it;
				}

				if (capacity - 1 - seats.back() > distanceToNeighbour) {
					insertPos = seats.end();
					newSeat = capacity - 1;
				}

				auto it = seats.insert(insertPos, newSeat);
				map[newSeat] = it;
				return newSeat;
			}

			void leave(int p) {
				seats.erase(map[p]);
			}
		
		};

		/**
		 * Your ExamRoom object will be instantiated and called as such:
		 * ExamRoom* obj = new ExamRoom(n);
		 * print (obj->seat();
		 * obj->leave(p);
		 */

		void Main() {
			ExamRoom* obj = new ExamRoom(10);
			print(obj->seat());
			print(obj->seat());
			print(obj->seat());
			print(obj->seat());
			obj->leave(4);
			print(obj->seat());

			//ExamRoom* obj = new ExamRoom(4);
			//print(obj->seat());
			//print(obj->seat());
			//print(obj->seat());
			//print(obj->seat());
			//obj->leave(1);
			//obj->leave(3);
			//print(obj->seat());
		}
	}
}
