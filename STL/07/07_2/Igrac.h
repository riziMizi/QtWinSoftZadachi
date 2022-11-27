#ifndef IGRAC_H
#define IGRAC_H

#include <string>
#include "Karta.h"

using namespace std;

class Igrac {
public:
    Igrac();
    void putCard(Karta karta);
    int countSum(int);
    void printCards() const;
private:
    int counter;
    Karta cards[30];
};

#endif