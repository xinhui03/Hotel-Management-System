#include "NodeRoom.h"

NodeRoom::NodeRoom()
{
    next = NULL;
}

NodeRoom* NodeRoom::getNext()
{
    return this->next;
}

void NodeRoom::setNext(NodeRoom* node)
{
    this->next = node;
}

Room NodeRoom::getRoom()
{
    return room;
}

void NodeRoom::setRoom(Room room)
{
    this->room = room;
}
