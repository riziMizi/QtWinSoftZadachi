#include <iostream>

using namespace std;

#include "Lica.h"
#include "Lica.cpp"

int instructions();

template<class T>
void pecatiPole(T* arr, int size)
{
    for(int i = 0; i < size; ++i)
    {
        arr[i].pecati();
        cout << endl;
    }
}

int main()
{
    Lica<int> arrVraboten[100];
    Lica<string> arrKlienti[100];

    int counterVraboten = 0;
    int counterKlient = 0;
    int choise;

    while((choise = instructions()) != 5)
    {
        switch(choise)
        {
            case 1:
            {
                Lica<int> newVraboten;
                cout << "Vnesi vraboten: \n";
                arrVraboten[counterVraboten++] = newVraboten.postavi();
                cout << "Uspesno vnesen vraboten. \n";
                break;
            }
            case 2:
            {
                Lica<string> newKlient;
                cout << "Vnesi klient: \n";
                arrKlienti[counterKlient++] = newKlient.postavi();
                cout << "Uspesno vnesen klient. \n";
                break;
            }
            case 3:
            {
                pecatiPole(arrVraboten, counterVraboten);
                break;
            }
            case 4:
            {
                pecatiPole(arrKlienti, counterKlient);
                break;
            }
            default:
                cout << "Vnesovte pogresen broj.\n";
                break;
        }
    }

    return 0;
}

int instructions()
{
    int choise;
    cout<<"Izberi broj: \n"
        "1 - Vnesi vraboten.\n"
        "2 - Vnesi klient.\n"
        "3 - Prikazi lista vraboteni.\n"
        "4 - Prikazi lista klienti.\n"
        "5 - Za kraj.\n";
    cin >> choise;
    return choise;
}