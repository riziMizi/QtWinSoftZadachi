#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

#include "Karta.h"
#include "Igrac.h"

#define SIZE 52

void dealCards(int numberOfPlayers, vector<Igrac> &vPlayers,
             vector<Karta> vCards);

int main()
{
    vector<Karta> deck;
    int numberCard = 1;
    string colorCard = "Srce";
    // counter sluzi za menuvanje na bojte
    // pri inicijaliziranje na spilot
    int counter = 1;

    int numberOfPlayers;
    cout << "Vnesi broj na igraci: ";
    cin >> numberOfPlayers;
    int typeOfGame;
    cout << "Izberi tip na igra: \n"
         "1 - Normlana igra.\n"
         "2 - Igra kade srcinjata se brojat *2\n";
    cin >> typeOfGame;

    typeOfGame = (typeOfGame == 1 || typeOfGame == 2) ?
                  typeOfGame : 1;

    vector<Igrac> players(numberOfPlayers);

    for(int i = 0; i < SIZE; ++i)
    {
        deck.push_back(Karta(numberCard, colorCard));
        ++numberCard;
        // A ima vrednost 1. vo spilot nema vrednost 11
        // zatoa se skoka
        if(numberCard == 11) ++numberCard;

        // ako numberCard == 15 znaci deka site brojki
        // od edna boja se vneseni vo spilot.
        if(numberCard == 15)
        {
            if(counter == 1)
             colorCard = "Baklava";
            else if(counter == 2)
             colorCard = "Detelina";
            else
             colorCard = "List";
            
            numberCard = 1;
            ++counter;
        }
    }

    cout << "Neizmesan spil.\n";
    ostream_iterator<Karta> output(cout, "\n");
    copy(deck.begin(), deck.end(), output);

    cout << "Izmesan spil.\n";
    random_shuffle(deck.begin(), deck.end());
    copy(deck.begin(), deck.end(), output);

    dealCards(numberOfPlayers, players, deck);

    int max = 0;
    int indexOfWinner = 0;
    for(int i = 0; i < numberOfPlayers; ++i)
    {
        int sum = players[i].countSum(typeOfGame);
        if(sum > max)
        {
            max = sum;
            indexOfWinner = i + 1;
        }
        cout << "\nIgrac " << i + 1 << ": \n";
        players[i].printCards();
        cout << "Zbirot e: " << sum << endl;
    }

    cout << "Pobednik e igracot " << indexOfWinner
         << " so zbir od " << max << endl;

    return 0;
}

void dealCards(int numberOfPlayers, vector<Igrac> &vPlayers,
             vector<Karta> vCards)
{
    // Ako imame broj na igraci koj sto ne e deliv so 52
    // nekoj igraci ke imaat poveke karti od drugite.
    // Zatoa se presmetuva numberOfDealtCards
    int numberOfDealtCards = (SIZE / numberOfPlayers) * numberOfPlayers;
    for(int i = 0; i < numberOfDealtCards; ++i)
    {
       vPlayers[i % numberOfPlayers].putCard(vCards[i]);

    }
}

