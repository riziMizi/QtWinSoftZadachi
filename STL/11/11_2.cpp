#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream createReadFile("read.txt", ios::out);
    ofstream writeTxt("write.txt", ios::out);
    string text;
    string word;

    if(!createReadFile)
    {
        cerr << "Datotekata nemoze da se otvori.\n";
        exit(1);
    }
    if(!writeTxt)
    {
        cerr << "Datotekata nemoze da se otvori.\n";
        exit(1);
    }

    cout << "Vnesi tekst.\n";
    getline(cin, text);
    createReadFile << text; 
    createReadFile.close();

    ifstream readTxt("read.txt", ios::in);

    if(!readTxt)
    {
        cerr << "Datotekata nemoze da se otvori.\n";
        exit(1);
    }

    while(readTxt >> word)
    {
        if(word.length() < 10)
        {
            writeTxt << word << " ";
        }
    }

    readTxt.close();
    writeTxt.close();

    return 0;
}