#include "AirshipOrderList.h"


/*********************************************************************
void displayMenu();
Purpose:
	Displays the menu of the simulation. 
Parameters:
    -
Return Value:
	-
Notes:
    -
*********************************************************************/
void displayMenu()
{
	cout << "Captain, here are your options: " << endl;
    cout << "1. Add a new delivery." << endl;
    cout << "2. Modify an existing delivery." << endl;
    cout << "3. Find a delivery." << endl;
    cout << "4. Remove a delivery" << endl;
	cout << "5. Display all the deliveries." << endl;
    cout << "-1. Exit" << endl;
	cout << "-----------------------------" << endl;
}


/*********************************************************************
File name: program5_driver.cpp
Author: Kripa Hayanju
Date: 11/12/2025

Purpose:
    This program simulates the Skyborne Express Company's alien pet delivery system. 
	It allows the user to manage deliveries of extraterrestrial pets 
   	using a singly linked list implemented in the AirshipOrderList class. 
    Users can add, modify, find, remove, and display deliveries interactively.
Command Parameters:
    -
Input:
    Customer name (string)
    Alien pet name (string)
    Quantity of pets (integer)
    Total cost of delivery (double)
    Menu choice (integer)
Results
    Confirmation messages for each operation (add, modify, remove)
	All of the information of the delivery that the user searches.
	Displays an error message if the user inputs the wrong menu choice.
Notes:
    The program flow is as follows:
	1. Display a welcome message and list available alien pets.
    2. Show the main menu with options to manage deliveries.
    3. Take user input for menu selection.
    4. Perform the selected operation:
        - Add a delivery
        - Modify an existing delivery
        - Find a delivery
        - Remove a delivery
        - Display all deliveries
    5. Loop until the user selects exit (-1).

	It uses fun, creative alien pet names for simulation purposes.
*********************************************************************/
int main()
{
	int iChoice;
	AirshipOrderList orderList;
	
	cout << "Welcome to Skyborne Express Company!" << endl;
	cout << "Track and manage the delivery of extraterrestrial pets as they travel from one planet to another." << endl;

	cout << "Available pet types for delivery: " << endl;
	cout << "1. Martian Cat\n";
	cout << "2. Zorp Dog\n";
	cout << "3. Starling Puffer\n";
	cout << "4. Glorp Pig\n";
	cout << "5. Zap Bear\n \n";

	cout << "Your goal is to ensure every alien pet reaches its destination safely and on time!" << endl;
	
	while(true)
	{
		displayMenu();

		cout << "Enter your choice: ";
		cin >> iChoice;
		if(iChoice == -1)  //if the choice is -1
		{
			cout<< "Exiting the Simulation. Thank you! " << endl;
			break;
		}	

		switch(iChoice)
		{
			case 1:  //Add delivery
			{
				string szN;
				string szI;
        		int iQ;
        		double dC;

				cin.ignore();
				cout << "Enter the name of the customer: ";
				getline(cin, szN);

				cout << "Enter the name of the alien pet: ";
				getline(cin, szI);

				cout << "Enter the number of alien pets ordered: ";
				cin >> iQ;
	
				cout << "Enter the total cost of the delivery: ";
				cin >> dC;

				orderList.addDelivery(szN, szI, iQ, dC);

				cout << "Delivery added successfully!" << endl;
				cout << "-----------------------------" << endl;
				break;
			}
			//Modify Delivery
			case 2:
			{
				string szN;
				string szI;
        		int iQ;
        		double dC;

				cin.ignore();
				
				cout << "Enter the name of the customer: ";
				getline(cin, szN);
				cout << "Enter the name of the alien pet: ";
				getline(cin, szI);
				cout << "Enter the updated number of pets: ";
				cin >> iQ;
				cout << "Enter the updated cost of delivery:  ";
				cin >> dC;

				bool bDelivery = orderList.modifyDelivery(szN, szI, iQ, dC);

				if(bDelivery)
				{
					cout << "Delivery modified successfully!" << endl;
					cout << "-----------------------------" << endl;
					break;
				}
				else
				{
					cout << "Could not modify delivery." << endl;
					cout << "-----------------------------" << endl;
					break;
				}
			}
			//Find a delivery
			case 3:
			{
				string szN;
				string szI;

				cin.ignore();
				
				cout << "Enter the name of the customer: ";
				getline(cin, szN);
				cout << "Enter the name of the alien pet: ";
				getline(cin, szI);

				Delivery* pFound = orderList.findDelivery(szN, szI);

				if(pFound != nullptr)
				{
					cout << "Found the delivery you were searching for!" << endl;
					cout << "Customer name: " << pFound->szName << endl;
					cout << "Alien pet name: "  << pFound->szItem << endl;
					cout << "Total number of pets purchased: " << pFound->iQuantity << endl;
					cout << "Total cost of delivery: " << pFound->dCost << endl; 
					cout << "-----------------------------" << endl;
					break;
				}
				else
				{
					cout << "Not found." << endl;
					cout << "-----------------------------" << endl;
					break;
				}
			}
			case 4:   //Remove the delivery
			{       
				string szN;
				string szI;
				
				cin.ignore();
				cout << "Enter the name of the customer to be removed: ";
				getline(cin, szN);
				
				cout << "Enter the name of the alien pet to be removed: ";
				getline(cin, szI);
				
				bool bRemoved = orderList.removeDelivery(szN, szI);
				
				if(bRemoved)
				{
					cout << "Delivery removed successfully!" << endl;
					cout << "-----------------------------" << endl;
					break;
				}
				else
				{
					cout << "Could not remove the delivery." << endl;
					break;
				}	
			}
			case 5:  //Display the delivery
				orderList.displayDeliveries();
				break;

			default:
				cout << "Wrong choice!" << endl;
		}
	}	
    return 0;	
}	