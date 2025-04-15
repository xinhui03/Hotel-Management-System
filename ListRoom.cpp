#include "ListRoom.h"
#include "Room.h"
#include "NodeRoom.h"
#include <iomanip>
#include <vector>
#include <string>


ListRoom::ListRoom()
{
    head = NULL;
    tail = NULL;
}
NodeRoom* ListRoom::getHead()
{
    return head;
}
bool ListRoom::IsEmpty()
{
    return head == NULL;
}
void ListRoom::EnqueueRoom(NodeRoom* node)
{
    
    if(head == NULL)
    {
        head = node;
        tail = node; 
    }
    else
    {
		tail->setNext(node);
		node->setnull();
		tail=node;
    }
}
int ListRoom::FindNodeRoom(NodeRoom node)
{
    NodeRoom* currentNodeRoom = head;
    int index = 0;
    while(currentNodeRoom->getRoom().getRoomID() != node.getRoom().getRoomID())
    {
        currentNodeRoom  = currentNodeRoom->getNext();
        index++;
    }    
    if(currentNodeRoom)
    {
        return index;
    }
    else 
    return -1;
}
NodeRoom* ListRoom::FindNodeRoomByName(string name)
{
    NodeRoom* currentNodeRoom = head;
    int index = 0;
    while (currentNodeRoom && currentNodeRoom->getRoom().getRoomName() != name)
    {
        currentNodeRoom = currentNodeRoom->getNext();
        index++;
    }
    if (currentNodeRoom->getRoom().getRoomName() == name)
    {
        return currentNodeRoom;
    }
    else
        return NULL;
}



vector <NodeRoom*> ListRoom::FindNodeRoomByPrice(double budget)
{
	vector <NodeRoom*> roomsLessThanBudget;
	
	NodeRoom* currRoom = head;
	int currIndex = 1;
	
	while(currIndex <= getSize())
	{
		if(currRoom->getRoom().getRoomPrice() <= budget)
		{
			roomsLessThanBudget.push_back(currRoom);
		}
		currRoom = currRoom->getNext();
		currIndex++;
	}
	
	return roomsLessThanBudget;
}


NodeRoom* ListRoom::FindNodeRoomByID(string id)
{
    NodeRoom* currentNodeRoom = head;
    int index = 0;
    while (currentNodeRoom->getRoom().getRoomID() != id && currentNodeRoom != NULL)
    {
        currentNodeRoom = currentNodeRoom->getNext();
        index++;
    }
    if (currentNodeRoom->getRoom().getRoomID() == id)
    {
        return currentNodeRoom;
    }
    else
        return NULL;
}
void ListRoom::DequeueRoom(NodeRoom *node)
{
	NodeRoom* currroom = head;
    NodeRoom* lastroom = tail;
	NodeRoom* delroom = NULL;

	delroom=currroom;
	while(currroom->getRoom().getRoomID() != node->getRoom().getRoomID())
	{
		lastroom->setNext(currroom);
		lastroom=currroom;
		currroom=currroom->getNext();
		delroom=currroom;
	}
	head=currroom->getNext();
	delete delroom;
	tail=lastroom;
	lastroom->setnull();
}
void ListRoom::DisplayList()
{
    cout<<"**One package is for one day only ~ :P"<<endl;
	cout<<"**If u want to stay for more than one day, please place more than one package"<<endl;
	cout<<endl;
    cout << setw(15) << right << "<<<<< MENU >>>>>" << endl;
    cout << setw(10) << left << "Room ID" << setw(60) << left << "Room Name" << setw(8) << left << "Price (RM)" << endl;

    NodeRoom* currentNodeRoom = head;
    if (currentNodeRoom)
    {
        while (currentNodeRoom)
        {
            cout << setw(10) << left << currentNodeRoom->getRoom().getRoomID() << setw(60) << left << currentNodeRoom->getRoom().getRoomName() << setw(8) << left << fixed << setprecision(2) << currentNodeRoom->getRoom().getRoomPrice() << endl;
            currentNodeRoom = currentNodeRoom->getNext();
        }
    }
}
int ListRoom::getSize()
{
    int index = 1;
    NodeRoom* currentNodeRoom = head;
    if(!head)
        return -1;
    else
    {
        while (currentNodeRoom->getNext() != NULL)
        {
            currentNodeRoom = currentNodeRoom->getNext();
            index++;
        }
        return index;
    }
}


ostream& operator<<(ostream& os, ListRoom& room)
{

    room.DisplayList();
    return os;
}
