
#include "IntVector.h"
#include <iostream>

using namespace std;
 
int main()
{
    cout<<"compiled"<<endl;
    // IntVector aVector(5, 3);
    IntVector aVector(10,2);
    cout<<"size: "<<aVector.size()<<endl;
    cout<<"capacity: "<<aVector.capacity()<<endl;
    // for (unsigned i=0; i<aVector.size(); i++)
    // {
    //     cout<<aVector.at(i)<<" ";
    // }
    cout<<endl;
    // aVector.expand();
    // cout<<"the element is "<<aVector.at(3)<<endl;
    // cout<<"front element: "<<aVector.front()<<endl;
    // cout<<"back element: "<<aVector.back()<<endl;
    
    for (unsigned i=0; i<aVector.size(); i++)
    {
        cout<<aVector.at(i)<<" ";
    }
    cout<<endl;
    // aVector.erase(0);
    // cout<<"size: "<<aVector.size()<<endl;
    // cout<<"capacity: "<<aVector.capacity()<<endl;
    // for (unsigned i=0; i<aVector.size(); i++)
    // {
    //     cout<<aVector.at(i)<<" ";
    // }
    // cout<<endl;
    aVector.insert(1, 0);

    // aVector.erase(1);
    // for (unsigned i=0; i<aVector.size(); i++)
    // {
    //     cout<<aVector.at(i)<<" ";
    // }
    // cout<<endl;
    // aVector.erase(1);
    // aVector.push_back(2);
    // cout<<"size: "<<aVector.size()<<endl;
    // cout<<"capacity: "<<aVector.capacity()<<endl;
    // for (unsigned i=0; i<aVector.size(); i++)
    // {
    //     cout<<aVector.at(i)<<" ";
    // }
    // cout<<endl;
    // aVector.pop_back();
    // aVector.clear();
    // aVector.resize(8);
    // aVector.expand(10);
    // aVector.reserve(20);
    // aVector.assign(49, 0);
    cout<<"size: "<<aVector.size()<<endl;
    cout<<"capacity: "<<aVector.capacity()<<endl;
    for (unsigned i=0; i<aVector.size(); i++)
    {
        cout<<aVector.at(i)<<" ";
    }
    cout<<endl;
    // cout<<aVector;
    // IntVector emptVector(0,0);
    // cout<<"size: "<<emptVector.size()<<"\nis emptVector empty? "<<emptVector.empty()<<endl;
    
}

