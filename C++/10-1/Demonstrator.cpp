#include <iostream>
#include <cstring>

using namespace std;

#include "Demonstrator.h"

Demonstrator::Demonstrator(){}

Demonstrator::Demonstrator(char *ime, char *prezime,
            int godinaNaVrabotuvanje, char *rabotnoVremeOd,
            char *rabotnoVremeDo)
    :Vraboten(ime, prezime, godinaNaVrabotuvanje)
{
    this->rabotnoVremeOd = new char[strlen(rabotnoVremeOd) + 1];
    strcpy(this->rabotnoVremeOd, rabotnoVremeOd);
    this->rabotnoVremeDo = new char[strlen(rabotnoVremeDo) + 1];
    strcpy(this->rabotnoVremeDo, rabotnoVremeDo);
}

Demonstrator Demonstrator::postaviDemonstrator()
{
    char ime[30];
    char prezime[30];
    char rabotnoVremeOd[10];
    char rabotnoVremeDo[10];
    int godinaVrabotuvanje;
   
    cout << "Vnesi ime: ";
    cin >> ime;
    cout << "Vnesi prezime: ";
    cin >> prezime;
    cout << "Vnesi godina na vrabotuvanje: ";
    cin >> godinaVrabotuvanje;
    cout << "Vnesi od kolku raboti: ";
    cin >> rabotnoVremeOd;
    cout << "Vnesi do kolku raboti: ";
    cin >> rabotnoVremeDo;
    return Demonstrator(ime, prezime, godinaVrabotuvanje,
                rabotnoVremeOd, rabotnoVremeDo);
}

void Demonstrator::prikaziPodatociDemonstrator() const
{
    prikaziPodatociVraboten();
    cout << "Rabotno vreme: " << rabotnoVremeOd <<
        " - " << rabotnoVremeDo << endl;
}