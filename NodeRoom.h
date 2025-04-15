#pragma once
#include <iostream>
#include "Room.h"

class NodeRoom 
{
public:
    NodeRoom();
    NodeRoom* getNext();
    void setNext(NodeRoom*);
    void setnull(){ this->next=NULL; }
    Room getRoom();
    void setRoom(Room); 
private:
    NodeRoom* next;
    Room room;
};


