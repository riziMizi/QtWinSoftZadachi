#include <iostream>
#include <ctime>

using namespace std;

#include "Pantaloni.h"

Pantaloni::Pantaloni(){}

Pantaloni::Pantaloni(char *imeArtikl, int golemina, 
        int cena, int denDonesen, int mesecDonesen,
         int godinaDonesen, int denNabavka,
        int mesecNabavka, int godinaNabavka)
        : Artikl(imeArtikl, golemina, cena, 
        denDonesen, mesecDonesen, godinaDonesen),
        datumNaSlednaNabavka(denNabavka, 
        mesecNabavka, godinaNabavka)
        {}


void Pantaloni::prikaziPodatociPantaloni() const
{
    prikaziPodatociArtikl();
    cout << "Datum na sledna nabavka: ";
    getDatumNaSlednaNabavka().print();

}

bool Pantaloni::presmetajNabavka()
{
    static const int daysPerMonth[13] = 
      {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    time_t t = time(0);  
    tm* now = localtime(&t);
    int currentYear = now->tm_year + 1900;
    int currentMonth = now->tm_mon + 1;
    int currentDay = now->tm_mday;
    int supplyDay = datumNaSlednaNabavka.getDay();
    int supplyMonth = datumNaSlednaNabavka.getMonth();
    int supplyYear = datumNaSlednaNabavka.getYear();

    int daysLeft = ((supplyYear * 365) + (daysPerMonth[supplyMonth] + supplyMonth) + 
            supplyDay) - ((currentYear * 365) + (daysPerMonth[currentMonth] + currentMonth) + 
            currentDay);
        if(daysLeft <= 7 && daysLeft >= 0) 
            return true;

    return false;
}

Pantaloni Pantaloni::postaviPantaloni()
{
    char nameArtikl[30];
    int sizeArtikla;
    int priceArtikl;
    int broughtDay, broughtMonth, broughtYear;
    int supplyDay, supplyMonth, supplyYear;

    cout << "Vnesi ime na artiklot: ";
    cin >> nameArtikl;
    cout << "Vnesi golemina: ";
    cin >> sizeArtikla;
    cout << "Vnesi cena: ";
    cin >> priceArtikl;
    cout << "Vnesi koga pristignal vo prodavnica"
            "(den mesec godina):";
    cin >> broughtDay >> broughtMonth >> broughtYear;
    cout << "Vnesi datum za sledna nabavka"
            "(den mesec godina):";
    cin >> supplyDay >> supplyMonth >> supplyYear;

    return Pantaloni(nameArtikl, sizeArtikla, priceArtikl,
                broughtDay, broughtMonth, broughtYear,
                supplyDay, supplyMonth, supplyYear);
}

Datum Pantaloni::getDatumNaSlednaNabavka() const
{
    return datumNaSlednaNabavka;
}

