
#include "IntList.h"
#include <iostream>
using namespace std;

IntList::IntList() 
{
    // data = new int[10];
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList()
{
    // delete[] data;
    delete head;
    head = nullptr;
    delete tail;
    tail = nullptr;
}

void IntList::push_front(int value)
{
    IntNode *newNode = new IntNode(value);
    newNode->next=head;
    head = newNode;
}

void IntList::pop_front()
{
    if (head != nullptr)
    {
        IntNode *tempNode = new IntNode(head->value);
        tempNode->next = head;
        head = tempNode->next->next;
        delete tempNode;
    }
}

bool IntList::empty() const
{
    if (head == nullptr)
    {
        return true;
    }
    return false;
}

const int& IntList::front() const
{
    return head->value;
}

const int& IntList::back() const
{
    IntNode *lastNode = nullptr;
    lastNode = head;
    while (lastNode->next != nullptr)
    {
        lastNode = lastNode->next;
    }
    return lastNode->value;
}

ostream & operator<<(ostream &o, const IntList &oIntList)
{
    IntNode *tempNode = nullptr;
    tempNode = oIntList.head;
    while (tempNode != nullptr)
    {
        if (tempNode->next == nullptr)
        {
            cout<<tempNode->value;
        }
        else
        {
            cout<<tempNode->value<<" ";
        }
        tempNode = tempNode->next;
    }
    return o;
}