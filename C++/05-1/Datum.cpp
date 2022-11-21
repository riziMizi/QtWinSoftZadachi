#include <iostream>

using namespace std;

#include "Datum.h"

Datum::Datum(int dd, int mm, int yy)
{
    if (mm > 0 && mm <= 12)
      month = mm;
    else 
    {
      month = 1;
    }

    if(yy > 2000 && yy < 2025)
     year = yy;
    else
    {
      year = 2000;
    }
    
   day = checkDay(dd);           
}

void Datum::print() const
{
    cout << day << "/" << month << 
         "/" << year << endl;
}

int Datum::checkDay(int dd)
{
    static const int daysPerMonth[13] = 
      {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (dd > 0 && dd <= daysPerMonth[month])
      return dd;

    if (month == 2 && 
        dd == 29 &&
        (year % 400 == 0 ||                      
         (year % 4 == 0 && year % 100 != 0)))
      return dd;

   return 1;
}