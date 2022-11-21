#include <iostream>

using std::cin;
using std::cout;
using std::endl;

inline void circleArea();


int main()
{
    circleArea();

   return 0;
}

inline void circleArea()
{
    float radius;

    cout << "Vnesete radius na krug: ";
    cin >> radius;

    cout << "Povrsinata na krugot iznesuva: " << radius * 2 * 3.14 << endl;
}


