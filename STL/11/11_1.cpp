#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int n, m;
    cout<< "Vnesi za kolku vrednosti: ";
    cin >> n;
    cout << "Vnesi sirina na kolona: ";
    cin >> m;

    cout << left << setw(m) << "i" << setw(m)
         << "i^2" << setw(m) << "sqrt(i)" <<
         "cbrt(i)" << endl;

    cout.precision(4);
    for(int i = 1; i <= n; ++i)
    {
        cout << left << setw(m) << i << setw(m)
         << i * i << setw(m) << sqrt(i) <<
         cbrt(i) << endl;
    }

    return 0;
}