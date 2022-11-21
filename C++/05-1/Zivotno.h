#ifndef ZIVOTNO_H
#define ZIVOTNO_H

#include "Datum.h"

class Zivotno {
public:
    Zivotno();
    Zivotno(char *, char, char, 
        int, int, int,
        int, int, int,
        int, int, int);
    void prikaziPodatoci() const;
    int presmetajVakcinacija();
    char getTip() const {return tip;}
private:
    char ime[30];
    char tip;
    char pol;
    Datum datumNaRaganje;
    Datum datumNaDonesuvanjeVoZoo;
    Datum datumNaPoslednaVakcinacija;
};

#endif