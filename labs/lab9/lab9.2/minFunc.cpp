#include "minFunc.h"
const int * min(const int arr[], int arrSize) 
{
    if ((arrSize == 0))
    {
        return nullptr;
    }
    else if ((arrSize == 1))
    {
        return arr;
    }
    const int *low = min(arr+1,arrSize-1);
    return *arr<*low?arr:low;
}