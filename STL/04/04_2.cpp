#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string word1, word2;
    cout << "Vnesi go prviot zbor: ";
    getline(cin, word1);
    cout << "Vnesi go vtoriot zbor: ";
    getline(cin, word2);

    if(word1.length() != word2.length())
    {
        cout << "Zborovite ne se anagrami.\n";
        return 0;
    }

    vector<char> vector1(word1.begin(), word1.end());
    vector<char> vector2(word2.begin(), word2.end());

    sort(vector1.begin(), vector1.end());
    sort(vector2.begin(), vector2.end());

    if(equal(vector1.begin(), vector1.end(), vector2.begin()))
        cout << "Zborivite se anagrami.\n";
    else
      cout << "Zborovite ne se anagrami.\n";  

    return 0;
}
