#include <iostream>
#include <ctime>

using namespace std;

#include "Ptici.h"

Ptici::Ptici() {}

Ptici::Ptici(char *name, char gender, char fly,
                int birthDay, int birthMonth, int birthYear,
                int commingDay, int commingMonth, int commingYear,
                int vaccinationDay, int vaccinationMonth, 
                int vaccinationYear)
  : Zivotno(name, gender, birthDay, birthMonth, birthYear,
            commingDay, commingMonth, commingYear,
            vaccinationDay, vaccinationMonth, vaccinationYear)
    {
         letac = (fly == 'd' || fly == 'n') ? fly : 'n';
    }


void Ptici::prikaziPodatoci() const
{
    prikaziPodatociZivotno();
    cout << "Letac: " << getLetac() << endl;
}

bool Ptici::presmetajVakcinacija()
{
    static const int daysPerMonth[13] = 
      {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    time_t t = time(0);  
    tm* now = localtime(&t);
    int currentYear = now->tm_year + 1900;
    int currentMonth = now->tm_mon + 1;
    int currentDay = now->tm_mday;
    int vaccinationDay = getDatumNaPoslednaVakcinacija().getDay();
    int vaccinationMonth = getDatumNaPoslednaVakcinacija().getMonth();
    int vaccinationYear = getDatumNaPoslednaVakcinacija().getYear();

    if(vaccinationMonth + 6 <= 12) vaccinationMonth += 6;
    else
    {
        vaccinationYear += 1;
        vaccinationMonth = (vaccinationMonth + 6) % 12;
    }

    int daysLeft = ((vaccinationYear * 365) + (daysPerMonth[vaccinationMonth] + vaccinationMonth) + 
            vaccinationDay) - ((currentYear * 365) + (daysPerMonth[currentMonth] + currentMonth) + 
            currentDay);
        if(daysLeft <= 7) return true;

    return false;
}

Ptici Ptici::postavi()
{
    char name[30];
    char gender;
    char fly;
    int birthDay, birthMonth, birthYear;
    int commingDay, commingMonth, commingYear;
    int vaccinationDay, vaccinationMonth, vaccinationYear;

    cout << "Vnesi ime na zivotnoto: ";
    cin.ignore();
    cin.getline(name, 30);
    cout << "Vnesi pol(m - mashki, z - zhenski): ";
    cin >> gender;
    cout << "Vnesi dali e letac(d - da, n - ne): ";
    cin >> fly;
    cout << "Vnesi datum na raganje na zivotnoto(den mesec godina): ";
    cin >> birthDay >> birthMonth >> birthYear;
    cout << "Vnesi datum na doaganje na zivotnoto(den mesec godina): ";
    cin >> commingDay >> commingMonth >> commingYear;
    cout << "Vnesi datum na posledna vakcinacija na " 
            "zivotnoto(den mesec godina): ";
    cin >> vaccinationDay >> vaccinationMonth >> vaccinationYear;

    return Ptici(name, gender, fly, 
                birthDay, birthMonth, birthYear,
                commingDay, commingMonth, commingYear,
                vaccinationDay, vaccinationMonth, vaccinationYear);
}


char Ptici::getLetac() const
{
    return letac;
}