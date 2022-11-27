#ifndef KVADRAT_H
#define KVADRAT_H
#include <iostream>

using namespace std;

class Kvadrat {
public:
    Kvadrat();
    Kvadrat(double);
    bool operator <(const Kvadrat &);
    friend ostream &operator<<(ostream&, 
                    const Kvadrat &);
    double getStrana() const {return strana;}
private:
    double strana;
};

#endif