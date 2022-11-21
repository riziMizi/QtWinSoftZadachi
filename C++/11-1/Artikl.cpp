#include <iostream>
#include <cstring>

using namespace std;

#include "Artikl.h"

Artikl::Artikl(){}

Artikl::Artikl(char *imeArtikl, int golemina, 
        int cena, int den, int mesec, int godina)
        :datumDonesenVoProdavnica(den, mesec, godina)
{
    this->imeArtikl = new char[strlen(imeArtikl) + 1];
    strcpy(this->imeArtikl, imeArtikl);
    this->golemina = golemina;
    this->cena = cena;
}

void Artikl::prikaziPodatociArtikl() const
{
    cout << "Ime na artiklot: " << getImeArtikl() <<
        "\nGolemina: " << getGolemina() <<
        "\nCena: " << getCena() <<
        "\nDonesen vo prodavnica: ";
    getDatumDonesenVoProdavnica().print();
}

char* Artikl::getImeArtikl() const
{
    return imeArtikl;
}

void Artikl::setImeArtikl(char *imeArtikl)
{
    this->imeArtikl = new char[strlen(imeArtikl) + 1];
    strcpy(this->imeArtikl, imeArtikl);
}

int Artikl::getGolemina() const
{
    return golemina;
}

void Artikl::setGolemina(int golemina)
{
    this->golemina = golemina;
}

int Artikl::getCena() const
{
    return cena;
}

void Artikl::setCena(int cena)
{
    this->cena = cena;
}

Datum Artikl::getDatumDonesenVoProdavnica() const
{
    return datumDonesenVoProdavnica;
}


