#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void splitString(string txt, vector<string> &v);

int main()
{
    string text;
    cout << "Vnesi tekst: ";
    getline(cin, text);
    vector<string> mainVector;

    splitString(text, mainVector);

    sort(mainVector.begin(), mainVector.end());

    for(int i = 0; i < mainVector.size(); ++i)
    {
        cout << mainVector[i] << endl;
    }

    return 0;
}

void splitString(string txt, vector<string> &v)
{
    int startIndex = 0;
    string temp;
    vector<char> charVector(txt.begin(), txt.end());
    for(int i = 0; i < charVector.size() - 1; ++i)
    {
        if(charVector[i] == ' ')
        {
            temp = txt.substr(startIndex, i - startIndex);
            if(find(v.begin(), v.end(), temp) == v.end())
                v.push_back(temp);   

            startIndex = i + 1;
        }
    }

    // za da se vnese i posledniot zbor od tekstot
    temp = txt.substr(startIndex);

    if(find(v.begin(), v.end(), temp) == v.end())
        v.push_back(temp);   
}

