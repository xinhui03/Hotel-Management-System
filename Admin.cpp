#include "Admin.h"
#include "Customer.h"
#include "Room.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


void Admin::setListCustomer(ListCustomer* listCustomer)
{
	this->listCustomer = listCustomer;
}

ListCustomer* Admin::getListCustomer()
{
	return listCustomer;
}

void Admin::viewBooking(int bookingNum)
{
	NodeCustomer* currentNodeCustomer = listCustomer->getHead();
	if (currentNodeCustomer)
	{
		while (currentNodeCustomer)
		{
			if (currentNodeCustomer->getCustomer().getBookingNumber() == bookingNum)
				currentNodeCustomer->getCustomer().getBookingList()->DisplayList();

			currentNodeCustomer = currentNodeCustomer->getNext();
		}
	}
}
