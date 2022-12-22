#include "IntList.h"
#include "SortedSet.h"

#include <iostream>
using namespace std;

int main()
{
    cout<<"hello world"<<endl;

    SortedSet list1;
    list1.push_front(2);
    list1.push_front(3);
    list1.push_front(21);
    list1.push_front(5);
    cout<<"list1 is "<<list1<<endl;
    SortedSet list2;
    list2.push_back(10);
    list2.push_back(3);
    list2.push_back(30);
    list2.push_back(5);
    cout<<"list2 is "<<list2<<endl;

    // TESTING 'IN' FUNCTION
    if (list1.in(13))
    {
        cout<<"13 is in list1"<<endl;
    }
    else
    {
        cout<<"not in list"<<endl;
    }

    // TESTING COPY CONSTRUCTOR
    SortedSet list3(list1);
    list3.clear();
    cout<<list2<<endl;

    // TESTING | OPERATOR
    SortedSet list4;
    list4 = list1 | list2;
    cout<<"list4 is "<<list4<<endl;

    // TESTING & OPERATOR
    SortedSet list5;
    list5 = list1 & list2;
    cout<<"list5 is "<<list5<<endl;

    // TESTING ADD FUNCTION
    list4.add(1);
    list4.add(5);
    list4.add(6);
    cout<<"list4 is "<<list4<<endl;

    // TESTING |= OPERATOR
    list1 |= list2;
    cout<<"list1 is "<<list1<<endl;

    // TESTING &= OPERATOR
    list1 &= list2;
    cout<<"list1 is "<<list1<<endl;

    cout<<endl<<endl<<"PHASE TWO"<<endl<<endl;

    SortedSet list20;
    list20.add(15);
    list20.add(37);
    list20.add(55);
    list20.insert_ordered(15);
    cout<<list20<<endl;

    IntList list22;
    list22.push_back(5);
    list22.push_back(10);
    cout<<list22<<endl;

    SortedSet list23(list22);
    cout<<list23<<endl;
}