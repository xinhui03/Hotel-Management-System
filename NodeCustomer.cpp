#include "NodeCustomer.h"
NodeCustomer::NodeCustomer()
{
    next = NULL;
}

NodeCustomer* NodeCustomer::getNext()
{
    return this->next;
}

void NodeCustomer::setNext(NodeCustomer* node)
{
    this->next = node;
}

Customer NodeCustomer::getCustomer()
{
    return customer;
}

void NodeCustomer::setCustomer(Customer customer)
{
    this->customer = customer;
}
