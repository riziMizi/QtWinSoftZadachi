#include <iostream>

using namespace std;

#include "Dropki.h"

int main()
{
    Dropki fraction1, fraction2, fraction3;

    int numerator, denominator;
    int number;

    cout << "Vnesete broitel i imenitel za prvata dropka: ";
    cin >> numerator >> denominator;
    fraction1.setValues(numerator, denominator);

    cout << "Vnesete broitel i imenitel za vtorata dropka: ";
    cin >> numerator >> denominator;
    fraction2.setValues(numerator, denominator);

    cout << "Prvata dropka: ";
    fraction1.printFractionAsString();
     cout << "Vtorata dropka: ";
    fraction2.printFractionAsString();
   

    fraction3 = fraction1 + fraction2;
    cout << "Sobiranje so dropka: ";
    fraction3.printFractionAsString();

    cout << "Odzemanje so dropka: ";
    fraction3 = fraction1 - fraction2;
    fraction3.printFractionAsString();

    cout << "Mnozenje so dropka: ";
    fraction3 = fraction1 * fraction2;
    fraction3.printFractionAsString();

    cout << "Delenje so dropka: ";
    fraction3 = fraction1 / fraction2;
    fraction3.printFractionAsString();

    cout << "Vnesete cel broj: ";
    cin >> number;

    cout << "Sobiranje so " << number << ": ";
    fraction3 = fraction1 + number;
    fraction3.printFractionAsString();

    cout << "Odzemanje so " << number << ": ";
    fraction3 = fraction1 - number;
    fraction3.printFractionAsString();

    cout << "Mnozenje so " << number << ": ";
    fraction3 = fraction1 * number;
    fraction3.printFractionAsString();

    cout << "Delenje so " << number << ": ";
    fraction3 = fraction1 / number;
    fraction3.printFractionAsString();

    return 0;
}
