#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <numeric>

using namespace std;

class Vraboten {
public:
    Vraboten();
    Vraboten(string, int);
    string getIme() const {return ime;}
    int getBodovi() const {return bodovi;}
    friend ostream &operator<<(ostream&, 
                    const Vraboten &);
private:
    string ime;
    int bodovi;
};

Vraboten::Vraboten() {}

Vraboten::Vraboten(string ime, int bodovi)
{
    this->ime = ime;
    this->bodovi = bodovi;
}

ostream &operator<<(ostream &output, const Vraboten &vraboten)
{
    output << vraboten.getIme() <<
          ": " << vraboten.getBodovi();
   
    return output;   
}

bool compareBodovi(Vraboten v1, Vraboten v2);

int main()
{
    vector<Vraboten> vraboteni;
    ostream_iterator<Vraboten> output(cout, "\n");
    int vrednostBod;
    int brojVraboteni;

    string imeVraboten;
    int bodoviVraboten;

    cout << "Vnesi broj na vraboteni: ";
    cin >> brojVraboteni;

    for(int i = 0; i < brojVraboteni; ++i)
    {
        cout << "Vnesi ime na vraboten: ";
        cin.ignore();
        getline(cin, imeVraboten);
        cout << "Vnesi bodovi na vraboten: ";
        cin >> bodoviVraboten;
        vraboteni.push_back(
            Vraboten(imeVraboten, bodoviVraboten));
    }

    cout << "\nVnesi vrednost na bod: ";
    cin >> vrednostBod;

    sort(vraboteni.begin(), vraboteni.end(), compareBodovi);
    cout << "Vraboteni:\n";
    copy(vraboteni.begin(), vraboteni.end(), output);

    // koristime labda expression za da ja sumirame vrednosta
    // na bodovite na sekoj vraboten
    int sum = accumulate(vraboteni.begin(), vraboteni.end(), 0, 
            [](int i, Vraboten  &v){
                return v.getBodovi() + i; 
                                   });
    
    cout << "Vkupnata suma sto treba da se isplati iznesuva: "
         << sum * vrednostBod << endl;

    return 0;
}

bool compareBodovi(Vraboten v1, Vraboten v2)
{
    return v1.getBodovi() < v2.getBodovi();
}