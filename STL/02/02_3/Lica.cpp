#include <iostream>
#include <string>

using namespace std;

#include "Lica.h"

template<class T>
Lica<T>::Lica() {}

template<class T>
Lica<T>::Lica(string imePrezime, long maticenBroj,
            int vozrast, string adresa, T kod) 
{
    this->imePrezime = imePrezime;
    this->maticenBroj = maticenBroj;
    this->vozrast = vozrast;
    this->adresa = adresa;
    this->kod = kod;
}

template<class T>
Lica<T> Lica<T>::postavi()
{
    string imePrezimeLice;
    long maticenBrojLice;
    int vozrastLice;
    string adresaLice;
    T kodLice;
    cout << "Vnesi ime i prezime: ";
    cin.ignore();
    getline(cin, imePrezimeLice);
    cout << "Vnesi maticen broj: ";
    cin >> maticenBrojLice;
    cout << "Vnesi vozrast: ";
    cin >> vozrastLice;
    cout << "Vnesi adresa: ";
    cin.ignore();
    getline(cin, adresaLice);
    cout << "Vnesi kod: ";
    cin >> kodLice;

    return Lica(imePrezimeLice, maticenBrojLice,
        vozrastLice, adresaLice, kodLice);
}

template<class T>
void Lica<T>::pecati() const
{
    cout << "Ime i prezime: " << getImePrezime() <<
        "\nMaticen broj: " << getMaticenBroj() <<
        "\nVozrast: " << getVozrast() <<
        "\nAdresa: " << getAdresa() <<
        "\nKod: " << getKod() << endl;
}

