#include <iostream>

using namespace std;

class Stedac
{
 public:
        void vnesiPodatoci();
        void prikaziPodatoci();
        void uplata(unsigned long i);
        void isplata(unsigned long i);
        long sostojba() {return saldo;}
        int getBroj() {return broj;}

  private:
        int broj;
        char imeprezime[30], adresa[50];
        long saldo;
};

void Stedac::vnesiPodatoci()
{
    cout << "Vnesi broj: ";
    cin >> broj;
    cout << "Vnesi ime i prezime: ";
    cin.ignore();
    cin.getline(imeprezime, 30);
    cout << "Vnesi adresa: ";
    cin.getline(adresa, 50);
    cout << "Vnesi saldo: ";
    cin >> saldo;
}

void Stedac::prikaziPodatoci()
{
    cout << "Broj: " << broj <<
        "\nIme i prezime: " << imeprezime <<
        "\nAdresa: " << adresa <<
        "\nSaldo: " << saldo << endl;
}

void Stedac::uplata(unsigned long i)
{
    saldo += i;
}

void Stedac::isplata(unsigned long i)
{
    if(i > saldo)
     cout << "Nemate tolku sredstva za isplata.\n";
    else
    {
        cout << "Uspesna isplata.\n";
        saldo -= i;
    }
}

int instructions();

int main()
{
    int choise;
    Stedac arrayOfStedac[100];
    int i;
    int counter = 0;

    while((choise = instructions()) != 6)
    {
        switch(choise)
        {
            case 1:
                {
                    Stedac newStedac;
                    newStedac.vnesiPodatoci();
                    arrayOfStedac[counter++] = newStedac;
                    cout << "Uspesno vnesen stedac.\n";
                    break;
                }
            case 2:
                {
                    int numberStedac;
                    // Ako postoi stedacot za daden broj wrongNumber = 0.
                    int wrongNumber = 1;
                    cout << "Vnesete broj na stedac: ";
                    cin >> numberStedac;
                    for(i = 0; i < counter; ++i)
                    {
                        if(arrayOfStedac[i].getBroj() == numberStedac)
                        {
                            arrayOfStedac[i].prikaziPodatoci();
                            wrongNumber = 0;
                            break;
                        }
                    }
                    if(wrongNumber == 1)
                     cout << "Ne postoi stedac so broj " << numberStedac << endl;;
                    break;
                }
            case 3:
                {
                    int numberStedac;
                    int wrongNumber = 1;
                    unsigned long amountOfPayment;
                    cout << "Vnesete broj na stedac: ";
                    cin >> numberStedac;
                    cout << "Vnesete broj na sredstva za uplata: ";
                    cin >> amountOfPayment;
                    for(i = 0; i < counter; ++i)
                    {
                        if(arrayOfStedac[i].getBroj() == numberStedac)
                        {
                            arrayOfStedac[i].uplata(amountOfPayment);
                            cout << "Uspesna uplata.\n";
                            wrongNumber = 0;
                            break;
                        }
                    }
                    if(wrongNumber == 1)
                     cout << "Ne postoi stedac so broj " << numberStedac << endl;;
                    break;
                }
            case 4:
                {
                    int numberStedac;
                    int wrongNumber = 1;
                    unsigned long amountOfPayment;
                    cout << "Vnesete broj na stedac: ";
                    cin >> numberStedac;
                    cout << "Vnesete broj na sredstva za isplata: ";
                    cin >> amountOfPayment;
                    for(i = 0; i < counter; ++i)
                    {
                        if(arrayOfStedac[i].getBroj() == numberStedac)
                        {
                            arrayOfStedac[i].isplata(amountOfPayment);
                            wrongNumber = 0;
                            break;
                        }
                    }
                    if(wrongNumber == 1)
                     cout << "Ne postoi stedac so broj " << numberStedac << endl;;
                    break;
                }
            case 5:
                {
                    int numberStedac;
                    int wrongNumber = 1;
                    cout << "Vnesete broj na stedac: ";
                    cin >> numberStedac;

                    for(i = 0; i < counter; ++i)
                    {
                        if(arrayOfStedac[i].getBroj() == numberStedac)
                        {
                            cout << "Stedacot so broj " << numberStedac <<
                                " ima " << arrayOfStedac[i].sostojba() << endl;
                            wrongNumber = 0;
                            break;
                        }
                    }
                    if(wrongNumber == 1)
                     cout << "Ne postoi stedac so broj " << numberStedac << endl;;
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
        "1 - Kreiraj nov stedac.\n"
        "2 - Prikaz na podatocite.\n"
        "3 - Uplata na sredstva.\n"
        "4 - Isplata na sredstva.\n"
        "5 - Prikaz na saldo za daden stedac.\n"
        "6 - Za kraj. \n";

    cin >> choise;
    return choise;
}

