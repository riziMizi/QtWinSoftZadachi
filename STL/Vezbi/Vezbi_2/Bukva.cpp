#include <iostream>

using namespace std;

#include "Bukva.h"

Bukva::Bukva() {}

Bukva::Bukva(char bukva)
{
    this->bukva = bukva;
    pogodena = false;
}

void Bukva::setPogodena()
{
    pogodena = true;
}

ostream &operator<<(ostream &output, const Bukva &b)
{
    if(b.getPogodena())
        output << b.getBukva();
    else
        output << "-";
   
    return output;   
}