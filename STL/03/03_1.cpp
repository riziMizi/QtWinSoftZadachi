#include <iostream>

using namespace std;

template<class T>
class Zapis {
public:
    Zapis(T, T, T);
    T getX() const {return x;}
    T getY() const {return y;}
    T getZ() const {return z;}
private:
    T x;
    T y;
    T z;
};

template<class T>
Zapis<T>::Zapis(T x, T y, T z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

template<class T>
bool kontrolor(Zapis<T> zapis)
{
    if(zapis.getX() + zapis.getY() 
        + zapis.getZ() > 10000)
        return true;
    else return false;
}

int main()
{
    Zapis<int> intZapis(100, 200, 300);
    if(kontrolor(intZapis))
        cout << "Zbirot na intZapis e pogolem od 10000\n";
    
    else
        cout << "Zbirot na intZapis ne e pogolem od 10000\n";

    Zapis<double> doubleZapis(1000.20, 5000.30, 30000.35);
    if(kontrolor(doubleZapis))
        cout << "Zbirot na doubleZapis e pogolem od 10000\n";
    
    else
        cout << "Zbirot na doubleZapis ne e pogolem od 10000\n";

    return 0;
}