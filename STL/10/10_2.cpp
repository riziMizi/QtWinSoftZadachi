#include <iostream>
#include <exception>

using namespace std;

class Motor{
    public:
        Motor()
        {
            cout << "Kreiran e motor.\n";
            throw 0;
        }
        ~Motor()
        {
            cout << "Unisten e motor.\n";
        }
};

class Avtomobil: public Motor{
    public:
        Avtomobil() : Motor()
        {
            cout << "Kreiran e avtomobil.\n";
        }
        ~Avtomobil()
        {
            cout << "Unisten e avtomobil.\n";
        }
};

class Garaza {
    public:
        Garaza()
        {
            try
            {
                cout << "Kreirana e garaza.\n";
                Avtomobil avtomobil;
            }
            catch(int)
            {
                cout << "Faten exception vo garaza.\n";
                throw exception();
            }
        }
        ~Garaza()
        {
            cout << "Unistena e garaza.\n";
        }
};

int main()
{
    try
    {
        Garaza garaza;
    }
    catch(exception &e)
    {
        cout << "Faten e exception vo main.\n";
    }

    return 0;
}