#ifndef ADMIN_H
#define ADMIN_H
#include "Customer.h"
#include "ListCustomer.h"
#include "Room.h"
#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Admin
{
	public:
		
		void setListCustomer(ListCustomer* listCustomer);
		ListCustomer* getListCustomer();
		void viewBooking(int);
		
	private:
		ListCustomer* listCustomer;
};
#endif
