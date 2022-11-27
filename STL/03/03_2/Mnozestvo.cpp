#include <iostream>
#include <cstring>

using namespace std;

#include "Mnozestvo.h"

template<class T>
int Mnozestvo<T>::numElements = 0;

template<class T>
Mnozestvo<T>::Mnozestvo() {}

template<class T>
void Mnozestvo<T>::addElement(T value)
{ 
    for(int i = 0; i < numElements; ++i)
    {
        if(value == arr[i])
        {
            cout << "Elementoto " << value <<
             " postoi vo nizata.\n";
             return;
        } 
    }
    arr[numElements++] = value;
}

template<class T>
void Mnozestvo<T>::printArray() const
{
    for(int i = 0; i < numElements; ++i)
    {
        cout << arr[i] << " - ";
    }
    cout << endl;
}

template<class T>
T Mnozestvo<T>::maxElement()
{
    if(numElements == 0) return 0;
    T max = arr[0];
    for(int i = 1; i < numElements; ++i)
    {
        if(max < arr[i])
            max = arr[i];
    }

    return max;
}

template<class T>
int Mnozestvo<T>::getNumElements() const
{
    return numElements;
}
