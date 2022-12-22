#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
#include <iostream>
#include "ItemToPurchase.h"
#include <vector>
using namespace std;

class ShoppingCart
{
    public: 
    ShoppingCart();
    ShoppingCart(string custName, string date);

    string customerName() const;
    string date() const;
    void addItem(ItemToPurchase inputItem);
    void removeItem(string inputItemName);
    void modifyItem(ItemToPurchase inputItem);
    int numItemsInCart();
    int costOfCart();
    void printTotal();
    void printDescriptions();


    private:
    string _customerName;
    string _currentDate;
    vector<ItemToPurchase> _cartItems;
};



#endif