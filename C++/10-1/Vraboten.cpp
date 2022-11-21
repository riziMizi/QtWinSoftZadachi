#include <iostream>
#include <cstring>

using namespace std;

#include "Vraboten.h"

Vraboten::Vraboten(){}

Vraboten::Vraboten(char *ime, char *prezime,
                    int godinaNaVrabotuvanje)
{
    this->ime = new char[strlen(ime) + 1];
    strcpy(this->ime, ime);
    this->prezime = new char[strlen(prezime) + 1];
    strcpy(this->prezime, prezime);
    this->godinaNaVrabotuvanje = godinaNaVrabotuvanje;
}

Vraboten Vraboten::postaviVraboten()
{
    char ime[30];
    char prezime[30];
    int godinaVrabotuvanje;

    cout << "Vnesi ime: ";
    cin >> ime;
    cout << "Vnesi prezime: ";
    cin >> prezime;
    cout << "Vnesi godina na vrabotuvanje: ";
    cin >> godinaVrabotuvanje;
    return Vraboten(ime, prezime, godinaVrabotuvanje);
}

void Vraboten::prikaziPodatociVraboten() const
{
    cout << "Ime: " << ime <<
        "\nPrezime: " << prezime <<
        "\nGodina na vrabotuvanje: " << 
        godinaNaVrabotuvanje << endl;
}
