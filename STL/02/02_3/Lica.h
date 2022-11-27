#ifndef LICA_H
#define LICA_H

#include<string>

using namespace std;

template<class T>
class Lica{
public:
    Lica();
    Lica(string, long, int, string, T);
    Lica<T> postavi();
    void pecati() const;
    string getImePrezime() const {return imePrezime;}
    long getMaticenBroj() const {return maticenBroj;}
    int getVozrast() const {return vozrast;}
    string getAdresa() const {return adresa;}
    T getKod() const {return kod;}
private:
    string imePrezime;
    long maticenBroj;
    int vozrast;
    string adresa;
    T kod;
};

#endif