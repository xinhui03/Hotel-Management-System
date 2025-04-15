#pragma once
#include <iostream>
#include "NodeCustomer.h"

class ListCustomer
{
public:
    ListCustomer();
    NodeCustomer* getHead();
    bool IsEmpty();
    void EnqueueCustomer(NodeCustomer*);


    int FindNodeCustomer(NodeCustomer);
    NodeCustomer* FindNodeCustomerByID(int);

    void DequeueCustomer(int);
    void DisplayList();
    int getSize();
    friend ostream& operator<<(ostream& os, ListCustomer&);
    
private:
    NodeCustomer* head;
    NodeCustomer* tail;
};
