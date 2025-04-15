#pragma once
#include "Customer.h"

class NodeCustomer 
{
public:
    NodeCustomer();
    NodeCustomer* getNext();
    void setNext(NodeCustomer*);
    void setNULL(){ this->next=NULL; }
    Customer getCustomer();
    void setCustomer(Customer);
private:
    NodeCustomer* next;
    Customer customer;
};

