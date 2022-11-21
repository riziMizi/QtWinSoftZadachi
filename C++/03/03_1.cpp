#include <iostream>

using namespace std;

class Kvadar {
public:
    void setValues();
    float getDolzina() {return dolzina;}
    float getSirina() {return sirina;}
    float getVisina() {return visina;}
    void printValues();
    float volumen();
    float plostina();

private:
    float dolzina, sirina, visina;
};

void Kvadar::setValues()
{
    cout << "Vnesi dolzina: ";
    cin >> dolzina;
    cout << "Vnesi sirina: ";
    cin >> sirina;
    cout << "Vnesi visina: ";
    cin >> visina;
}

void Kvadar::printValues()
{
    cout << "dolzina = " << dolzina <<
         "\nsirina = " << sirina <<
         "\nvisina = " << visina << endl;
}

float Kvadar::volumen()
{
    return dolzina * visina * sirina;
}

float Kvadar::plostina()
{
    // ako e kocka
    if(dolzina == sirina == visina)
       return 6 * (dolzina * dolzina);
    // ako e kvadar
    else
        return 2 * ((dolzina * visina) + (dolzina * sirina) +
                    (visina * sirina));
}

int instructions();

int main()
{
    int choise;
    Kvadar arrayOfKvadars[100];
    int i;
    int counter = 0;

    while((choise = instructions()) != 6)
    {
        switch(choise)
        {
            case 1:
                {
                    Kvadar newKvadar;
                    arrayOfKvadars[counter++] = newKvadar;
                    cout << "Uspesno go kreiravte kvadarot "
                         << counter << endl;
                    break;
                }
            case 2:
                {
                    int numberOfKvadar;
                    cout << "Vnesi broj na kvadar: ";
                    cin >> numberOfKvadar;
                    if(numberOfKvadar > counter)
                    {
                        cout << "Nema kvadar so broj " << numberOfKvadar;
                        break;
                    }
                    arrayOfKvadars[numberOfKvadar - 1].setValues();
                    break;
                }
            case 3:
                for(i = 0; i < counter; ++i)
                {
                    cout << "Kvadar " << i + 1 << endl;
                    arrayOfKvadars[i].printValues();
                }
                break;
            case 4:
                {
                    int numberOfKvadar;
                    cout << "Vnesi broj na kvadar: ";
                    cin >> numberOfKvadar;
                    if(numberOfKvadar > counter)
                    {
                        cout << "Nema kvadar so broj " << numberOfKvadar;
                        break;
                    }
                    cout << "Kvadar " << numberOfKvadar << endl;
                    arrayOfKvadars[numberOfKvadar - 1].printValues();
                    break;
                }

            case 5:
                {
                    // inicijalizacija na minPlostina na golem broj
                    float minPlostina =1000000;
                    int index;
                    for(i = 0; i < counter; ++i)
                    {
                        if(arrayOfKvadars[i].getDolzina() ==
                           arrayOfKvadars[i].getSirina() ==
                           arrayOfKvadars[i].getVisina()) continue;
                        else
                        {
                            float tempNumber = arrayOfKvadars[i].plostina();
                            if(minPlostina > tempNumber)
                            {
                                index = i;
                                minPlostina = tempNumber;
                            }
                        }
                    }
                    cout << "Kvadarot so broj " << index + 1 <<
                         "ima najmala plostina: " << minPlostina << endl;
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
        "1 - Kreiraj nov objekt.\n"
        "2 - Postavi gi dimenziite.\n"
        "3 - Pechati gi dimenziite za site objekti.\n"
        "4 - Pechati gi dimenziite za poedinecen objekt.\n"
        "5 - Pechati gi onie koi go zadovoluvaat uslovot.\n"
        "6 - Za kraj. \n";

    cin >> choise;
    return choise;
}

