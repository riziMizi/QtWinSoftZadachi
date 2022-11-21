#ifndef VLEKACI_H
#define VLEKACI_H

#include "Datum.h"
#include "Zivotno.h"

class Vlekaci: public Zivotno {
public:
    Vlekaci();
    Vlekaci(char *, char, 
        int, int, int,
        int, int, int,
        int, int, int,
        int, int, int);
    void prikaziPodatoci() const;
    bool presmetajVakcinacija();
    Vlekaci postavi();
    Datum getDatumNaSlednaVakcinacija() const;
private:
    Datum datumNaSlednaVakcinacija;
};

#endif