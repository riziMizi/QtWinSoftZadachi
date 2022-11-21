// p08_06.cpp
// Drajver za klasata Complex
#include <iostream>

using std::cout;
using std::endl;

#include "Complex.h"

int main()
{
   Complex x, y( 4.3, 8.2 ), z( 3.3, 1.1 );

   cout << "Vnesi realen i imaginaren del na x: ";
   cin >> x;
   cout << "x: ";
   cout << x;

   cout << "\ny: " << y;
   cout << "\nz: " << z;

   x = y + z;
   cout << "\n\nx = y + z:\n";
   cout << x << " = " << y << " + " << z;
 

   x = y - z;
   cout << "\n\nx = y - z:\n";
   cout << x << " = " << y << " - " << z;

   x = y * z;
   cout << "\n\nx = y * z:\n";
   cout << x << " = " << y << " * " << z;

   x = y * 3;
   cout << "\n\nx = y * 3:\n";
   cout << x << " = " << y << " * 3";

   x = 3 * y;
   cout << "\n\nx = 3 * y:\n";
   cout << x << " = 3 * " << y;

   if(y == z) cout << "\n\n" << y << 
            " == " << z;
   else cout << "\n\n" << y << 
            " != " << z;

    if(y != z) cout << "\n\n" << y << 
            " != " << z;
    else cout << "\n\n" << y << 
            " == " << z;

    Complex temp = x;
    x += y;
    cout << "\n\nx += y\n";
    cout << x << " = " << temp << " + " << y;

    temp = x;
    x -= y;
    cout << "\n\nx -= y\n";
    cout << x << " = " << temp << " - " << y;

    temp = x;
    x *= y;
    cout << "\n\nx *= y\n";
    cout << x << " = " << temp << " * " << y;

   return 0;
} // kraj main


