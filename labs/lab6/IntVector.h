
#ifndef __INTVECTOR_H__
#define __INTVECTOR_H__

#include <iostream>
using namespace std;

class IntVector 
{
    private:
        unsigned _size;
        unsigned _capacity;
        int *_data;
    public:
        IntVector(unsigned capacity = 0, int value = 0);
        ~IntVector();
        unsigned size() const;
        unsigned capacity() const;
        bool empty() const;
        const int & at(unsigned index) const;
        const int & front() const;
        const int & back() const;

        // IntVector* head;
};





#endif 