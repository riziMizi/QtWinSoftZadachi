#include <iostream>

using namespace std;

#include "Stedac.h"
#include "Covek.h"

int main()
{
    cout << "Brojot na stedaci iznesuva " << 
         Stedac::getBrojStedaci() << endl;
    

    Stedac *stedac1 = new Stedac(
        "bojan", "risteski", "doma", "09090909", 200, 400);

    Stedac *stedac2 = new Stedac(
        "pece", "pecov", "opa", "082342324", 500, 1000);
    
    stedac1->print();
    stedac2->print();

    cout << "Brojot na stedaci iznesuva " << 
         Stedac::getBrojStedaci() << endl;
    cout << "Godisnata kamata iznesuva: " << 
         Stedac::getKamata() << "%"<< endl;
    
    delete stedac1;
    stedac1 = 0;
    delete stedac2;
    stedac2 = 0;

    cout << "Brojot na stedaci iznesuva " << 
         Stedac::getBrojStedaci() << endl;

    return 0;
}