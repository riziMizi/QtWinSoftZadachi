#include <iostream>
#include <vector>
#include <iterator>
#include <time.h>
#include <algorithm>
#include <exception>

using namespace std;

int randomNumber();

int main()
{
    srand(time(0));
    int number1 = randomNumber();
    int number2 = randomNumber();
    ostream_iterator<int> output(cout, " ");

    vector<int> v1(number1);
    vector<int> v2(number2);

    generate(v1.begin(), v1.end(), randomNumber);
    
    try
    {
        if(number2 < number1)
            throw exception();

        copy(v1.begin(), v1.end(), v2.begin());
        cout << "v2: \n";
        copy(v2.begin(), v2.end(), output);

    }
    catch(exception &e)
    {
        cout << "Vectorot v2 nema dovolno mesto!!";
    }

    return 0;
}

int randomNumber()
{
    return rand() % 1000 + 1;
}