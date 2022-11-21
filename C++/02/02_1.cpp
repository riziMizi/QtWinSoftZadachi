#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template <typename T>
T min(T value1, T value2);

int main()
{
    int int1, int2;

    cout << "Vnesi dva celi broja: ";
    cin >> int1 >> int2;
    cout << "Minimalniot cel broj e: "
         << min(int1, int2);

   double double1, double2;

   cout << "\nVnesi dve double vrednosti: ";
   cin >> double1 >> double2;
   cout << "Minimalnata double vrednost e: "
        << min(double1, double2);

   char char1, char2;

   cout << "\nVnesi dva karakteri: ";
   cin >> char1 >> char2;
   cout << "Minimalniot karakter e: "
        << min(char1, char2) << endl;

   return 0;
}

template <typename T>
T min(T value1, T value2)
{
    if(value1 <= value2) return value1;
    else return value2;
}
