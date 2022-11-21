#ifndef ARTIKL_H
#define ARTIKL_H

#include "Datum.h"

class Artikl {
public:
    Artikl();
    Artikl(char *, int, int, 
            int, int, int);
    void prikaziPodatociArtikl() const;
    void setImeArtikl(char *);
    void setGolemina(int);
    void setCena(int);
    char* getImeArtikl() const;
    int getGolemina() const;
    int getCena() const;
    Datum getDatumDonesenVoProdavnica() const;
private:
    char *imeArtikl;
    int golemina;
    int cena;
    Datum datumDonesenVoProdavnica;
};

#endif