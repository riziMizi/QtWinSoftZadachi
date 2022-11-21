#include <iostream>

using namespace std;

#include "Dropki.h"

int main()
{
    Dropki fraction1, fraction2;

    int numerator, denominator;

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
   

    fraction1.adding(fraction2);
    fraction1.subtracting(fraction2);
    fraction1.multiplication(fraction2);
    fraction1.division(fraction2);

    return 0;
}
