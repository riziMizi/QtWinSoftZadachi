#ifndef PRAVOAGOLNIK_H
#define PRAVOAGOLNIK_H
#include <iostream>

using namespace std;

class Pravoagolnik {
public:
    Pravoagolnik();
    Pravoagolnik(double, double);
    bool operator <(const Pravoagolnik &);
    friend ostream &operator<<(ostream&, 
                    const Pravoagolnik &);
    double getSirina() const {return sirina;}
    double getDolzina() const {return dolzina;}
private:
    double sirina;
    double dolzina;
};

#endif