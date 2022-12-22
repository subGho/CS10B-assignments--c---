
#ifndef SORTEDSET_H
#define SORTEDSET_H

#include "IntList.h"

class SortedSet : public IntList
{
    protected:


    public:
        //constructors 
        SortedSet();
        SortedSet(const SortedSet &);
        SortedSet(const IntList &);
        ~SortedSet();

        //accessors 
        bool in(int value);
        SortedSet operator| (const SortedSet &);
        SortedSet operator& (const SortedSet &);

        //mutators
        void add(int value);
        void push_front(int value) ;
        void push_back(int value) ;
        void insert_ordered(int value);
        SortedSet operator|= (const SortedSet &);
        SortedSet operator&= (const SortedSet &);

};




#endif