#include <iostream>

using namespace std;

#include "Pantaloni.h"
#include "Kosuli.h"

int instructions();

int main()
{
    int choise;
    Pantaloni arrayOfPantaloni[100];
    Kosuli arrayOfKosuli[100];
    int counterPantaloni = 0;
    int counterKosuli = 0;

    while((choise = instructions()) != 5)
    {
        switch(choise)
        {
            case 1:
            {
                    int type;
                    cout << "Izberi broj\n(1 - Pantaloni)\n"
                            "(2 - Kosuli)\n";
                    cin >> type;
                    if(type == 1)
                    {
                        Pantaloni newPantaloni = newPantaloni.postaviPantaloni();
                        arrayOfPantaloni[counterPantaloni++] = newPantaloni;
                        cout << "Uspesno vnesen artikl.\n";
                        break;

                    }
                    else if(type == 2)
                    {
                        Kosuli newKosuli = newKosuli.postaviKosuli();
                        arrayOfKosuli[counterKosuli++] = newKosuli;
                        cout << "Uspesno vnesen artikl.\n";
                        break;
                    }
                    else
                    {
                        cout << "Vnesovte pogresen broj.\n";
                        break;
                    }
            }
            case 2:
            {
                    int type;
                    cout << "Izberi broj\n(1 - Pantaloni)\n"
                            "(2 - Kosuli)\n";
                    cin >> type;
                    if(type == 1)
                    {
                        if(counterPantaloni == 0)
                        {
                            cout << "Nemate vneseno pantaloni.\n";
                            break;
                        }
                        for(int i = 0; i < counterPantaloni; ++i)
                        {
                            cout << "\nPantaloni " << i + 1 << endl;
                            arrayOfPantaloni[i].prikaziPodatociPantaloni();
                        }
                        break;
                    }
                    else if(type == 2)
                    {
                       if(counterKosuli == 0)
                        {
                            cout << "Nemate vneseno kosuli.\n";
                            break;
                        }
                        for(int i = 0; i < counterKosuli; ++i)
                        {
                            cout << "\nKosuli " << i + 1 << endl;
                            arrayOfKosuli[i].prikaziPodatociKosuli();
                        }
                        break;
                    }
                    else
                    {
                        cout << "Vnesovte pogresen broj.\n";
                        break;
                    } 
            }
            case 3:
            {
                int totalPrice = 0;
                if(counterKosuli == 0 && counterPantaloni == 0)
                {
                    cout << "Nemate vneseno artikli.\n";
                    break;
                }
                for(int i = 0; i < counterPantaloni; ++i)
                {
                    cout << "\nPantaloni " << i + 1 << endl;
                    arrayOfPantaloni[i].prikaziPodatociPantaloni();
                    totalPrice += arrayOfPantaloni[i].getCena();
                }
                for(int i = 0; i < counterKosuli; ++i)
                {
                    cout << "\nKosula " << i + 1 << endl;
                    arrayOfKosuli[i].prikaziPodatociKosuli();
                    totalPrice += arrayOfKosuli[i].getCena();
                }
                cout << "\nVkupnata cena na site artikli iznesuva : "
                     << totalPrice << endl;
                break;
            }
            case 4:
            {
                int totalPrice = 0;
                if(counterPantaloni == 0)
                {
                    cout << "Nemate vneseno pantaloni.\n";
                    break;
                }
                for(int i = 0; i < counterPantaloni; ++i)
                {
                    if(arrayOfPantaloni[i].presmetajNabavka())
                    {
                        cout << "\nPantaloni " << i + 1 << endl;
                        arrayOfPantaloni[i].prikaziPodatociPantaloni();
                        totalPrice += arrayOfPantaloni[i].getCena();
                    }
                   
                }
                cout << "Vkupnata suma na site artikli koi treba da"
                        " se nabavat iznesuva: " << totalPrice << endl;
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
    cout << "Izberi broj: \n"
        "1 - Dodadi artikl.\n"
        "2 - Prikazi artikl od dadena grupa.\n"
        "3 - Prikazi site artikli so vkupna cena.\n"
        "4 - Prikazi artikli za nabavka vo rok od edna nedela.\n"
        "5 - Za kraj.\n";
    cin >> choise;
    return choise;
}