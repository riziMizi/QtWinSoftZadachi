#include <iostream>
#include <string>
#include <map>
#include <iterator>

using namespace std;

class Stedac {
public:
    Stedac(string, int);
    string getIme() const {return ime;}
    int getUplata() const {return uplata;}
private:
    string ime;
    int uplata;
};

Stedac::Stedac(string ime, int uplata)
{
    this->ime = ime;
    this->uplata = uplata;
}

int instructions();

typedef multimap< string, Stedac, less<string>> mmid;

int main()
{
    int choise;
    mmid mapStedac;

    while((choise = instructions()) != 3)
    {
        switch(choise)
        {
            case 1:
            {
                string ime;
                int uplata;
                cout << "Vnesi ime na stedac: ";
                cin.ignore();
                getline(cin, ime);
                cout << "Vnesi uplata: ";
                cin >> uplata;
                mapStedac.insert(mmid::value_type
                        (ime, Stedac(ime, uplata)));
                break;
            }
            case 2:
            {
                mmid::const_iterator iter;
                string ime;
                cout << "Vnesete ime na stedac: ";
                cin.ignore();
                getline(cin, ime);
                if(mapStedac.count(ime) == 0)
                {
                    cout << "Nema stedac so ime "
                         << ime << endl;
                    break;
                }
          
                iter = mapStedac.find(ime);
                cout << "\nStedacot so ime " 
                     << iter->second.getIme() <<
                     " ima uplata od "
                     << iter->second.getUplata() << endl;
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
        "1 - Dodaj uplata.\n"
        "2 - Prikazi uplata za daden stedac.\n"
        "3 - Za kraj.\n";
    cin >> choise;
    return choise;
}