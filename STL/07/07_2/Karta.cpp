#include <iostream>

using namespace std;

#include "Karta.h"

Karta::Karta(){}

Karta::Karta(int number, string color)
{
    this->number = number;
    this->color = color;
}

ostream &operator<<(ostream &output, const Karta &karta)
{
    output << karta.getNumber() << " " << karta.getColor();
   
    return output;   
}