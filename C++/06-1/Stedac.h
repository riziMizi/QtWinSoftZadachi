#ifndef STEDAC_H
#define STEDAC_H

#include "Covek.h"

class Stedac {
public:
    Stedac();
    ~Stedac();
    Stedac(string, string, string, string, int, int);
    void print() const;
    static int getKamata();
    static int getBrojStedaci();
private:
    Covek lice;
    int bilans;
    int kredit;

    static int kamata;
    static int brojStedaci;
};

#endif