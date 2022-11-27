#ifndef PRAVOAGOLNIK_H
#define PRAVOAGOLNIK_H

class Pravoagolnik{
public:
    Pravoagolnik(int = 1, int = 1);
    int getPlostina() const;
    Pravoagolnik postavi();

private:
    int sirina;
    int dolzina;
    int plostina;
};

#endif