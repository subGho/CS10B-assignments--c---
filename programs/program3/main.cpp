#include "ItemToPurchase.h"
#include "ShoppingCart.h"
#include <iostream>
using namespace std;

void printMenu(ShoppingCart inputCart);
char inputChar;

int main()
{   
    string inputCustomerName;
    string inputTodayDate;
    cout<<"Enter customer's name: "<<endl;
    getline(cin, inputCustomerName);
    cout<<"Enter today's date: ";
    getline(cin, inputTodayDate);
    cout<<endl<<endl;

    ShoppingCart cart = ShoppingCart(inputCustomerName, inputTodayDate);
    cout<<"Customer name: "<<cart.customerName()<<endl;
    cout<<"Today's date: "<<cart.date()<<endl<<endl;



    // cin>>inputChar;
    // while (inputChar != 'q')
    // {
        printMenu(cart);
    // }
    

    

    return 0;
}

void printMenu(ShoppingCart inputCart)
{
    // char inputChar;
    string inputItemName;
    string inputItemDescription;
    int inputItemPrice;
    int inputItemQuantity;
    ItemToPurchase itemToAdd;
    cout<<"MENU"<<endl;
    cout<<"a - Add item to cart"<<endl;
    cout<<"d - Remove item from cart"<<endl;
    cout<<"c - Change item quantity"<<endl;
    cout<<"i - Output items' descriptions"<<endl;
    cout<<"o - Output shopping cart"<<endl;
    cout<<"q - Quit"<<endl<<endl;
    cout<<"Choose an option: "<<endl;

    cin>>inputChar;
    bool isq = false;
    while (inputChar!='q')
    {
        while (inputChar != 'a' && inputChar != 'd' && inputChar != 'c' && inputChar != 'i' && inputChar != 'o')
        {
            if (inputChar == 'q')
            {
                isq = true;
                break;
            }
            cout<<"Choose an option: "<<endl;
            cin>>inputChar;
        }
        if (isq) 
        {
            break;
        }
        if (inputChar == 'a')
        {
            cout<<endl<<"ADD ITEM TO CART"<<endl;
            cout<<"Enter the item name: "<<endl;
            cin.ignore();
            getline(cin, inputItemName);
            itemToAdd.setName(inputItemName);
            cout<<"Enter the item description: "<<endl;
            getline(cin, inputItemDescription);
            itemToAdd.setDescription(inputItemDescription);
            cout<<"Enter the item price: "<<endl;
            cin>>inputItemPrice;
            itemToAdd.setPrice(inputItemPrice);
            cout<<"Enter the item quantity: "<<endl<<endl;
            cin>>inputItemQuantity;
            itemToAdd.setQuantity(inputItemQuantity);
            inputCart.addItem(itemToAdd);
        }
        else if (inputChar == 'd')
        {
            cout<<endl<<"REMOVE ITEM FROM CART"<<endl;
            cout<<"Enter name of item to remove: "<<endl;
            cin.ignore();
            getline(cin, inputItemName);
            inputCart.removeItem(inputItemName);
            cout<<endl;
        }
        else if (inputChar == 'c')
        {
            cout<<endl<<"CHANGE ITEM QUANTITY"<<endl;
            cout<<"Enter the item name: "<<endl;
            cin.ignore();
            getline(cin, inputItemName);
            itemToAdd.setName(inputItemName);
            cout<<"Enter the new quantity: "<<endl;
            cin>>inputItemQuantity;
            itemToAdd.setQuantity(inputItemQuantity);
            inputCart.modifyItem(itemToAdd);
            cout<<endl;
        }
        else if (inputChar == 'i')
        {
            cout<<endl<<"OUTPUT ITEMS' DESCRIPTIONS"<<endl;
            inputCart.printDescriptions();
            cout<<endl;
        }
        else if (inputChar == 'o')
        {
            cout<<endl<<"OUTPUT SHOPPING CART"<<endl;
            inputCart.printTotal();
        }
        // else if (inputChar == 'q')
        // {
        //     break;
        // }
        // else
        // {
        //     while ()

        // }
        cout<<"MENU"<<endl;
        cout<<"a - Add item to cart"<<endl;
        cout<<"d - Remove item from cart"<<endl;
        cout<<"c - Change item quantity"<<endl;
        cout<<"i - Output items' descriptions"<<endl;
        cout<<"o - Output shopping cart"<<endl;
        cout<<"q - Quit"<<endl<<endl;
        cout<<"Choose an option: " <<endl;
        cin>>inputChar;
        
    }
    // cout<<endl;

}