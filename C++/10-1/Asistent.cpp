#include <iostream>
#include <cstring>

using namespace std;

#include "Asistent.h"

Asistent::Asistent(){}

Asistent::Asistent(char *ime, char *prezime,
            int godinaNaVrabotuvanje, char *zvanje,
            char *mentor, int brojPredmeti)
    :Vraboten(ime, prezime, godinaNaVrabotuvanje)
{
    this->zvanje = new char[strlen(zvanje) + 1];
    strcpy(this->zvanje, zvanje);
    this->mentor = new char[strlen(mentor) + 1];
    strcpy(this->mentor, mentor);
    this->brojPredmeti = brojPredmeti;
}

Asistent Asistent::postaviAsistent()
{
    char ime[30];
    char prezime[30];
    char zvanje[30];
    char mentor[30];
    int godinaVrabotuvanje;
    int brojPredmeti;

    cout << "Vnesi ime: ";
    cin >> ime;
    cout << "Vnesi prezime: ";
    cin >> prezime;
    cout << "Vnesi godina na vrabotuvanje: ";
    cin >> godinaVrabotuvanje;
    cout << "Vnesi zvanje: ";
    cin >> zvanje;
    cout << "Vnesi mentor: ";
    cin >> mentor;
    cout << "Vnesi broj na predmeti: ";
    cin >> brojPredmeti;
    return Asistent(ime, prezime, godinaVrabotuvanje,
                zvanje, mentor, brojPredmeti);
}

void Asistent::prikaziPodatociAsistent() const
{
    prikaziPodatociVraboten();
    cout << "Zvanje: " << zvanje <<
        "\nMentor: " << mentor <<
        "\nBroj na predmeti: " << 
        brojPredmeti << endl;
}