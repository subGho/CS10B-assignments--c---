
#include "IntList.h"
#include <iostream>
using namespace std;

IntList::IntList() 
{
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList()
{
    clear();
}

void IntList::push_front(int value)
{
    IntNode *newNode = new IntNode(value);
    newNode->next = head;
    head = newNode;
    if (head->next == nullptr) {tail = newNode;}
}

void IntList::pop_front()
{
    if (head != nullptr)
    {
        IntNode *tempNode = head->next;
        delete head;
        head=tempNode;
        if(head==nullptr){
            tail=nullptr;
        }
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
    return tail->value;
}
//2
ostream & operator<<(ostream &o, const IntList &oIntList)
{
    IntNode *tempNode =oIntList.head;
    if(tempNode!=nullptr){
        o<<tempNode->value;
        for(tempNode=oIntList.head->next;tempNode!=nullptr;tempNode=tempNode->next){
            o<<" "<<tempNode->value;
        }
    }
    // while (tempNode != nullptr)
    // {
        
    //     if (tempNode->next == nullptr)
    //     {
    //         cout<<tempNode->value;
    //     }
    //     else
    //     {
    //         cout<<tempNode->value<<" ";
    //     }
    //     tempNode = tempNode->next;
    // }
    return o;
}

void IntList::push_back(int value)
{
    if (!empty()) 
    {
        IntNode *newNode = new IntNode(value);
        tail->next = newNode;
        tail = newNode;
    }
    else
    {
        head = tail = new IntNode(value);
    }
}

IntList::IntList(const IntList &cpy)
{
    head = nullptr;
    tail = nullptr; 

    IntNode *currNode = cpy.head;
    while(currNode!=nullptr){
        push_back(currNode->value);
        currNode=currNode->next;
    }
}

void IntList::clear()
{
    while (head != nullptr)
    {
        pop_front();
    }
}

void IntList::selection_sort()
{
    IntNode *tempNode = nullptr;
    IntNode *minNode = nullptr;
    IntNode *tempNodeNext = nullptr;

    tempNode = head;
    while (tempNode)
    {
        minNode = tempNode;
        tempNodeNext = tempNode->next;
        while (tempNodeNext)
        {
            if (minNode->value > tempNodeNext->value)
            {
                minNode = tempNodeNext;
            }
            tempNodeNext = tempNodeNext->next;
        }
        int tempVal = tempNode->value;
        tempNode->value = minNode->value;
        minNode->value = tempVal;
        tempNode = tempNode->next;
    }
}

void IntList::insert_ordered(int value)
{
    if ((head == nullptr) || (value <= head->value))
    {
        push_front(value);
    }
    else if (value >= tail->value)
    {
        push_back(value);
    }
    else
    {
        IntNode *insertNode = new IntNode(value);
        IntNode *currNode = head->next;
        IntNode *prevNode = head;

        while (currNode != nullptr)
        {
            if (value <= currNode->value)
            {
                insertNode->next = currNode;
                prevNode->next = insertNode;
                break;
            }
            currNode = currNode->next;
            prevNode = prevNode->next;
        }
    }
}

void IntList::remove_duplicates()
{
    if (head != nullptr)
    {
        IntNode *currNode = head->next;
        IntNode *tempNode = head;
        IntNode *prev=head;
        while (tempNode != nullptr)
        {
            prev=tempNode;
            currNode = prev->next;
            while (currNode != nullptr)
            {
                if (currNode->value == tempNode->value)
                {
                    prev->next = currNode->next;
                    if(currNode->next==nullptr){
                    tail=prev;
                }
                delete currNode;
                currNode = prev->next;
            }
            else
            {
                currNode = currNode->next;
                prev=prev->next;
            }
        }
        tempNode = tempNode->next;
        }
    }
}

IntList & IntList::operator=(const IntList &rhs)
{
    if(this!=&rhs){
        clear();
        IntNode *currNode = nullptr;
        currNode = rhs.head;
        while(currNode!=nullptr)
        {
            push_back(currNode->value);
            currNode=currNode->next;
        }
    }
    // IntList newList(rhs);
    return *this;
}