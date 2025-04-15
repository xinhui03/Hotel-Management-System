#include "Room.h"
#include "Customer.h"
#include "ListCustomer.h"
#include "Admin.h"
#include "NodeCustomer.h"
#include "ListRoom.h"
#include "NodeRoom.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <vector>
#include <windows.h>

using namespace std;

static int bookingNum = 1;

string user_interface = "\n\n\n\n\t\tWelcome Ivlyn_Yt_Xh_Yx Hotel Management System.\n\t\t";

void AddCustomer(string customer_mobile, string customer_name, string customer_gender,int customer_age, string customer_Ic,string customer_email)
{
	cout << "Please enter your information details"<< endl;
	cout << "Name: ";
	cin >>customer_name;
	cout << "Phone Number: ";
	cin >>customer_mobile;
	cout << "Gender: ";
	cin >>customer_gender;
	cout <<"Age: ";
	cin >>customer_age;
	cout <<"Ic number:";
	cin >>customer_Ic;
	cout <<"Email: ";
	cin>> customer_email;	
	system("CLS");
}

string to_lower(string ori)
{

	for (int i = 0; i < ori.size(); i++)
	{
		ori[i] = tolower(ori[i]);
	}

	return ori;
}

int customerAction()
{
	int choice;

	cout << "### CUSTOMER MENU ###" << endl;
	cout<<  "1) View Hotel Package List" << endl;
	cout << "2) Add Room" << endl;
	cout << "3) Search menu by name" << endl;
	cout << "4) Search menu by budget" << endl;
	cout << "5) Exit" << endl;
	for(int i=0;i<25;i++){
		cout<<"-";
	}
	cout<<endl;
	cout << "Option: ";
	cin >> choice;
	cout<<endl;
	return choice;
}

int main()
{
	system("color E1");
	ifstream readMenu;

	string room_ID;
	string room_Name;
	double room_Price;

	ListRoom menuList;
	ListCustomer listOrder;

	cout<<user_interface;
	system ("PAUSE");
	system("CLS");
	readMenu.open("menu.txt");

	int i = 0;

	while (!readMenu.eof())
	{
		NodeRoom* menu = new NodeRoom;
		Room room;

		readMenu >> room_ID >> room_Name >> room_Price;

		room.setRoomID(room_ID);
		room.setRoomName(room_Name);
		room.setRoomPrice(room_Price);

		menu->setRoom(room);
		menuList.EnqueueRoom(menu);
	}

	readMenu.close();

	char choiceContinue1, choiceContinue2;
	int listSize = menuList.getSize();
	int role;
	bool loop = true;

	while (loop)
	{
		bool choosing1 = true, choosing2 = true;

		system("CLS");
		cout << "### USER MENU ###" << endl;
		cout<<"Please select your category."<<endl;
		cout << "1--> Customer " << endl << "2--> Admin" << endl;
		for(int i=0;i<25;i++){
			cout<<"-";
		}
		cout<<endl;
		cout << "Option: ";
		cin >> role;
		if (role == 1)
		{

			while (choosing1)
			{
				bool booking = true;

				while (booking)
				{
					system("CLS");
					int choice;
					cout << endl;

					choice = customerAction();

					switch (choice)
					{
					case 1: {
						system("CLS");
						menuList.DisplayList();
						cout<< endl << "Press 1--> return to Customer Menu\n Option: ";
						int ch;
                    	cin>>ch;
                    	if (ch==1)
                    	{
							system("CLS");
                    	}
						break;
					}
					case 2: {
						
						string customer_name, customer_mobile, customer_gender, customer_Ic,customer_email;
						int customer_age;

						Customer customer;
						double totPrice=0;
						system("CLS");
						AddCustomer(customer_mobile,customer_name,customer_gender,customer_age,customer_Ic,customer_email);
						system("CLS");
						NodeCustomer* customerNode = new NodeCustomer;
						customer.setBookingNumber(bookingNum++);
						system("CLS");
						cout << menuList;
						cout << endl;
						customer.BookingRoomByList(menuList);
						customerNode->setCustomer(customer);
						listOrder.EnqueueCustomer(customerNode);
						system("PAUSE");
						break;
					}
					case 3: {
						string roomName;
						int index;
						cout << endl << "Enter the room name you want to search: ";
						cin>>roomName;
						system("CLS");
						cout<<"**One package is for one day only ~ :P"<<endl;
						cout<<"**If u want to stay for more than one day, please place more than one package"<<endl;
						cout<<endl;
						cout << setw(15) << right << "<<<<< MENU >>>>>" << endl;
						cout << setw(10) << left << "Room ID" << setw(60) << left << "Room Name" << setw(8) << left << "Price (RM)" << endl;
						cout << setw(10) << left << menuList.FindNodeRoomByName(roomName)->getRoom().getRoomID() << setw(60) << left << menuList.FindNodeRoomByName(roomName)->getRoom().getRoomName() << setw(8) << left << fixed << setprecision(2) << menuList.FindNodeRoomByName(roomName)->getRoom().getRoomPrice() << endl;
						system("PAUSE");
						break;
					}

					case 4:
					{
						vector <NodeRoom*> roomsLessThanBudget;
						double budget;
						
						cout << endl << "Enter your maximum budget (RM): ";
						cin >> budget;
						
						roomsLessThanBudget = menuList.FindNodeRoomByPrice(budget);
						system("CLS");
						cout<<"**One package is for one day only ~ :P"<<endl;
						cout<<"**If u want to stay for more than one day, please place more than one package"<<endl;
						cout<<endl;
						cout << setw(15) << right << "<<<<< MENU >>>>>" << endl;
						cout << setw(10) << left << "Room ID" << setw(60) << left << "Room Name" << setw(8) << left << "Price (RM)" << endl;
						
						for(int i=0; i<roomsLessThanBudget.size(); i++)
						{
							cout << setw(10) << left << roomsLessThanBudget[i]->getRoom().getRoomID() << setw(60) << left << roomsLessThanBudget[i]->getRoom().getRoomName() << setw(8) << left << fixed << setprecision(2) << roomsLessThanBudget[i]->getRoom().getRoomPrice() << endl;
						}
						system("PAUSE");
						break;
						
					}
					case 5: {
						char quit;
						cout << "Do you want to quit booking?" << endl;
						cout<<"Press Y--> Quit"<<endl;
						cout<<"Press N--> Continue Booking"<<endl;
						cout<<"Enter your choice: ";
						cin >> quit;
						if (tolower(quit) == 'y')
						{
							booking = false;
						}
						break;
					}

					default: {	cout << "Invlid option, please try again." << endl;
						booking = true;
						break;
					}
					}
				}
				system("CLS");
				cout << "Do you want to continue as another role?"<<endl;
				cout<<"Press Y--> Continue"<<endl;
				cout<<"Press N--> Exit"<<endl;
				cout<<"Enter your choice: ";
				cin >> choiceContinue1;
				if (tolower(choiceContinue1) == 'y')
					choosing1 = false;
				else
					goto jmp;
			}
		}
		else if (role == 2)
		{

			while (choosing2)
			{

				Admin admin;

				admin.setListCustomer(&listOrder);

				bool working = true;


				while (working)
				{
					system("CLS");

					cout << "Booking List:" << endl;
					cout << endl;
					cout << listOrder;

					int choice;
					cout << "### ADMIN MENU ###" << endl;
					cout << "1) View Booking List" << endl;
					cout << "2) Quit viewing" << endl;
					for(int i=0;i<25;i++){
						cout<<"-";
					}
					cout<<endl;
					cout << "Option: ";
					cin >> choice;
					cout << endl;

					switch(choice)
					{
					case 1: {
						int id;
						bool viewBooking = true;

						if (admin.getListCustomer()->IsEmpty())
						{
							cout << "There are no orders available to view currently." << endl << endl;
							system("PAUSE");
						}

						else
						{
							cout << "Enter the Booking ID to be viewed: ";
							cin >> id;

							system("CLS");
							
							admin.viewBooking(id);
							system("PAUSE");

						}
						break;
					}
					case 2: {
						char choiceQuitCrew;
						cout << "Do you want to quit as admin?(Y/N)" << endl;
						cout<<"Choose Y to quit"<<endl;
						cout<<"Choose N to continue as admin"<<endl;
						cout<<"Enter your choice: ";
						cin >> choiceQuitCrew;
						if(tolower(choiceQuitCrew) == 'y')
							working = false;
						break;
					}
					default: {
						cout << "Invalid Input! Please try again." << endl << endl;
					  	system("PAUSE");
					}  
					}   
				} 
				system("CLS"); 
				cout << "Do you want to continue as another role? (Y/N)"<<endl;
				cout<<"Choose Y for continue"<<endl;
				cout<<"Choose N for close the system"<<endl;
				cout<<"Enter your choice: ";
				cin >> choiceContinue2;                                                
				if (tolower(choiceContinue2) == 'y')                                        
					choosing2 = false; 
				else
					goto jmp;
			}
		}
		else
		{
			cout << "Invalid Input! Please try again." << endl << endl;
			system("PAUSE");
		}
	}
jmp:
	return 0;
}
