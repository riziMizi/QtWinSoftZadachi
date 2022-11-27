#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <exception>
#include <iomanip>

using namespace std;

#include "Kvadrat.h"
#include "Pravoagolnik.h"

int main()
{
    vector<Kvadrat> firstKvadrati;
    vector<Pravoagolnik> firstPravoagolnici;
    vector<Kvadrat> secondKvadrati;
    vector<Pravoagolnik> secondPravoagolnici;
    vector<Kvadrat> unionKvadrati;
    vector<Kvadrat> intersectionKvadrati;
    vector<Pravoagolnik> unionPravoagolnici;
    vector<Pravoagolnik> intersectionPravoagolnici;
    double stranaKvadrat;
    double sirinaPravoagolnik, dolzinaPravoagolnik;
    int tip;

    ostream_iterator<Kvadrat> outputKvadrat(cout, "\n");
    ostream_iterator<Pravoagolnik> outputPravoagolnik(cout, "\n");

    ifstream readPrva("prva.txt", ios::in);

    if(!readPrva)
      throw logic_error("Ne postoi datoteka prva.txt.");
    
    try
    {
        while(readPrva >> tip)
        {
            if(tip == 1)
            {
                readPrva >> sirinaPravoagolnik >> dolzinaPravoagolnik;

                firstPravoagolnici.push_back(
                Pravoagolnik(sirinaPravoagolnik, dolzinaPravoagolnik));
            }
            else if(tip == 2)
            {
                readPrva >> stranaKvadrat;
                firstKvadrati.push_back(Kvadrat(stranaKvadrat));
            }
            else
            {
                throw 0;
            }
        }
    }
    catch(int)
    {  
        cout << "Pogresen podatok vo datoteka prva.txt";
        readPrva.close();
    }

    cout << "Kvadrati od prvata datoteka: \n";
    copy(firstKvadrati.begin(), firstKvadrati.end(), outputKvadrat);

    cout << "Pravoagolnici od prvata datoteka: \n";
    cout << "Sirina" << setw(15) << "Dolzina" << endl; 
    copy(firstPravoagolnici.begin(), firstPravoagolnici.end(), 
                                            outputPravoagolnik);
    readPrva.close();

    ifstream readVtora("vtora.txt", ios::in);

    if(!readVtora)
      throw logic_error("Ne postoi datoteka vtora.txt.");
    
    try
    {
        while(readVtora >> tip)
        {
            if(tip == 1)
            {
                readVtora >> sirinaPravoagolnik >> dolzinaPravoagolnik;

                secondPravoagolnici.push_back(
                Pravoagolnik(sirinaPravoagolnik, dolzinaPravoagolnik));
            }
            else if(tip == 2)
            {
                readVtora >> stranaKvadrat;
                secondKvadrati.push_back(Kvadrat(stranaKvadrat));
            }
            else
            {
                throw 0;
            }
        }
    }
    catch(int)
    {  
        cout << "Pogresen podatok vo datoteka vtora.txt";
        readVtora.close();
    }

    cout << "Kvadrati od vtorata datoteka: \n";
    copy(secondKvadrati.begin(), secondKvadrati.end(), outputKvadrat);

    cout << "Pravoagolnici od vtorata datoteka: \n";
    cout << "Sirina" << setw(15) << "Dolzina" << endl; 
    copy(secondPravoagolnici.begin(), secondPravoagolnici.end(), 
                                            outputPravoagolnik);
    readVtora.close();

    sort(firstKvadrati.begin(), firstKvadrati.end());
    sort(secondKvadrati.begin(), secondKvadrati.end());
    sort(firstPravoagolnici.begin(), firstPravoagolnici.end());
    sort(secondPravoagolnici.begin(), secondPravoagolnici.end());

    set_union(firstKvadrati.begin(), firstKvadrati.end(),
              secondKvadrati.begin(), secondKvadrati.end(),
              back_inserter(unionKvadrati));
    
    cout << "Unija na kvadrati: \n";
    copy(unionKvadrati.begin(), unionKvadrati.end(), 
                                      outputKvadrat);

    set_intersection(firstKvadrati.begin(), firstKvadrati.end(),
              secondKvadrati.begin(), secondKvadrati.end(),
              back_inserter(intersectionKvadrati));

    cout << "Presek na kvadrati: \n"; 
    copy(intersectionKvadrati.begin(), 
        intersectionKvadrati.end(), outputKvadrat);


    set_union(firstPravoagolnici.begin(), firstPravoagolnici.end(),
              secondPravoagolnici.begin(), secondPravoagolnici.end(),
              back_inserter(unionPravoagolnici));
    
    cout << "Unija na pravoagilnici: \n";
    cout << "Sirina" << setw(15) << "Dolzina" << endl; 
    copy(unionPravoagolnici.begin(), unionPravoagolnici.end(), 
                                            outputPravoagolnik);

    set_intersection(firstPravoagolnici.begin(), firstPravoagolnici.end(),
              secondPravoagolnici.begin(), secondPravoagolnici.end(),
              back_inserter(intersectionPravoagolnici));

    cout << "Presek na pravoagilnici: \n";
    cout << "Sirina" << setw(15) << "Dolzina" << endl; 
    copy(intersectionPravoagolnici.begin(), 
        intersectionPravoagolnici.end(), outputPravoagolnik);

    return 0;
}