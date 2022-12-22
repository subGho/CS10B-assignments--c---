
#include <iostream>
#include "IntList.h"
#include "SortedSet.h"
using namespace std;


SortedSet::SortedSet() : IntList() {}

SortedSet::SortedSet(const SortedSet &cpy) : IntList(cpy) {}

SortedSet::SortedSet(const IntList &cpy) : IntList(cpy)
{
    remove_duplicates();
    selection_sort();
}

SortedSet::~SortedSet()
{
    clear();
}

bool SortedSet::in(int value)
{
    IntNode *currNode = nullptr;
    currNode = head;
    while (currNode != nullptr)
    {
        if (currNode->value == value)
        {
            return true;
        }
        currNode = currNode->next;
    }
    return false;
}

SortedSet SortedSet::operator| (const SortedSet &inputSet)
{
    SortedSet tempSet;
    IntNode *currNode = nullptr;
    currNode = this->head;
    while (currNode != nullptr)
    {
        tempSet.push_back(currNode->value);
        currNode = currNode->next;
    }
    currNode = nullptr;
    currNode = inputSet.head;
    while (currNode != nullptr)
    {
        tempSet.push_back(currNode->value);
        currNode = currNode->next;
    }
    tempSet.remove_duplicates();
    tempSet.selection_sort();
    return tempSet;
}

SortedSet SortedSet::operator& (const SortedSet &inputSet)
{
    SortedSet tempSet;
    IntNode *currNodeInput = nullptr;
    currNodeInput = inputSet.head;
    IntNode *currNodeThis = nullptr;
    currNodeThis = this->head;

    while (currNodeThis != nullptr)
    {
        while (currNodeInput != nullptr)
        {
            if (currNodeInput->value == currNodeThis->value)
            {
                tempSet.push_back(currNodeInput->value);
            }
            currNodeInput = currNodeInput->next;
        }
        currNodeInput = inputSet.head;
        currNodeThis = currNodeThis->next;
    }
    return tempSet;
}

void SortedSet::add(int value)
{
    if (in(value))
    {
        return;
    }
    else
    {
        insert_ordered(value);
    }
}

void SortedSet::push_front(int value) 
{ 
    add(value);
}

void SortedSet::push_back(int value)
{
    add(value);
}

void SortedSet::insert_ordered(int value)
{
    if (!(in(value)))
    {
        if ((head == nullptr) || (value <= head->value))
    {
        // push_front(value);
        IntNode *newNode = new IntNode(value);
        newNode->next = head;
        head = newNode;
        if (head->next == nullptr) {tail = newNode;}
    }
    else if (value >= tail->value)
    {
        // push_back(value);
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
}

SortedSet SortedSet::operator|= (const SortedSet &inputSet)
{
    SortedSet tempSet;
    tempSet = *this | inputSet;
    *this = tempSet;
    return *this;
}

SortedSet SortedSet::operator&= (const SortedSet &inputSet)
{
    SortedSet tempSet;
    tempSet = *this & inputSet;
    *this = tempSet;
    return *this;
}
