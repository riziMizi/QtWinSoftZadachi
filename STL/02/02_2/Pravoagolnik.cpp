#include <iostream>

using namespace std;

#include "Pravoagolnik.h"

Pravoagolnik::Pravoagolnik(int sirina, int dolzina)
{
    this->sirina = sirina;
    this->dolzina = dolzina;
    plostina = sirina * dolzina;
}

Pravoagolnik Pravoagolnik::postavi()
{
    int sirinaPravoagolnik;
    int dolzinaPravoagolnik;
    cout << "Vnesi sirina na pravoagolnikot: ";
    cin >> sirinaPravoagolnik;
    cout << "Vnesi dolzina na pravoagolnikot: ";
    cin >> dolzinaPravoagolnik;
    return Pravoagolnik(sirinaPravoagolnik, dolzinaPravoagolnik); 
}

int Pravoagolnik::getPlostina() const
{
    return plostina;
}