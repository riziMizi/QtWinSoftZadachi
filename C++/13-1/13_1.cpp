#include <iostream>

using namespace std;

#include "Vlekaci.h"
#include "Ptici.h"
#include "Cicaci.h"

int instructions();

int main()
{
    int choise;
    Vlekaci arrayOfVlekaci[100];
    Ptici arrayOfPtici[100];
    Cicaci arrayOfCicaci[100];
    int counterVlekaci = 0;
    int counterPtici = 0;
    int counterCicaci = 0;

    while((choise = instructions()) != 6)
    {
        switch(choise)
        {
            case 1:
            {
                int type;
                cout << "Izberi broj\n(1 - vlekaci)\n"
                        "(2 - ptici)\n(3 - cicaci)\n";
                cin >> type;
                if(type == 1)
                {
                    Vlekaci newVlekac = newVlekac.postavi();
                    arrayOfVlekaci[counterVlekaci++] = newVlekac;
                    cout << "Uspesno vnesen vlekac.\n";
                    break;

                }
                else if(type == 2)
                {
                    Ptici newPtica = newPtica.postavi();
                    arrayOfPtici[counterPtici++] = newPtica;
                    cout << "Uspesno vnesena ptica.\n";
                    break;
                }
                    else if(type == 3)
                {
                    Cicaci newCicac = newCicac.postavi();
                    arrayOfCicaci[counterCicaci++] = newCicac;
                    cout << "Uspesno vnesen cicac.\n";
                    break;
                }
                else
                {
                    cout << "Vnesovte pogresen tip.\n";
                    break;
                }
            }
            case 2:
            {
                int vkupnoZivotni = counterVlekaci + 
                    counterPtici + counterCicaci;
                    cout << "Vo zooloskata ima " << vkupnoZivotni <<
                    " zivotni.\n";
                break;
            }
            case 3:
            {
                int type;
                cout << "Izberi broj\n(1 - vlekaci)\n"
                        "(2 - ptici)\n(3 - cicaci)\n";
                cin >> type;
                if(type == 1)
                {
                    if(counterVlekaci == 0)
                    {
                        cout << "Nemate vneseno vlekaci.\n";
                        break;
                    }
                    for(int i = 0; i < counterVlekaci; ++i)
                    {
                        cout << "\nVlekac " << i + 1 << endl;
                        arrayOfVlekaci[i].prikaziPodatoci();
                    }
                    break;
                }
                else if(type == 2)
                {
                    if(counterPtici == 0)
                    {
                        cout << "Nemate vneseno ptici.\n";
                        break;
                    }
                    for(int i = 0; i < counterPtici; ++i)
                    {
                        cout << "\nPtica " << i + 1 << endl;
                        arrayOfPtici[i].prikaziPodatoci();
                    }
                    break;
                }
                else if(type == 3)
                {
                    if(counterCicaci == 0)
                    {
                        cout << "Nemate vneseno cicaci.\n";
                        break;
                    }
                    for(int i = 0; i < counterCicaci; ++i)
                    {
                        cout << "\nCicac " << i + 1 << endl;
                        arrayOfCicaci[i].prikaziPodatoci();
                    }
                    break;
                }
                else
                {
                    cout << "Vnesovte pogresen broj.\n";
                    break;
                } 
            }
            case 4:
            {
                if(counterVlekaci == 0 && counterPtici == 0 && 
                    counterPtici == 0)
                {
                    cout << "Nema zivotni vo zooloskata.\n";
                    break;
                }
                for(int i = 0; i < counterVlekaci; ++i)
                {
                    cout << "\nVlekac " << i + 1 << endl;
                    arrayOfVlekaci[i].prikaziPodatoci();
                }
                for(int i = 0; i < counterPtici; ++i)
                {
                    cout << "\nPtica " << i + 1 << endl;
                    arrayOfPtici[i].prikaziPodatoci();
                }
                for(int i = 0; i < counterCicaci; ++i)
                {
                    cout << "\nCicac " << i + 1 << endl;
                    arrayOfCicaci[i].prikaziPodatoci();
                }
                break;
            }
            case 5:
            {
                int noAnimals = 0;
                if(counterVlekaci == 0 && counterPtici == 0 && 
                    counterPtici == 0)
                {
                    cout << "Nema zivotni vo zooloskata.\n";
                    break;
                }
                for(int i = 0; i < counterVlekaci; ++i)
                {
                    if(arrayOfVlekaci[i].presmetajVakcinacija())
                    {
                        cout << "\nVlekac " << i + 1 << endl;
                        arrayOfVlekaci[i].prikaziPodatoci();
                        noAnimals = 1;
                    } 
                }
                for(int i = 0; i < counterPtici; ++i)
                {
                    if(arrayOfPtici[i].presmetajVakcinacija())
                    {
                        cout << "\nPtica " << i + 1 << endl;
                        arrayOfPtici[i].prikaziPodatoci();
                        noAnimals = 1;
                    }  
                }
                for(int i = 0; i < counterCicaci; ++i)
                {
                    if(arrayOfCicaci[i].presmetajVakcinacija())
                    {
                        cout << "\nCicac " << i + 1 << endl;
                        arrayOfCicaci[i].prikaziPodatoci();
                        noAnimals = 1;
                    }  
                }
                if(noAnimals == 0)
                 cout << "Nema zivotni za vakcinacija.\n";
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
        "1 - Dodadi zivotno.\n"
        "2 - Prikazi kolku zivotni ima vo zooloskata.\n"
        "3 - Prikazi zivotni od dadena grupa.\n"
        "4 - Prikazi site zivotni.\n"
        "5 - Prikazi zivotni sto treba da se"
        " vakciniraat za edna nedela.\n"
        "6 - Za kraj.\n";
    cin >> choise;
    return choise;
}