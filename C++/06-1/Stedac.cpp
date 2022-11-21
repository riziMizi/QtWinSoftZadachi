#include <iostream>

using namespace std;

#include "Covek.h"
#include "Stedac.h"

int Stedac::kamata = 5;
int Stedac::brojStedaci = 0;

int Stedac::getBrojStedaci() {return brojStedaci;}
int Stedac::getKamata() {return kamata;}

Stedac::Stedac() {}

Stedac::Stedac(string name, string surname, string address,
                string phone, int bilans, int kredit)
    :lice(name, surname, address, phone)
{
    this->bilans = bilans;
    this->kredit = kredit;
    ++brojStedaci;
}

Stedac::~Stedac()
{
    cout << "Izbrishan e korisnikot " << lice.getName() <<
         " " << lice.getSurname() << endl;
    --brojStedaci;
}

void Stedac::print() const 
{
    lice.print();
    cout << "Bilans: " << this->bilans <<
         "\nKredit: " << this->kredit << endl;
}

