#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
bool palindrom(vector<T> v)
{
    // (v.begin() + v.size() / 2) se stava zatoa
    // sto dovolno e da sporedime do polovina od zborot.
    // Ke raboti i ako se ostavi do v.end()
    return equal(v.begin(), v.begin() + 
        v.size() / 2, v.rbegin());
}

int main()
{
    string word;

    cout << "Vnesi zbor: ";
    cin >> word;

    vector<char> vector1(word.begin(), word.end()); 

    if(palindrom(vector1))
        cout << "zborot " << word <<
             " e palindrom.";
    else
        cout << "zborot " << word <<
             " ne e palindrom.";

    return 0;
}
