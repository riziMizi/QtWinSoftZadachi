#include <iostream>
#include <string>

using namespace std;

#include "Mnozestvo.h"
#include "Mnozestvo.cpp"

int instructions();

template<>
string Mnozestvo<string>::maxElement()
{
    if(numElements == 0) return "Prazno mnozestvo";
    string max = arr[0];
    for(int i = 1; i < numElements; ++i)
    {
        if(max.length() < arr[i].length())
          max = arr[i];
    }
    return max;
}


int main()
{
    Mnozestvo<int> A;
    Mnozestvo<double> B;
    Mnozestvo<string> C;
    int choise;

    while((choise = instructions()) != 9)
    {
        switch(choise)
        {
            case 1:
            {
                int value;
                cout << "Vnesi element vo A: ";
                cin >> value;
                A.addElement(value);
                break;
            }
            case 2:
            {
                double value;
                cout << "Vnesi element vo B: ";
                cin >> value;
                B.addElement(value);
                break;
            }
            case 3:
            {
                string value;
                cout << "Vnesi element vo C: ";
                cin.ignore();
                getline(cin, value);
                C.addElement(value);
                break;
            }
            case 4:
            {
                cout << "Elementi vo A:\n";
                A.printArray();
                break;
            }
            case 5:
            {
                cout << "Elementi vo B:\n";
                B.printArray();
                break;
            }
            case 6:
            {
                cout << "Elementi vo C:\n";
                C.printArray();
                break;
            }
            case 7:
            {
                cout << "Najgolem element vo A: "
                     << A.maxElement();
                cout << "\nNajgolem element vo B: "
                     << B.maxElement();
                cout << "\nNajgolem element vo C: "
                     << C.maxElement();
                cout << endl;
                break;
            }
            case 8:
            {
                cout << "Vo mnozestvoto A ima " <<
                    A.getNumElements() << " elementi.\n";
                cout << "Vo mnozestvoto B ima " <<
                    B.getNumElements() << " elementi.\n";
                cout << "Vo mnozestvoto C ima " <<
                    C.getNumElements() << " elementi.\n";
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
        "1 - Dodaj element vo A.\n"
        "2 - Dodaj element vo B.\n"
        "3 - Dodaj element vo C.\n"
        "4 - Prikazi go A.\n"
        "5 - Prikazi go B.\n"
        "6 - Prikazi go C.\n"
        "7 - Prikazi najgolem element.\n"
        "8 - Prikazi broj na elementi vo mnozestva.\n"
        "9 - Za kraj.\n";
    cin >> choise;
    return choise;
}