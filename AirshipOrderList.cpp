#include "AirshipOrderList.h"

//Constructor
AirshipOrderList::AirshipOrderList()
{
	pHead = nullptr;
}

//Destructor
AirshipOrderList::~AirshipOrderList() 
{
    Delivery* pCurrent = pHead;
    while (pCurrent != nullptr) 
    {
        Delivery* pTemp = pCurrent; 
        pCurrent = pCurrent->pNext; 
        delete pTemp;               
    }
}


/*********************************************************************
void addDelivery(string szCust, string szItm, int iQty, double dCst);
Purpose:
    Add a new delivery to the end of the linked list(APPEND)
Parameters:
    I string szCust   Name of the customer
    I string szItm    Item purchased
    I int iQty        How many items were purchased
    I double dCst     Total Cost of the delivery
Return Value:
    -
Notes:
    Dynamically creates a new delivery and adds it to the end of the linked list.
    If the list is empty, the new delivery becomes the first node (pHead).
    Deliveries are stored in the order they were added.
*********************************************************************/
void AirshipOrderList::addDelivery(string szCust, string szItm, int iQty, double dCst)
{
    Delivery* pNew = new Delivery(szCust, szItm, iQty, dCst);
    pNew->pNext = nullptr;   //not necessary as the structure already assigns a default value
    
    //Check if list is empty
    if(pHead == nullptr)
    {
        pHead = pNew;
        return;   //the program comes to an end after the node becomes first node
    }

    //If not empty, append to the linked list
    //loop to the end of the list
    Delivery* pCurrent;

    for(pCurrent = pHead; pCurrent->pNext!=nullptr; pCurrent = pCurrent->pNext);

    //append the node
    pCurrent->pNext = pNew;
}


/*********************************************************************
Delivery* findDelivery(string szCust, string szItm) const;

Purpose:
    - To search the AirshipOrderList linked list for a delivery that 
    matches the given customer name and item name.

Parameters:
    I  string szCust - The customer name to search for.
    I  string szItm  - The item name to search for.

Return Value:
    Delivery* 	- Pointer to the Delivery node if a matching delivery 
                  is found and returns nullptr if no matching delivery exists 
                  or if the list is empty.

Notes:
    - This function does not modify the linked list.
    - If the list is empty, "Empty Linked List" is printed to 
      provide feedback.
*********************************************************************/
Delivery* AirshipOrderList::findDelivery(string szCust, string szItm) const
{
	if(pHead == nullptr)
	{
		cout << "Empty Linked List";
		return nullptr;
	}

	Delivery* pCurrent = pHead;
	while(pCurrent != nullptr)
	{
		if(pCurrent->szName == szCust && pCurrent->szItem == szItm)
		{
			return pCurrent;
		}
		pCurrent = pCurrent->pNext;
	} 
	return nullptr;
}


/*********************************************************************
bool removeDelivery(string szCust, string szItm);
Purpose:
    Description of the purpose of the function.
Parameters:
    I string szCust  Name of the customer
    I string sItem   Item purchased
Return Value:
    true - if delivery was successfully removed
    false - if delivery was not successfully removed
Notes:
    Searches for an delivery by customer name and item name.
    If found, removes the delivery from the linked list and frees the memory.
*********************************************************************/
//remove only one instance
bool AirshipOrderList::removeDelivery(string szCust, string szItm)
{
    Delivery* pCurrent = pHead;
    Delivery* pPrevious = nullptr;

    //search for the delivery
    // if remove only one instance
    while(pCurrent!=nullptr && (pCurrent->szName!=szCust || pCurrent->szItem!=szItm))
    {
        pPrevious = pCurrent;
        pCurrent = pCurrent->pNext;
    }

    //if delivery found
    if(pCurrent!=nullptr)
    {
        //if the delivery is the first node
        if(pPrevious == nullptr)
        {
            pHead = pCurrent->pNext;
            delete pCurrent;
            return true;
        }
        //if list has more than one delivery
        else
        {
            pPrevious->pNext = pCurrent->pNext;
            delete pCurrent;
            return true;
        }
    }
    return false;
}


/*********************************************************************
bool modifyDelivery(string szCust, string szItm, int iNewQty, double dNewCst)
Purpose:
    - It searches the AirshipOrderList linked list for a delivery that 
      matches the given customer name and item name and updates its 
      quantity and cost if it is found.

Parameters:
    I  string szCust  - The customer name to search for.
    I  string szItm   - The item name to search for.
    I  int iNewQty 	  - The new quantity to modify .
    I  double dNewCst - The new cost to set modify.

Return Value:
    bool 	- Returns true if the delivery was found and successfully 
           modified; returns false if the delivery does not exist.

Notes:
    This function relies on findDelivery() to find the correct node.
*********************************************************************/
bool AirshipOrderList::modifyDelivery(string szCust, string szItm, int iNewQty, double dNewCst)
{	
	Delivery* pFound = findDelivery(szCust, szItm);

	if (pFound == nullptr)
	{
		return false;
	}
	else
	{
		pFound->iQuantity = iNewQty;
		pFound->dCost = dNewCst;
		return true;
	}
}


/*********************************************************************
void displayDeliveries() const;
Purpose:
    Displays the Lineked list.
Parameters:
    -
Return Value:
    -
Notes:
    Iterates through the linked list and prints each delivery in a readable format.
    If the list is empty, prints "No deliveries to display".
*********************************************************************/
void AirshipOrderList::displayDeliveries() const
{
    //Check if empty
    if(pHead == nullptr)
    {
        cout << "No deliveries to display." << endl;
		cout << "-----------------------------" << endl;
        return;
    }
    //If not empty, print the list
    Delivery* pCurrent = pHead;

    while(pCurrent != nullptr)
    {
        cout<< "Name of the customer: " << pCurrent->szName <<endl;
        cout<< "Name of Item purchased: " << pCurrent->szItem <<endl;
        cout<< "How many items were purchased: " << pCurrent->iQuantity <<endl;
        cout<< "Total Cost of the delivery: " << fixed << setprecision(2) <<pCurrent->dCost <<endl;
        cout << "-----------------------------" << endl;

        pCurrent = pCurrent->pNext;
    }
}