#ifndef KVADRAT_H
#define KVADRAT_H

class Kvadrat{
public:
    Kvadrat(int = 1);
    int getPlostina() const;
    Kvadrat postavi();

private:
    int strana;
    int plostina;
};

#endif