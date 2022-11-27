#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <exception>
#include <numeric>
#include <iterator>
#include <iomanip>

using namespace std;

class Inventar {
public:
    Inventar();
    Inventar(int, int, double);
    friend ostream &operator<<(ostream&, 
                    const Inventar &);
    int getId() const {return id;}
    int getKolicestvo() const {return kolicestvo;}
    double getCena() const {return cena;}
private:
    int id;
    int kolicestvo;
    double cena;
};

Inventar::Inventar() {}

Inventar::Inventar(int id, int kolicestvo, 
                    double cena)
{
    this->id = id;
    this->kolicestvo = kolicestvo;
    this->cena = cena;
}

ostream &operator<<(ostream &output, const Inventar &inv)
{
    output << inv.getId() << setw(20) << inv.getKolicestvo() <<
          setw(20) << inv.getCena();
   
    return output;   
}


int main()
{
    vector<Inventar> inventar;
    ostream_iterator<Inventar> output(cout, "\n");
    int idArtikl;
    int kolicestvoArtikl;
    double cenaArtikl;
    double vkupnaCena;

    ifstream readInventar("inventar.txt", ios::in);

    if(!readInventar)
    {
        throw std::logic_error("Ne postoi datoteka inventar.txt.");
    }
    
    while(readInventar >> idArtikl >> kolicestvoArtikl
            >> cenaArtikl)
    {
        inventar.push_back(Inventar(idArtikl, 
            kolicestvoArtikl, cenaArtikl));
    }

    vkupnaCena = accumulate(inventar.begin(), inventar.end(), 0.0, 
                [](double i, Inventar  &inv){
                return inv.getCena() * inv.getKolicestvo() + i; 
                                   });
    cout << "Vkupnata vrednost na artiklite vo magacinot iznesuva: "
         << vkupnaCena << endl;

    cout << "Artiklite koi imaat kolicestvo pomalo od 10: \n";
    cout << "Id" << setw(20) << "Kolicestvo" <<
          setw(20) << "Cena" << endl;
          
    copy_if(inventar.begin(), inventar.end(), output,
                [](Inventar inv) { 
                    return inv.getKolicestvo() < 10;
                    });
    readInventar.close();

    return 0;
}