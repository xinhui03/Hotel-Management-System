#include "Customer.h"
#include "Room.h"
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

Customer::Customer()
{
	booking = ListRoom();
}

Customer::Customer(int num)
{
	BookingNumber = num;
}


void Customer::BookingRoomByList(ListRoom menu)
{
	int numRooms;
	string roomID;
	double totPrice=0;
	cout << "Booking ID: " << getBookingNumber() << endl << endl;
	cout << "Number of rooms to book: ";
	cin >> numRooms;
	cout << endl;

	for (int i = 1; i <= numRooms; i++)
	{
		NodeRoom* currentRoom = new NodeRoom;
		NodeRoom* roomSearch = NULL;
		Room room;
		cout << "Enter ID for room " << i << ": ";
		cin >> roomID;

		roomSearch = menu.FindNodeRoomByID(roomID);

		room.setRoomID(roomSearch->getRoom().getRoomID());
		room.setRoomName(roomSearch->getRoom().getRoomName());
		room.setRoomPrice(roomSearch->getRoom().getRoomPrice());
		
		totPrice+=roomSearch->getRoom().getRoomPrice();
		
		currentRoom->setRoom(room);
		booking.EnqueueRoom(currentRoom);

		cout << "Room #" << roomID << " has been added to this order." << endl << endl;
	}
	
	if(booking.IsEmpty())
	{
		cout<<"No room is added into booking list"<<endl;
	}
	
	else
	{
		char opt;
		cout<<"Are you confirm with the booking?: "<<endl;
		cout<<"Press Y--> Confirm Booking"<<endl;
		cout<<"Press N--> Edit Booking"<<endl;
		cout<<"Enter your choice: ";
		cin>>opt;
		cout<<endl;
		if(opt=='y'||opt=='Y'){
			system("CLS");
			print();
		}
		else if(opt=='n'||opt=='N')
		{
			bool option1=true;	
			while(option1)
			{
				int choice;
				cout<<"Add room Or delete room"<<endl;
				cout<<"Press 1--> add room"<<endl;
				cout<<"Press 2--> remove room"<<endl;
				cout<<"Enter your choice: ";
				cin>>choice;
				cout<<endl;
				if(choice== 1)
				{
					cout << "Number of rooms to book: ";
					cin >> numRooms;
					cout << endl;
			
					for (int i = 1; i <= numRooms; i++)
					{
					
						NodeRoom* currentRoom = new NodeRoom;
						NodeRoom* roomSearch = NULL;
						Room room;
						cout << "Enter ID for room " << i << ": ";
						cin >> roomID;
				
						roomSearch = menu.FindNodeRoomByID(roomID);
				
						room.setRoomID(roomSearch->getRoom().getRoomID());
						room.setRoomName(roomSearch->getRoom().getRoomName());
						room.setRoomPrice(roomSearch->getRoom().getRoomPrice());
						
						totPrice+=roomSearch->getRoom().getRoomPrice();
						
						currentRoom->setRoom(room);
						booking.EnqueueRoom(currentRoom);
				
						cout << "Room #" << roomID << " has been added to this order." << endl << endl;
					}
				}
				else if(choice==2)
				{
					bool option2=true;
					while(option2)
					{
						cout<<"Enter room ID to delete: ";
						cin>>roomID;
						
						NodeRoom* currentRoom = new NodeRoom;
						NodeRoom* roomSearch = NULL;
						Room room;
						
						roomSearch = menu.FindNodeRoomByID(roomID);
				
						room.setRoomID(roomSearch->getRoom().getRoomID());
						room.setRoomName(roomSearch->getRoom().getRoomName());
						room.setRoomPrice(roomSearch->getRoom().getRoomPrice());
						
						totPrice-=roomSearch->getRoom().getRoomPrice();
						
						currentRoom->setRoom(room);
						booking.DequeueRoom(currentRoom);
						
						cout << "Room #" << roomID << " has been deleted from this order." << endl << endl;
						
						cout<<"Continue delete?"<<endl;
						cout<<"Press Y--> continue delete"<<endl;
						cout<<"Press N--> stop delete"<<endl;
						cout<<"Enter your choice: ";
						cin>>opt;
						cout<<endl;
						if(opt=='y'||opt=='Y')
						{
							option2=true;
						}
						else if(opt=='n'||opt=='N')
						{
							option2=false;
						}
						cout<<endl;
					}
				}
				cout<<"Continue to Edit Booking? "<<endl;
				cout<<"Press Y--> Continue"<<endl;
				cout<<"Press N--> Stop"<<endl;
				cout<<"Enter your choice: ";
				cin>>opt;
				cout<<endl;
				if(opt=='y'||opt=='Y')
				{
					option1=true;
				}
				else if(opt=='n'||opt=='N')
				{
					system("CLS");
					print();
					option1=false;
				}
			}	
		}
	}
}

ListRoom* Customer::getBookingList()
{
	return &booking;
}


int Customer::getBookingNumber()
{
	return BookingNumber;
}

void Customer::setBookingNumber(int bookingNum)
{
	BookingNumber = bookingNum;
}

void Customer::print()
{
    cout << "Booking ID: " << getBookingNumber() << endl;
    cout << "Booking List" << endl;
    cout << "----------" << endl;
    cout << left << setw(10) << "No" << setw(20) << "ID" << setw(40) << "Name" << setw(20) << "Unit Price/RM" << endl;

    ListRoom* roomList = getBookingList();

    if (roomList != nullptr && !roomList->IsEmpty())
    {
        int roomNumber = 1;
        double subtotal = 0.0;

        NodeRoom* currentRoom = roomList->getHead();
        while (currentRoom != nullptr)
        {
            Room room = currentRoom->getRoom();

            cout << left << setw(10) << roomNumber << setw(20) << room.getRoomID() << setw(40) << room.getRoomName()
                 << setw(20) << fixed << setprecision(2) << room.getRoomPrice() << endl;

            subtotal += room.getRoomPrice();

            currentRoom = currentRoom->getNext();
            roomNumber++;
        }

        cout << endl << "Subtotal: RM" << fixed << setprecision(2) << subtotal << endl << endl;
    }
    else
    {
        cout << "No rooms in the booking." << endl;
    }
}