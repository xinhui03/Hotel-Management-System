#include "Room.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Room::Room()
{
	RoomID = "";
	RoomName = "N/A";
	RoomPrice = 0;
}

Room::Room(string id, string name, double price)
{
	RoomID = id;
	RoomName = name;
	RoomPrice = price;
}

string Room::getRoomID()
{
	return RoomID;
}

string Room::getRoomName()
{
	return RoomName;
}

double Room::getRoomPrice()
{
	return RoomPrice;
}

void Room::setRoomID(string id)
{
	RoomID = id;
}

void Room::setRoomName(string name)
{
	RoomName = name;
}

void Room::setRoomPrice(double price)
{
	RoomPrice = price;
}
