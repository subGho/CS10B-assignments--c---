
#include "IntVector.h"

#include <iostream>
#include <stdexcept>
using namespace std;


IntVector::IntVector(unsigned capacity, int value )
{
    _capacity = capacity;
    _size = _capacity;
    _data = nullptr;
    if (capacity > 0) 
    {
        _data = new int[_capacity];
        for (unsigned i=0; i<capacity; i++)
        {
            _data[i]=value;
        }
    }
}

IntVector::~IntVector()
{
   delete[]_data;
}

unsigned IntVector::size() const
{
    // int currSize = 0;
    // for (int i=0; i<_size; i++)
    // {
    //     if (_data[i])
    //     {
    //         currSize++;
    //     }
    // }
    // return currSize;
    return _size;
}

unsigned IntVector::capacity() const
{
    return _capacity;
}

bool IntVector::empty() const
{
    if (size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

const int & IntVector::at(unsigned index) const
{
    if (index < _size)
    {
        return _data[index];
    }
    else
    {
        throw out_of_range("IntVector::at_range_check");
    }
}

const int & IntVector::front() const
{
    return _data[0];
}

const int & IntVector::back() const
{
    return _data[_size-1];
}