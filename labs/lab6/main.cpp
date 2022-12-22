
#include "IntVector.h"
#include <iostream>

using namespace std;

int main()
{
    cout<<"compiled"<<endl;
    IntVector aVector(5, 3);
    cout<<"the element is "<<aVector.at(3)<<endl;
    cout<<"front element: "<<aVector.front()<<endl;
    cout<<"back element: "<<aVector.back()<<endl;
    // cout<<"size: "<<aVector.size()<<endl;
    // cout<<"capacity: "<<aVector.capacity()<<endl;
    // IntVector emptVector(0,0);
    // cout<<"size: "<<emptVector.size()<<"\nis emptVector empty? "<<emptVector.empty()<<endl;
    
}

