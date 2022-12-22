#include "ItemToPurchase.h"
#include <iostream>
using namespace std;

ItemToPurchase::ItemToPurchase()
{
    _name = "none";
    _price = 0;
    _quantity = 0;
    _description = "none";
}

ItemToPurchase::ItemToPurchase(string itemName, string itemDescription, int itemPrice, int itemQuantity)
{
    _name = itemName;
    _price = itemPrice;
    _quantity = itemQuantity;
    _description = itemDescription;
}


// name getter and setter //
string ItemToPurchase::name() const
{
    return _name;
} 
void ItemToPurchase::setName(string itemName)
{
    _name = itemName;
}

// price getter and setter //
int ItemToPurchase::price() const
{
    return _price;
}
void ItemToPurchase::setPrice(int itemPrice) 
{
    _price = itemPrice;
}

// quantity getter and setter //
int ItemToPurchase::quantity() const
{
    return _quantity;
}
void ItemToPurchase::setQuantity(int itemQuantity)
{
    _quantity = itemQuantity;
}

// description getter and setter // 
string ItemToPurchase::description() const
{
    return _description;
}
void ItemToPurchase::setDescription(string itemDescription)
{
    _description = itemDescription;
}


void ItemToPurchase::printItemCost() const
{
    cout<<name()<<" "<<quantity()<<" @ $"<<price()<<" = $"<<price()*quantity()<<endl;
}
void ItemToPurchase::printItemDescription() const
{
    cout<<name()<<": "<<description()<<endl;
}

