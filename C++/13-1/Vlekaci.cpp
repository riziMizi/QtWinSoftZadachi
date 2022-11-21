#include <iostream>
#include <ctime>

using namespace std;

#include "Vlekaci.h"

Vlekaci::Vlekaci() : 
  datumNaSlednaVakcinacija(1, 1, 2000) {}

Vlekaci::Vlekaci(char *name, char gender,
                int birthDay, int birthMonth, int birthYear,
                int commingDay, int commingMonth, int commingYear,
                int vaccinationDay, int vaccinationMonth, 
                int vaccinationYear, int nextVaccinationDay, 
                int nextVaccinationMonth, int nextVaccinationYear)
  : Zivotno(name, gender, birthDay, birthMonth, birthYear,
            commingDay, commingMonth, commingYear,
            vaccinationDay, vaccinationMonth, vaccinationYear),
    datumNaSlednaVakcinacija(nextVaccinationDay, 
            nextVaccinationMonth, nextVaccinationYear) {}


void Vlekaci::prikaziPodatoci() const
{
    prikaziPodatociZivotno();
    cout << "Datum na sledna vakcinacija: ";
    getDatumNaSlednaVakcinacija().print();
}

bool Vlekaci::presmetajVakcinacija()
{
     static const int daysPerMonth[13] = 
      {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    time_t t = time(0);  
    tm* now = localtime(&t);
    int currentYear = now->tm_year + 1900;
    int currentMonth = now->tm_mon + 1;
    int currentDay = now->tm_mday;
    int vaccinationDay = getDatumNaSlednaVakcinacija().getDay();
    int vaccinationMonth = getDatumNaSlednaVakcinacija().getMonth();
    int vaccinationYear = getDatumNaSlednaVakcinacija().getYear();

    int daysLeft = ((vaccinationYear * 365) + 
    (daysPerMonth[vaccinationMonth] + vaccinationMonth) + vaccinationDay) - 
    ((currentYear * 365) + (daysPerMonth[currentMonth] + currentMonth) + 
            currentDay);
    if(daysLeft <= 7  && daysLeft >= 0)
        return true;
        
    return false;
}

Vlekaci Vlekaci::postavi()
{
    char name[30];
    char gender;
    int birthDay, birthMonth, birthYear;
    int commingDay, commingMonth, commingYear;
    int vaccinationDay, vaccinationMonth, vaccinationYear;
    int nextVaccinationDay, nextVaccinationMonth, nextVaccinationYear;

    cout << "Vnesi ime na zivotnoto: ";
    cin.ignore();
    cin.getline(name, 30);
    cout << "Vnesi pol(m - mashki, z - zhenski): ";
    cin >> gender;
    cout << "Vnesi datum na raganje na zivotnoto(den mesec godina): ";
    cin >> birthDay >> birthMonth >> birthYear;
    cout << "Vnesi datum na doaganje na zivotnoto(den mesec godina): ";
    cin >> commingDay >> commingMonth >> commingYear;
    cout << "Vnesi datum na posledna vakcinacija na " 
            "zivotnoto(den mesec godina): ";
    cin >> vaccinationDay >> vaccinationMonth >> vaccinationYear;
    cout << "Vnesi datum na sledna vakcinacija na " 
            "zivotnoto(den mesec godina): ";
    cin >> nextVaccinationDay >> nextVaccinationMonth >> nextVaccinationYear;

    return Vlekaci(name, gender, 
                      birthDay, birthMonth, birthYear,
                      commingDay, commingMonth, commingYear,
                      vaccinationDay, vaccinationMonth, vaccinationYear,
                      nextVaccinationDay, nextVaccinationMonth, nextVaccinationYear);
}

Datum Vlekaci::getDatumNaSlednaVakcinacija() const
{
    return datumNaSlednaVakcinacija;
}