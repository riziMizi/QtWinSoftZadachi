#ifndef DROPKI_H
#define DROPKI_H

class Dropki {
public:
    Dropki(int = 0, int = 1);
    void setValues(int, int);
    int getBroitel() const {return broitel;}
    int getImenitel() const {return imenitel;}
    Dropki operator+ (Dropki fraction);
    Dropki operator+ (int number);
    Dropki operator- (Dropki fraction);
    Dropki operator- (int number);
    Dropki operator* (Dropki fraction);
    Dropki operator* (int number);
    Dropki operator/ (Dropki fraction);
    Dropki operator/ (int number);
    void printFractionAsString();
    float printFractionAsFloat();

private:
    int broitel;
    int imenitel;
};

#endif
