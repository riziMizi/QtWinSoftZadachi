#ifndef DATUM_H
#define DATUM_H

class Datum {
public:
    Datum(int = 1, int = 1, int = 2000);
    void print() const;
    int getDay() const {return day;}
    int getMonth() const {return month;}
    int getYear() const {return year;}
private:
    int day;
    int month;
    int year;

    int checkDay(int);
};

#endif