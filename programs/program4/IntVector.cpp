
#include "IntVector.h"

#include <iostream>
#include <stdexcept>
using namespace std;

 
IntVector::IntVector(unsigned capacity, int value )
{
    _capacity = capacity;
    _size = _capacity;
    _data = 0;
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
    if ((index < 0) || (index>=_size))
    {
        throw out_of_range("IntVector::at_range_check");
    }
    else 
    {
        return _data[index];
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

void IntVector::expand()
{
    if (_capacity == 0)
    {
        _capacity = 1;
        _size = 1;
        delete[] _data;
        _data = new int[1];
    }
    else
    {
        _capacity*=2;
        int *_tempdata = new int[_capacity]; 
        copy(_data, _data+(_capacity/2), _tempdata);
        delete[] _data;
        _data = new int[_capacity];
        _data = _tempdata;
    }
}

void IntVector::expand(unsigned amount)
{
    _capacity += amount;
    int *_tempdata = new int[_capacity]; 
    copy(_data, _data+(_capacity - amount), _tempdata);
    delete[] _data;
    _data = new int[_capacity];
    _data = _tempdata;   
}

void IntVector::insert(unsigned index, int value)
{
    // _size++;
    // if (index>=size())
    // {
    //     throw out_of_range("IntVector::insert_range_check");
    // }
    // if (_size>_capacity)
    // {
    //     expand();
    // }
    // for (unsigned i=size()-2; i>=index; i--)
    // {
    //     _data[i+1] = _data[i];
    // }
    // at(index) = value;

    if(_capacity == 0)
        expand(1);
    else
        if(_capacity == _size)
            expand();
            
    _size++;
    
    if(index >= _size)
        throw out_of_range("IntVector::insert_range_check");
    else
    {
        for(unsigned x = _size - 1; x > index; x--)
        {
            at(x) = at(x - 1);
        }
        
        at(index) = value;
    }
}

void IntVector::erase(unsigned index)
{
    if (index>=size())
    {
        throw out_of_range("IntVector::erase_range_check");
    }
    for (unsigned i=index; i<size(); i++)
    {
        _data[i] = _data[i+1];
    }
    _size--;
}

void IntVector::push_back(int value)
{
    _size++;
    if (_size>_capacity)
    {
        expand();
    }
    _data[_size-1] = value;
    // cout<<"hello world"<<endl;
}

void IntVector::pop_back()
{
    _size--;
}

void IntVector::clear()
{
    _size = 0;
}

void IntVector::resize(unsigned size, int value)
{
    if (size<=_size)
    {
        _size = size;
    }
    else if (size > _size)
    {
        int temp = _size;
        _size += (size-_size);
        if (_size > _capacity)
        {
            if ((_capacity+(size-_capacity))>_capacity*2)
            {
                expand(size-_capacity);
            }
            else
            {
                expand();
            }
        }
        for (unsigned i=temp; i<size; i++)
        {
            _data[i] = value;
        }
    }
}

void IntVector::reserve(unsigned n)
{
    if (n>_capacity)
    {
        _capacity = n;
    }
}

void IntVector::assign(unsigned n, int value)
{
    if (n>_capacity)
    {
        if (_capacity + (n-_capacity) > _capacity*2)
        {
            expand(n-_capacity);
        }
        else
        {
            expand();
        }
    }
    _size = n;
    for (unsigned i=0; i<_size; i++)
    {
        _data[i] = value;
    }
}

int & IntVector::at(unsigned index) 
{
    if ((index < 0) || (index>=_size))
    {
        throw out_of_range("IntVector::at_range_check");
    }
    else
    {
        return _data[index];
    }
}

int & IntVector::front() 
{
    return _data[0];
}

int & IntVector::back() 
{
    return _data[_size-1];
}