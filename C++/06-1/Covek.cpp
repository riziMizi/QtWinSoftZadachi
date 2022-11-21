#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

#include "Covek.h"

Covek::Covek() {}

Covek::Covek(string name, string surname, 
            string address, string phone)
{
    this->name = name;
    this->surname = surname;
    this->address = address;
    this->phone = phone;
}

void Covek::print() const
{
    cout << "Ime: " << this->name <<
         "\nPrezime: " << this->surname <<
         "\nAdresa: " << this->address <<
         "\nTelefon: " << this->phone << endl;
}