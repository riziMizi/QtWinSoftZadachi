#include <iostream>
#include <cstdlib>
#include <time.h>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>


using namespace std;

int randomNumber();
bool evenNumbers(int number);
bool lower2000(int number);
bool interval(int number);

#define SIZE 10000
int numberFrom = 2000;
int numberTo = 4000;


int main()
{
    list<int> randomList(SIZE);
    ostream_iterator<int> output(cout, " ");
    srand(time(0));

    generate(randomList.begin(), randomList.end(), randomNumber);
    copy(randomList.begin(), randomList.end(), output);

    int result = count_if(randomList.begin(), randomList.end(),
                            evenNumbers);
    cout << "\nBrojot na prani broevi vo listata e: " << result << endl;

    result = count_if(randomList.begin(), randomList.end(),
                            lower2000);

    cout << "Brojot na broevi pomali od 2000 vo listata e: " 
         << result << endl;

    result = count_if(randomList.begin(), randomList.end(),
                            interval);

    cout << "Brojot na broevi vo interval od [2000, 4000) vo listata e: " 
         << result << endl;
    
    numberFrom += 2000;
    numberTo += 2000;
    result = count_if(randomList.begin(), randomList.end(),
                            interval);

    cout << "Brojot na broevi vo interval od [4000, 6000) vo listata e: " 
         << result << endl;
    
    numberFrom += 2000;
    numberTo += 2000;
    result = count_if(randomList.begin(), randomList.end(),
                            interval);

    cout << "Brojot na broevi vo interval od [6000, 8000) vo listata e: " 
         << result << endl;
    
    numberFrom += 2000;
    numberTo += 2000;
    result = count_if(randomList.begin(), randomList.end(),
                            interval);

    cout << "Brojot na broevi vo interval od [8000, 10000) vo listata e: " 
         << result << endl;

    result = accumulate(randomList.begin(), randomList.end(), 0);

    double average = (double) result / SIZE;

    cout << "Srednata vrednost na broevite vo listata e: " 
         << average << endl;

    return 0;
}

int randomNumber()
{
    return rand() % 10000;
}

bool evenNumbers(int number)
{
    return number % 2 == 0;
}

bool lower2000(int number)
{
    return number < 2000;
}

bool interval(int number)
{
    return number >= numberFrom && number < numberTo;
}
