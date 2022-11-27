#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <exception>
#include <iterator>

using namespace std;

#include "Bukva.h"

bool containsOnlyLetters(string const &str);

int main()
{
    string word = "ordinacija";
    int counter;
    // zname za proverka dali go pogodil zborot
    bool victory = true;

    if(!containsOnlyLetters(word))
    {
        throw logic_error("Zborot mora da se sostoi"
                          " samo od mali bukvi.");
    }

    cout << "Vnesi broj na obidi za da go "
         "pogodis zborot(" << word.length()
         << " bukvi): ";
    cin >> counter;

    vector<Bukva> bukvi;
    ostream_iterator<Bukva> output(cout, "  ");

    for(int i = 0; i < word.length(); ++i)
    {
        bukvi.push_back(Bukva(word.at(i)));
    }

    while(counter > 0)
    {
        victory = true;
        cout << "\nUste " << counter << " obidi.\n";
        copy(bukvi.begin(), bukvi.end(), output);
        cout << endl;

        char tempLetter;
        cout << "\nVnesi bukva: ";
        cin >> tempLetter;

        for(auto &letter: bukvi)
        {
            if(letter.getBukva() == tempLetter)
             letter.setPogodena();
            
            if(!letter.getPogodena())
                victory = false;
        }

        if(victory)
            break;

        --counter;
    }

    if(victory)
        cout << "Go pogodivte zborot " << word;
    else
        cout << "Ne uspevte da go pogodite zborot "
             << word;

    return 0;
}

bool containsOnlyLetters(string const &str)
{
    return all_of(str.begin(), str.end(), 
                [](char const &c)
                {
                    return isalpha(c) && islower(c);
                });
}
