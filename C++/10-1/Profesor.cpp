#include <iostream>
#include <cstring>

using namespace std;

#include "Profesor.h"

Profesor::Profesor(){}

Profesor::Profesor(char *ime, char *prezime,
            int godinaNaVrabotuvanje, char *zvanje,
            char *oblast, int brojPredmeti)
    :Vraboten(ime, prezime, godinaNaVrabotuvanje)
{
    this->zvanje = new char[strlen(zvanje) + 1];
    strcpy(this->zvanje, zvanje);
    this->oblast = new char[strlen(oblast) + 1];
    strcpy(this->oblast, oblast);
    this->brojPredmeti = brojPredmeti;
}

Profesor Profesor::postaviProfesor()
{
    char ime[30];
    char prezime[30];
    char zvanje[30];
    char oblast[30];
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
    cout << "Vnesi oblast: ";
    cin >> oblast;
    cout << "Vnesi broj na predmeti: ";
    cin >> brojPredmeti;
    return Profesor(ime, prezime, godinaVrabotuvanje,
                zvanje, oblast, brojPredmeti);
}

void Profesor::prikaziPodatociProfesor() const
{
    prikaziPodatociVraboten();
    cout << "Zvanje: " << zvanje <<
        "\nOblast: " << oblast <<
        "\nBroj na predmeti: " << 
        brojPredmeti << endl;
}