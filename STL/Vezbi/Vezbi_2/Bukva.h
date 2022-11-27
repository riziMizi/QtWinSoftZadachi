#ifndef BUKVA_H
#define BUKVA_H
#include <iostream>

using namespace std;

class Bukva {
public:
    Bukva();
    Bukva(char);
    friend ostream &operator <<(ostream&, 
                    const Bukva &);
    char getBukva() const {return bukva;}
    char getPogodena() const {return pogodena;}
    void setPogodena();
private:
    char bukva;
    bool pogodena;
};

#endif