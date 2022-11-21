#ifndef COVEK_H
#define COVEK_H

using namespace std;
#include <string>

class Covek {
public:
    Covek();
    Covek(string, string, string, string);
    string getName() const {return this->name;}
    string getSurname() const {return this->surname;}
    void print() const;
private:
    string name;
    string surname;
    string address;
    string phone;
};

#endif