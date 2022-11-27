#include <iostream>
#include <memory>
#include <exception>

using namespace std;

class Objekt {
public:
    Objekt()
    {
        cout << "Kreiran e objektot. \n";
        throw exception();
    }
    ~Objekt()
    {
        cout << "Unisten e objektot.\n";
    }
};

int main()
{
    try
    {
       Objekt objekt;
    }
    catch(exception &e)
    {
        cout << "Exception.\n"
             "Ne se povikuva destruktorot na Objekt." ;
    }

    return 0;
}
