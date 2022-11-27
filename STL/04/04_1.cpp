#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Imenik {
public:
    Imenik(string, string);
    string getIme() const {return ime;}
    string getTelBroj() const {return telBroj;}
private:
    string telBroj;
    string ime;
};

Imenik::Imenik(string ime, string telBroj)
{
    this->ime = ime;
    this->telBroj = telBroj;
}

bool compareName(Imenik imenik1, Imenik imenik2)
{
    return imenik1.getIme() < imenik2.getIme();
}

int main()
{
    vector<Imenik> imenik;
    imenik.push_back(Imenik("Bojan", "071123123"));
    imenik.push_back(Imenik("Tamara", "072123123"));
    imenik.push_back(Imenik("Pece", "073123123"));
    imenik.push_back(Imenik("Ana", "074123123"));

    sort(imenik.begin(), imenik.end(), compareName);

    for(int i = 0; i < imenik.size(); ++i)
    {
        cout << imenik[i].getIme() <<
             " - " << imenik[i].getTelBroj()
             << endl;
    }

    return 0;
}
