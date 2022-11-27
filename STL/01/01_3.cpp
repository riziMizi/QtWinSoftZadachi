#include <iostream>

using namespace std;

template<typename P, typename R>
R implicit_cast(const P& p) {
  return p;
}

int main() 
{
    int i = 1;
    float x = implicit_cast<float>(i);
    int j = implicit_cast<int>(x);

    return 0;
} 

/*
Se javuva problem pri kompajliranje poradi toa 
sto povratniot tip e nespecificiran, odnosno
prviot parametar e tipot koj sto funkcijata
treba da go vrati. Vo ovoj slucaj funkcijata
treba da vrati P, a vraka R.
*/