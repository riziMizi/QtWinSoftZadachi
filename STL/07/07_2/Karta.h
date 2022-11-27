#ifndef KARTA_H
#define KARTA_H

#include <string>

using namespace std;

class Karta {
public:
    Karta();
    Karta(int, string);
    int getNumber() const {return number;}
    string getColor() const {return color;}
    friend ostream &operator<<(ostream&, const Karta &);
private:
    int number;
    string color;
};

#endif