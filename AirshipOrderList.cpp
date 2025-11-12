#include "AirshipOrderList.h"

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
// if remove only one instance
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

//if want to delete many of the delivery with the same customer name and item name 
bool AirshipOrderList::removeDelivery(string szCust, string szItm)
{
    Delivery* pCurrent = pHead;
    Delivery* pPrevious = nullptr;

    bool found = false;

    // loop through the list
    while(pCurrent!= nullptr)
    {
        if(pCurrent->szName == szCust && pCurrent->szItem == szItm)
        {
            //if the first node is the delivery
            if(pPrevious == nullptr)
            {
                pHead = pCurrent->pNext;
                delete pCurrent;
                found = true;
            }
            //if list has more than one delivery
            else
            {
                pPrevious->pNext = pCurrent->pNext;
                delete pCurrent;
                found = true;
            }
        }
        pPrevious = pCurrent;
        pCurrent = pCurrent->pNext;
    }
    return found;
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
        cout << "No deliveries to display" << endl;
        return;
    }
    //If not empty, print the list
    Delivery* pCurrent = pHead;

    while(pCurrent != nullptr)
    {
        cout<< "Name of the customer: " << pCurrent->szName <<endl;
        cout<< "Item purchased: " << pCurrent->szItem <<endl;
        cout<< "How many items were purchased: " << pCurrent->iQuantity <<endl;
        cout<< "Total Cost of the delivery: " << pCurrent->dCost <<endl;
        cout << "-----------------------------" << endl;

        pCurrent = pCurrent->pNext;
    }
}