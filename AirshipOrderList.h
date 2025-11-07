#include <iostream>
#include <iomanip>
using namespace std;

struct Delivery 
{
    string szName;          // Name of the customer
    string szItem;          // Item purchased
    int iQuantity;          // How many items were purchased
    double dCost;           // Total cost of delivery
    Delivery* pNext = nullptr; // Next delivery

    Delivery(string szN, string szI, int iQ, double dC) :
        szName(szN), szItem(szI), iQuantity(iQ), dCost(dC){}
};

/*********************************************************************
Class Name: AirshipOrderList
Purpose:
    Linked List of Airship Orders
Notes:
    This is used for managing a series of airship deliveries.
*********************************************************************/
class AirshipOrderList
{
    private:
        Delivery* pHead;

    public:
        AirshipOrderList();
        ~AirshipOrderList();

        void addDelivery(string szCust, string szItm, int iQty, double dCst);
        bool removeDelivery(string szCust, string szItm);
        Delivery* findDelivery(string szCust, string szItm) const;
        bool modifyDelivery(string szCust, string szItm, int iNewQty, double dNewCst);
        void displayDeliveries() const;
};