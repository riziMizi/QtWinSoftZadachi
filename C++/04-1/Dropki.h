#ifndef DROPKI_H
#define DROPKI_H

class Dropki {
public:
    Dropki(int = 0, int = 1);
    void setValues(int, int);
    int getBroitel() {return broitel;}
    int getImenitel() {return imenitel;}
    void adding(Dropki fraction);
    void subtracting(Dropki fraction);
    void multiplication(Dropki fraction);
    void division(Dropki fraction);
    void printFractionAsString();
    float printFractionAsFloat();

private:
    int broitel;
    int imenitel;
};

#endif
