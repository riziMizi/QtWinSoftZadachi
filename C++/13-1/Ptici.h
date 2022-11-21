#ifndef PTICI_H
#define PTICI_H

#include "Zivotno.h"

class Ptici: public Zivotno{
public:
    Ptici();
    Ptici(char *, char, char, 
        int, int, int,
        int, int, int,
        int, int, int);
    void prikaziPodatoci() const;
    bool presmetajVakcinacija();
    Ptici postavi();
    char getLetac() const;
private:
    char letac;
};

#endif