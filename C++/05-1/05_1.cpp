#include <iostream>

using namespace std;

#include "Zivotno.h"

int instructions();
Zivotno vnesiZivotno();

int main()
{
    int choise;
    Zivotno arrayOfZivotnni[100];
    int i;
    int counter = 0;

    while((choise = instructions()) != 6)
    {
        switch(choise)
        {
            case 1:
                {
                    Zivotno newZivotno;
                    newZivotno = vnesiZivotno();
                    arrayOfZivotnni[counter++] = newZivotno;
                    cout << "Uspesno e vneseno zivotnoto.\n";
                    break;
                }
            case 2:
                {
                   cout << "Vo zooloskata ima " << counter <<
                        " zivotni.\n";
                    break;
                }
            case 3:
                {
                    char type;
                    cout << "Vnesi tip(c - cicachi, v - vlekachi, p - ptici): ";
                    cin >> type;
                    int noAnimals = 0;
                    for(i = 0; i < counter; ++i)
                    {
                        if(arrayOfZivotnni[i].getTip() == type)
                        {
                            noAnimals = 1;
                            arrayOfZivotnni[i].prikaziPodatoci();
                        }
                    }
                    if(noAnimals == 0) cout << "\nNema zivotni od ovoj tip." << endl;
                    break;
                }
            case 4:
                {
                    if(counter == 0) cout << "\nNema zivotni vo zooloskata." << endl;
                    else
                    {
                         for(i = 0; i < counter; ++i)
                         {
                            arrayOfZivotnni[i].prikaziPodatoci(); 
                         }
                    }
                    break;
                }
            case 5:
                {
                    int noAnimals = 0;
                    for(i = 0; i < counter; ++i)
                    {
                        if(arrayOfZivotnni[i].presmetajVakcinacija())
                        {
                            noAnimals = 1;
                            arrayOfZivotnni[i].prikaziPodatoci();
                        }
                    }
                    if(noAnimals == 0)
                        cout << "Nema zivotni za vakcinacija." << endl;
                    break;
                }

            default:
                cout << "Vnesovte pogresen broj " << endl;
                break;
        }
    }
    return 0;
}

int instructions()
{
    int choise;
    cout<<"Izberi broj: \n"
        "1 - Dodadi novo zivotno.\n"
        "2 - Priakzi brojna sostojba.\n"
        "3 - Prikazi zivotni od dadena grupa .\n"
        "4 - Prikazi site zivotni.\n"
        "5 - Prikazi zivotni za vakcinacija.\n"
        "6 - Za kraj. \n";

    cin >> choise;
    return choise;
}

Zivotno vnesiZivotno()
{
    char name[30];
    char type;
    char gender;
    int birthDay, birthMonth, birthYear;
    int commingDay, commingMonth, commingYear;
    int vaccinationDay, vaccinationMonth, vaccinationYear;

    cout << "Vnesi ime na zivotnoto: ";
    cin.ignore();
    cin.getline(name, 30);
    cout << "Vnesi tip(c - cicachi, v - vlekachi, p - ptici): ";
    cin >> type;
    cout << "Vnesi pol(m - mashki, z - zhenski): ";
    cin >> gender;
    cout << "Vnesi datum na raganje na zivotnoto(den mesec godina): ";
    cin >> birthDay >> birthMonth >> birthYear;
    cout << "Vnesi datum na doaganje na zivotnoto(den mesec godina): ";
    cin >> commingDay >> commingMonth >> commingYear;
    cout << "Vnesi datum na posledna vakcinacija na " 
            "zivotnoto(den mesec godina): ";
    cin >> vaccinationDay >> vaccinationMonth >> vaccinationYear;

    Zivotno newZivotno(name, type, gender, 
                      birthDay, birthMonth, birthYear,
                      commingDay, commingMonth, commingYear,
                      vaccinationDay, vaccinationMonth, vaccinationYear);
    return newZivotno;
}
