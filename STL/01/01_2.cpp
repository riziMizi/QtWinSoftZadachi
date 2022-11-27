#include <iostream>

 
using namespace std;

template< class T >  //*
void printArray( const T *array, const int count )//**
{
   for ( int i = 0; i < count; i++ )
      cout << array[ i ] << " ";

    cout << endl;
} // Kraj na function template printArray

template<class T> 
void printArray(const T *array, const int count,
        const int lowSubscript, const int highSubscript)
{
    // pretpostavka deka prviot element(array[0]) ke go
    // vnese kako 1
    if(lowSubscript <= 0 || lowSubscript > count
            || lowSubscript > highSubscript
            || highSubscript > count)
        cout << "0" << endl;
    else
    {
        for(int i = lowSubscript - 1; i < highSubscript; ++i)
            cout << array[i] << " ";
        
        cout << endl;
        cout << highSubscript - lowSubscript + 1 << endl;
    }
} 

 

int main()
{
   const int aCount = 5;
   const int bCount = 7;
   const int cCount = 6;

   int a[ aCount ] = { 1, 2, 3, 4, 5 };
   double b[ bCount ] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
   char c[ cCount ] = "HELLO"; 

   cout << "Poleto a sodrzi:" << endl;
   // povikaj int function-template specijalizacija
   printArray( a, aCount );  //***

   cout << "Poleto b sodrzi:" << endl;
   // povikaj double function-template specijalizacija
   printArray( b, bCount );  // ***

   cout << "Poleto c sodrzi:" << endl;
   // povikaj char function-template specijalizacija
   printArray( c, cCount );  //***

   cout << "Poleto a sodrzi:" << endl;
   printArray(a, aCount, 2, 6);

   cout << "Poleto b sodrzi:" << endl;
   printArray(b, bCount, 2, 6);

   cout << "Poleto c sodrzi:" << endl;
   printArray(c, cCount, 1, 4);

   return 0;
} // kraj na main

 