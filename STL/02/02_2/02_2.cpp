#include <iostream>

using namespace std;

#include "Kvadrat.h"
#include "Pravoagolnik.h"

template<class T>
void sortirajPole(T* arr, int size)
{
    for(int i = 0; i < size - 1; ++i)
    {
        for(int j = i + 1; j < size; ++j)
        {
            if(arr[i].getPlostina() > arr[j].getPlostina())
            {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

template<class T>
void pecatiPole(T* arr, int size)
{
    for(int i = 0; i < size; ++i)
    {
        cout << arr[i].getPlostina() << " ";
    }
    cout << endl;
}

int main()
{
    int sizeKvadrati, sizePravoagolnici;
    cout << "Vnesi kolku kvadrati ke ima vo nizata: ";
    cin >> sizeKvadrati;
    cout << "Vnesi kolku pravoagolnici ke ima vo nizata: ";
    cin >> sizePravoagolnici;

    Kvadrat arrKvadrat[sizeKvadrati];
    Pravoagolnik arrPravoagolnik[sizePravoagolnici];

    cout << "Vnesi kvadrati: \n";
    for(int i = 0; i < sizeKvadrati; ++i)
    {
        Kvadrat newKvadrat;
        arrKvadrat[i] = newKvadrat.postavi();
    }

    cout << "Vnesi pravoagolnici: \n";
    for(int i = 0; i < sizePravoagolnici; ++i)
    {
        Pravoagolnik newPravoagolnik;
        arrPravoagolnik[i] = newPravoagolnik.postavi();
    }

    cout << "Nizata od kvadrati: \n";
    pecatiPole(arrKvadrat, sizeKvadrati);
    sortirajPole(arrKvadrat, sizeKvadrati);
    cout << "Sortirana niza od kvadrati: \n";
    pecatiPole(arrKvadrat, sizeKvadrati);

    cout << "Nizata od pravoagolnici: \n";
    pecatiPole(arrPravoagolnik, sizePravoagolnici);
    sortirajPole(arrPravoagolnik, sizePravoagolnici);
    cout << "Sortirana niza od pravoagolnici: \n";
    pecatiPole(arrPravoagolnik, sizePravoagolnici);

    return 0;
}