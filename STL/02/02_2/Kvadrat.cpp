#include <iostream>

using namespace std;

#include "Kvadrat.h"

Kvadrat::Kvadrat(int strana)
{
    this->strana = strana;
    plostina = strana * strana;
}

Kvadrat Kvadrat::postavi()
{
    int stranaKvadrat;
    cout << "Vnesi strana na kvadrat: ";
    cin >> stranaKvadrat;
    return Kvadrat(stranaKvadrat); 
}

int Kvadrat::getPlostina() const
{
    return plostina;
}