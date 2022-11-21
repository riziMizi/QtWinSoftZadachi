#include <iostream>

using namespace std;

#include "Matrica.h"

int instructions();

int main()
{
    int choise;
    Matrica arrayOfMatrica[100];
    int counter = 0;

    while((choise = instructions()) != 12)
    {
        switch(choise)
        {
            case 1:
            {
                int cols, rows;
                cout << "Vnesi dimenzii na matricata: ";
                cin >> rows >> cols;

                Matrica newMatrica(rows, cols);
                cout << "Vnesi elementi vo matricata: ";
                cin >> newMatrica;
                cout << "Dodadena e matrica " << counter + 1 << endl;
                cout << newMatrica;
                arrayOfMatrica[counter++] = newMatrica;
                break;
            }
            case 2:
            {
                int indexOfMatrix;
                cout << "Napravi identicna matrica od matricata "
                     "so broj : ";
                cin >> indexOfMatrix;
                if(indexOfMatrix > counter)
                {
                    cout << "Ne postoi matrica so broj " << 
                    indexOfMatrix << endl;
                    break;
                }
                else
                {
                    Matrica newMatrix = arrayOfMatrica[indexOfMatrix - 1];
                    arrayOfMatrica[counter++] = newMatrix;
                }
                break;
            }
            case 3:
            {
                if(counter == 0)
                {
                    cout << "Nema matrici.\n";
                    break;
                }
                for(int i = 0; i < counter; ++i)
                {
                    cout << "Matrica " << i + 1 << endl;
                    cout << arrayOfMatrica[i];
                }
                break;
            }
            case 4:
            {
                int indexOfMatrix1;
                int indexOfMatrix2;

                cout << "Vnesi koj dve matrici sakas da "
                     "gi sporedis: ";
                cin >> indexOfMatrix1 >> indexOfMatrix2;
                if(indexOfMatrix1 > counter ||
                    indexOfMatrix2 > counter)
                {
                    cout << "Vnesovte pogresen broj na matrica.\n";
                    break;
                }
                else
                {
                    if(arrayOfMatrica[indexOfMatrix1 - 1] == 
                        arrayOfMatrica[indexOfMatrix2 - 1])
                    {
                        cout << "Matricite " << indexOfMatrix1 <<
                             " i " << indexOfMatrix2 << " se identicni.\n";
                    }
                    else
                    {
                       cout << "Matricite " << indexOfMatrix1 <<
                             " i " << indexOfMatrix2 << " se razlicni.\n";
                    }
                }
                break;
            }
            case 5:
            {
                int indexOfMatrix;
                int indexOfElement;
                cout << "Vnesi broj na matrica i index na element: ";
                cin >> indexOfMatrix >> indexOfElement;
                 if(indexOfMatrix > counter)
                {
                    cout << "Ne postoi matrica so broj " << 
                    indexOfMatrix << endl;
                    break;
                }
                else
                {
                    cout << "Elementot sto go baravte e: " <<
                    arrayOfMatrica[indexOfMatrix - 1][indexOfElement] << endl;;
                }
                break;
            }
            case 6:
            {
                int indexOfMatrix;
                int indexOfElement;
                cout << "Vnesi broj na matrica i index na element: ";
                cin >> indexOfMatrix >> indexOfElement;
                 if(indexOfMatrix > counter)
                {
                    cout << "Ne postoi matrica so broj " << 
                    indexOfMatrix << endl;
                    break;
                }
                else
                {
                    int number;
                    cout << "Elementot sto ke go zamenite e: " <<
                    arrayOfMatrica[indexOfMatrix - 1][indexOfElement] << endl;
                    cout << "Vnesete broj za zamena: ";
                    cin >> number;
                    arrayOfMatrica[indexOfMatrix - 1][indexOfElement] = number;
                    cout << "Matrica " << indexOfMatrix <<
                         " posle promenata.\n";
                    
                    cout << arrayOfMatrica[indexOfMatrix - 1];
                }
                break;
            }
            case 7:
            {
                int indexOfMatrix1;
                int indexOfMatrix2;

                cout << "Vnesi koj dve matrici sakas da "
                     "gi soberes: ";
                cin >> indexOfMatrix1 >> indexOfMatrix2;
                if(indexOfMatrix1 > counter ||
                    indexOfMatrix2 > counter)
                {
                    cout << "Vnesovte pogresen broj na matrica.\n";
                    break;
                }
                else
                {
                    Matrica temp = arrayOfMatrica[indexOfMatrix1 - 1] + 
                        arrayOfMatrica[indexOfMatrix2 - 1];
                    if(temp != arrayOfMatrica[indexOfMatrix1 - 1])
                    {
                         cout << "Matrica " << indexOfMatrix1 <<
                        " + Matrica " << indexOfMatrix2 << endl;
                        cout << temp;
                    } 
                }
                break;
            }
            case 8:
            {
                int indexOfMatrix1;
                int indexOfMatrix2;

                cout << "Vnesi koj dve matrici sakas da "
                     "gi odzemes: ";
                cin >> indexOfMatrix1 >> indexOfMatrix2;
                if(indexOfMatrix1 > counter ||
                    indexOfMatrix2 > counter)
                {
                    cout << "Vnesovte pogresen broj na matrica.\n";
                    break;
                }
                else
                {
                    Matrica temp = arrayOfMatrica[indexOfMatrix1 - 1] - 
                        arrayOfMatrica[indexOfMatrix2 - 1];
                    if(temp != arrayOfMatrica[indexOfMatrix1 - 1])
                    {
                         cout << "Matrica " << indexOfMatrix1 <<
                        " - Matrica " << indexOfMatrix2 << endl;
                        cout << temp;
                    } 
                }
                break;
            }
            case 9:
            {
                int indexOfMatrix1;
                int indexOfMatrix2;

                cout << "Vnesi koj dve matrici sakas da "
                     "gi mnozis: ";
                cin >> indexOfMatrix1 >> indexOfMatrix2;
                if(indexOfMatrix1 > counter ||
                    indexOfMatrix2 > counter)
                {
                    cout << "Vnesovte pogresen broj na matrica.\n";
                    break;
                }
                else
                {
                    Matrica temp = arrayOfMatrica[indexOfMatrix1 - 1] * 
                        arrayOfMatrica[indexOfMatrix2 - 1];
                    if(temp != arrayOfMatrica[indexOfMatrix1 - 1])
                    {
                         cout << "Matrica " << indexOfMatrix1 <<
                        " * Matrica " << indexOfMatrix2 << endl;
                        cout << temp;
                    } 
                }
                break;
            }
            case 10:
            {
                int indexOfMatrix1;
                int number;

                cout << "Vnesi koja matrica sakas da "
                     "ja mnozis: ";
                cin >> indexOfMatrix1;
                cout << "Vnesi cel broj za mnozenje: ";
                cin >> number;
                if(indexOfMatrix1 > counter)
                {
                    cout << "Vnesovte pogresen broj na matrica.\n";
                    break;
                }
                else
                {
                    
                    cout << "Matrica " << indexOfMatrix1 <<
                        " *  " << number << endl;
                    cout << arrayOfMatrica[indexOfMatrix1 - 1] * number;
                }
                break;
            }
            case 11:
            {
                int indexOfMatrix1;
                int number;

                cout << "Vnesi koja matrica sakas da "
                     "ja mnozis: ";
                cin >> indexOfMatrix1;
                cout << "Vnesi cel broj za mnozenje: ";
                cin >> number;
                if(indexOfMatrix1 > counter)
                {
                    cout << "Vnesovte pogresen broj na matrica.\n";
                    break;
                }
                else
                {
                    cout << number <<" *  " << 
                    "Matrica " << indexOfMatrix1 << endl;
                    cout << number * arrayOfMatrica[indexOfMatrix1 - 1];
                }
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
        "1 - Kreiraj nova matrica.\n"
        "2 - Kopiraj matrica.\n"
        "3 - Izlistaj matrici.\n"
        "4 - Sporedi matrici.\n"
        "5 - Zemi element od matrica.\n"
        "6 - Promeni element na matrica. \n"
        "7 - Sobiranje na dve matrica. \n"
        "8 - Odzemanje na dve matrica. \n"
        "9 - Mnozenje na dve matrica. \n"
        "10 - Mnozenje na matrica so broj. \n"
        "11 - Mnozenje na broj so matrica. \n"
        "12 - Za kraj. \n";
    cin >> choise;
    return choise;
}