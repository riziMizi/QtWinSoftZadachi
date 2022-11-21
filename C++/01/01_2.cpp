#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int tripleCallByValue(int);
void tripleCallByReference(int &);

int main()
{
    int count;

    cout << "Vnesete eden cel broj: ";
    cin >> count;

    cout << "Vrednosta na count od funkcija tripleCallByValue iznesuva: "
         << tripleCallByValue(count) << endl;
    cout << "Vrednosta na count po funkcija tripleCallByValue iznesuva: "
         << count << endl;
    cout << "Vrednosta na count od funkcijata tripleCallByReference iznesuva: ";
    tripleCallByReference(count);
    cout << count << endl;
    cout << "Vrednosta na count po funkcijata tripleCallByReference iznesuva: "
         << count << endl;

    return 0;
}

int tripleCallByValue(int count)
{
    return count * 3;
}

void tripleCallByReference(int &count)
{
    count *= 3;
}
