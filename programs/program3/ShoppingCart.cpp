#include <iostream>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"
#include <vector>
using namespace std;

ShoppingCart::ShoppingCart()
{
    _customerName = "none";
    _currentDate = "January 1, 2016";
    
}

ShoppingCart::ShoppingCart(string custName, string date)
{
    _customerName = custName;
    _currentDate = date;
}

//customer getter//
string ShoppingCart::customerName() const
{
    return _customerName;
}
//date getter//
string ShoppingCart::date() const
{
    return _currentDate;
}

void ShoppingCart::addItem(ItemToPurchase inputItem)
{
    _cartItems.push_back(inputItem);
}

void ShoppingCart::removeItem(string inputItemName) 
{
    bool erased = false;
    for (unsigned int i=0; i<_cartItems.size(); i++)
    {
        if (_cartItems.at(i).name() == inputItemName)
        {
            _cartItems.erase(_cartItems.begin()+i);
            erased = true;
        }
    }
    if (!erased)
    {
        cout<<"Item not found in cart. Nothing removed."<<endl;
    }
}

void ShoppingCart::modifyItem(ItemToPurchase inputItem)
{
    bool foundName = false;
    for (unsigned int i=0; i<_cartItems.size(); i++)
    {
        // cout<<foundName<<"before change"<<endl;
        if (_cartItems.at(i).name() == inputItem.name())
        {
            if (_cartItems.at(i).description() != "none")
            {
                _cartItems.at(i).setDescription(inputItem.description());
            }
            // cout<<"ooga"<<_cartItems.at(i).name()<<"ooga"<<_cartItems.at(i).price()<<endl;
            if (_cartItems.at(i).price() == 0)
            {
                _cartItems.at(i).setPrice(inputItem.price());
                // cout<<"ooga"<<_cartItems.at(i).name()<<"ooga"<<_cartItems.at(i).price()<<endl;
            }
            if (_cartItems.at(i).quantity() != 0)
            {
                _cartItems.at(i).setQuantity(inputItem.quantity());
            }
            foundName = true;
            // cout<<foundName<<"in loop if"<<endl;

        }
    }
    if (!foundName)
    {
        // cout<<foundName<<"in not FOund"<<endl;
        cout<<"Item not found in cart. Nothing modified."<<endl;
    }
}

int ShoppingCart::numItemsInCart()
{
    int totalQuantity = 0;
    for (unsigned int i=0; i<_cartItems.size(); i++)
    {
        totalQuantity += _cartItems.at(i).quantity();
    }
    return totalQuantity;
}

int ShoppingCart::costOfCart()
{
    int totalPrice = 0;
    for (unsigned int i=0; i<_cartItems.size(); i++)
    {
        totalPrice += (_cartItems.at(i).price()*_cartItems.at(i).quantity());
    }
    return totalPrice;
}

void ShoppingCart::printTotal()
{
    cout<<customerName()<<"'s Shopping Cart - "<<date()<<endl;
    cout<<"Number of Items: "<<numItemsInCart()<<endl<<endl;
    
    if (_cartItems.size() != 0)
    {
        for (unsigned int i=0; i<_cartItems.size(); i++)
        {
            _cartItems.at(i).printItemCost();
        }
    }
    else
    {
        cout<<"SHOPPING CART IS EMPTY"<<endl;
    }
    cout<<endl<<"Total: $"<<costOfCart()<<endl<<endl;
}

void ShoppingCart::printDescriptions()
{
    cout<<customerName()<<"'s Shopping Cart - "<<date()<<endl<<endl;
    cout<<"Item Descriptions"<<endl;
    for (unsigned int i=0; i<_cartItems.size(); i++)
    {
        _cartItems.at(i).printItemDescription();
    }
}