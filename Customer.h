#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Room.h"
#include <iostream>
#include <vector>
#include <string>
#include "ListRoom.h"

using namespace std;


class Customer
{
	private:
		int BookingNumber;
		ListRoom booking;
	public:
		vector<Room> roomList;

		Customer();
		Customer(int);

		void BookingRoomByList(ListRoom);
		
		ListRoom* getBookingList();
		int getBookingNumber();
		void setBookingNumber(int);
		void print();
};

#endif
