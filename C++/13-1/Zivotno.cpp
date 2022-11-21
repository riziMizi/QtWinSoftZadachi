#include <iostream>
#include <cstring>

using namespace std;

#include "Zivotno.h"

Zivotno::Zivotno() : datumNaRaganje(1, 1, 2000),
                     datumNaDonesuvanjeVoZoo(1, 1, 2000),
                     datumNaPoslednaVakcinacija(1, 1, 2000) {}

Zivotno::Zivotno(char *name, char gender,
                int birthDay, int birthMonth, int birthYear,
                int commingDay, int commingMonth, int commingYear,
                int vaccinationDay, int vaccinationMonth, 
                int vaccinationYear)
    : datumNaRaganje(birthDay, birthMonth, birthYear),
      datumNaDonesuvanjeVoZoo(commingDay, commingMonth, commingYear),
      datumNaPoslednaVakcinacija(vaccinationDay, vaccinationMonth,
                              vaccinationYear)
{
    ime = new char[strlen(name) + 1];
    strcpy(ime, name);
   
    pol = (gender == 'm' || gender == 'z') ? gender : 'm';
}

void Zivotno::prikaziPodatociZivotno() const
{
    cout << "Zivotnoto se vika: " << getIme() <<
        "\nPol: " << getPol(); 
    cout << "\nDatum na raganje: ";
    getDatumNaRaganje().print();
    cout << "Datum na pristiganje: ";
    getDatumNaDonesuvanjeVoZoo().print();
    cout << "Datum na posledna vakcinacija: ";
    getDatumNaPoslednaVakcinacija().print();
}

char* Zivotno::getIme() const
{
    return ime;
}

char Zivotno::getPol() const
{
    return pol;
}

Datum Zivotno::getDatumNaRaganje() const
{
    return datumNaRaganje;
}

Datum Zivotno::getDatumNaDonesuvanjeVoZoo() const
{
    return datumNaDonesuvanjeVoZoo;
}

Datum Zivotno::getDatumNaPoslednaVakcinacija() const
{
    return datumNaPoslednaVakcinacija;
}



