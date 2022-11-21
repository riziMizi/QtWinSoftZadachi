#include <iostream>
#include <ctime>

using namespace std;

#include "Kosuli.h"

Kosuli::Kosuli(){}

Kosuli::Kosuli(char *imeArtikl, int golemina, 
        int cena, int denDonesen, int mesecDonesen,
         int godinaDonesen)
        : Artikl(imeArtikl, golemina, cena, 
        denDonesen, mesecDonesen, godinaDonesen)
        {}

void Kosuli::prikaziPodatociKosuli() const
{
    prikaziPodatociArtikl();
}


bool Kosuli::presmetajNabavka(){}

Kosuli Kosuli::postaviKosuli()
{
    char nameArtikl[30];
    int sizeArtikla;
    int priceArtikl;
    int day, month, year;
   
    cout << "Vnesi ime na artiklot: ";
    cin >> nameArtikl;
    cout << "Vnesi golemina: ";
    cin >> sizeArtikla;
    cout << "Vnesi cena: ";
    cin >> priceArtikl;
    cout << "Vnesi koga pristignal vo prodavnica"
            "(den mesec godina): ";
    cin >> day >> month >> year;

    return Kosuli(nameArtikl, sizeArtikla, priceArtikl,
                day, month, year);
}

