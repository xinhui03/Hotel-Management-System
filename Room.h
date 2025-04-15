#ifndef ROOM_H
#define ROOM_H
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Room
{
	private:
		string RoomID;
		string RoomName;
		double RoomPrice;
		
	public:
		vector <string> OrderList;

		Room();
		Room(string ,string,double);
		string getRoomID();
		string getRoomName();
		double getRoomPrice();
		void setRoomID(string);
		void setRoomName(string);
		void setRoomPrice(double);
};

#endif
