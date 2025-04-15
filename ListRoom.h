#pragma once
#include "NodeRoom.h"
#include "ListRoom.h"
#include "Room.h"
#include <iomanip>
#include <iostream>
#include <vector>


class ListRoom
{
public:
    ListRoom();
    NodeRoom* getHead();
    bool IsEmpty();
    void EnqueueRoom(NodeRoom*);


    int FindNodeRoom(NodeRoom);
    NodeRoom* FindNodeRoomByID(string);
    NodeRoom* FindNodeRoomByName(string);
    vector <NodeRoom*> FindNodeRoomByPrice(double);
    friend ostream& operator<<(ostream& os, ListRoom&);

    void DequeueRoom(NodeRoom*);
    void DisplayList();
    int getSize();
private:
    NodeRoom* head;
    NodeRoom* tail;
};
