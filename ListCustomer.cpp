#include "ListCustomer.h"
#include <iomanip>


ListCustomer::ListCustomer()
{
    head = NULL;
    tail = NULL;
}
NodeCustomer* ListCustomer::getHead()
{
    return head;
}
bool ListCustomer::IsEmpty()
{
    return head == NULL;
}
void ListCustomer::EnqueueCustomer(NodeCustomer* node)
{

    if (head == NULL)
    {
        head = node;
        tail = node;
    }
    else
    {
		tail->setNext(node);
		node->setNULL();
		tail=node;
    }
}
int ListCustomer::FindNodeCustomer(NodeCustomer node)
{
    NodeCustomer* currentNodeCustomer = head;
    int index = 0;
    while (currentNodeCustomer->getCustomer().getBookingNumber() != node.getCustomer().getBookingNumber())
    {
        currentNodeCustomer = currentNodeCustomer->getNext();
        index++;
    }
    if (currentNodeCustomer)
    {
        return index;
    }
    else
        return -1;
}

NodeCustomer* ListCustomer::FindNodeCustomerByID(int id)
{
    NodeCustomer* currentNodeCustomer = head;
    int index = 0;
    while (currentNodeCustomer->getCustomer().getBookingNumber() != id && currentNodeCustomer != NULL)
    {
        currentNodeCustomer = currentNodeCustomer->getNext();
        index++;
    }
    if (currentNodeCustomer->getCustomer().getBookingNumber() == id)
    {
        return currentNodeCustomer;
    }
    else
        return NULL;
}
void ListCustomer::DequeueCustomer(int bookingNumber)
{
    NodeCustomer* currcus = head;
    NodeCustomer* lastcus = tail;
	NodeCustomer* delcus = NULL;

	
	delcus=currcus;
	while(currcus->getCustomer().getBookingNumber()!=bookingNumber)
	{
		lastcus->setNext(currcus);
		lastcus=currcus;
		currcus=currcus->getNext();
		delcus=currcus;
	}
	head=currcus->getNext();
	delete delcus;
	tail=lastcus;
	lastcus->setNULL();
	
}
void ListCustomer::DisplayList()
{
    NodeCustomer* currentNodeCustomer = head;
    if (currentNodeCustomer)
    {
        while (currentNodeCustomer)
        {
            cout << "Booking ID: ";
            cout << currentNodeCustomer->getCustomer().getBookingNumber() << endl;

            cout << "Total Booked Room: ";
            cout << currentNodeCustomer->getCustomer().getBookingList()->getSize() << endl;
            cout << endl;

            currentNodeCustomer = currentNodeCustomer->getNext();
        }
    }
    
}
int ListCustomer::getSize()
{
    int index = 0;
    NodeCustomer* currentNodeCustomer = head;
    if (!head)
        return -1;
    else
    {
        while (currentNodeCustomer->getNext() != NULL)
        {
            currentNodeCustomer = currentNodeCustomer->getNext();
            index++;
        }
        return index;
    }

    
}


ostream& operator<<(ostream& os, ListCustomer& customer)
{

    customer.DisplayList();
    return os;
}
