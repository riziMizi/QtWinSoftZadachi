#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

#include "Datum.h"
#include "Zivotno.h"

Zivotno::Zivotno() : datumNaRaganje(1, 1, 2000),
                     datumNaDonesuvanjeVoZoo(1, 1, 2000),
                     datumNaPoslednaVakcinacija(1, 1, 2000) {}

Zivotno::Zivotno(char *name, char type, char gender,
                int birthDay, int birthMonth, int birthYear,
                int commingDay, int commingMonth, int commingYear,
                int vaccinationDay, int vaccinationMonth, 
                int vaccinationYear)
    : datumNaRaganje(birthDay, birthMonth, birthYear),
      datumNaDonesuvanjeVoZoo(commingDay, commingMonth, commingYear),
      datumNaPoslednaVakcinacija(vaccinationDay, vaccinationMonth,
                              vaccinationYear)
{
    int length = strlen(name);
    length = ( length < 30 ? length : 29 );
    strncpy(ime, name, length);
    ime[length] = '\0';
   
    tip = (type == 'c' || type == 'v' || type == 'p') ? type : 'c';
    pol = (gender == 'm' || gender == 'z') ? gender : 'm';
    
}


void findType(char type)
{
    if(type == 'c') cout << "Cicach";
    else if(type == 'v') cout << "Vlekach";
    else cout << "Ptica";
}

void Zivotno::prikaziPodatoci() const
{
    cout << "Zivotnoto se vika: " << ime <<
        "\nPol: " << pol << 
        "\nTip: ";
    findType(tip);
    cout << "\nDatum na raganje: ";
    datumNaRaganje.print();
    cout << "Datum na pristiganje: ";
    datumNaDonesuvanjeVoZoo.print();
    cout << "Datum na posledna vakcinacija: ";
    datumNaPoslednaVakcinacija.print();
}

int Zivotno::presmetajVakcinacija()
{
     static const int daysPerMonth[13] = 
      {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Momenatlniot datum
    time_t t = time(0);  
    tm* now = localtime(&t);
    // +1900 deka vraka godini posle 1900 god.
    int currentYear = now->tm_year + 1900;
    //+ 1 deka vraka meseci od 0-11 
    int currentMonth = now->tm_mon + 1;
    int currentDay = now->tm_mday;
    int vaccinationDay = datumNaPoslednaVakcinacija.getDay();
    int vaccinationMonth = datumNaPoslednaVakcinacija.getMonth();
    int vaccinationYear = datumNaPoslednaVakcinacija.getYear();

    if(tip == 'c')
    {
        // +1 deka treba na sekoja godina da se vakciniraat
        vaccinationYear += 1; 
        int daysLeft = ((vaccinationYear * 365) + (daysPerMonth[vaccinationMonth] + vaccinationMonth) + 
            vaccinationDay) - ((currentYear * 365) + (daysPerMonth[currentMonth] + currentMonth) + 
            currentDay);
        if(daysLeft <= 7 && daysLeft >= 0) return 1;
    }
    else if(tip == 'p')
    {
        // proverka dali + 6 meseci ke preminat vo nova godina
        if(vaccinationMonth + 6 <= 12) vaccinationMonth += 6;
        else
        {
            vaccinationYear += 1;
            vaccinationMonth = (vaccinationMonth + 6) % 12;
        }
        int daysLeft = ((vaccinationYear * 365) + (daysPerMonth[vaccinationMonth] + vaccinationMonth) + 
            vaccinationDay) - ((currentYear * 365) + (daysPerMonth[currentMonth] + currentMonth) + 
            currentDay);
        if(daysLeft <= 7 && daysLeft >= 0) return 1;
    }
    else if(tip == 'v')
    {
        if(vaccinationMonth + 8 <= 12) vaccinationMonth += 8;
        else
        {
            vaccinationYear += 1;
            vaccinationMonth = (vaccinationMonth + 8) % 12;
        }
        int daysLeft = ((vaccinationYear * 365) + (daysPerMonth[vaccinationMonth] + vaccinationMonth) + 
            vaccinationDay) - ((currentYear * 365) + (daysPerMonth[currentMonth] + currentMonth) + 
            currentDay);
        if(daysLeft <= 7 && daysLeft >= 0) return 1;
    }

    return 0;
}


