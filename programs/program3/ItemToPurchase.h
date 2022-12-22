#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H
#include <iostream>
using namespace std;

class ItemToPurchase 
{
    public:
    ItemToPurchase();
    ItemToPurchase(string, string, int, int);
    void setName(string);
    string name() const;
    void setPrice(int);
    int price() const;
    void setQuantity(int);
    int quantity() const;

    void setDescription(string);
    string description() const;
    void printItemCost() const;
    void printItemDescription() const;

    private:
    string _name;
    int _price;
    int _quantity;
    string _description;
};


#endif