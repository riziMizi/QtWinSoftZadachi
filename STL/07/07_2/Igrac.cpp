#include <iostream>

using namespace std;

#include "Igrac.h"

Igrac::Igrac() 
{
    counter = 0;
}

void Igrac::putCard(Karta karta)
{
    cards[counter++] = karta;
}

// typeOfGame: 1 za obicna igra
// 2 za igra kade srcinjata se * 2
int Igrac::countSum(int typeOfGame)
{
    int sum = 0;
    if(typeOfGame == 1)
    {
        for(int i = 0; i < counter; ++i)
         sum += cards[i].getNumber();
    }
    else
    {
        for(int i = 0; i < counter; ++i)
        {
            if(cards[i].getColor() == "Srce")
             sum += (cards[i].getNumber() * 2);
            else
             sum += cards[i].getNumber();
        }
    }
    return sum;
}

void Igrac::printCards() const
{
    for(int i = 0; i < counter; ++i)
    {
        cout << cards[i] << endl;
    }
}