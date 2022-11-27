#include <iostream>
#include <cstring>

using namespace std;

template<class T>
T sum(T* arr, int start, int end, int size, T value = T())
{
    if(start < 0 || end > size || start > end) return 0;
    for(int i = start; i <= end; ++i)
    {
        value += arr[i];
    }

    return value;
}

int main()
{
    int intSize, doubleSize;
    cout << "Vnesi dolzina na int nizata: ";
    cin >> intSize;
    cout << "Vnesi dolzina na double nizata: ";
    cin >> doubleSize;

    int intArr[intSize];
    double doubleArr[doubleSize];

    cout << "Vnesi elementi za int nizata: \n";
    for(int i = 0; i < intSize; ++i)
    {
        cout << "Vnesi element: ";
        cin >> intArr[i];
    }

    cout << "Vnesi elementi za double nizata: \n";
    for(int i = 0; i < doubleSize; ++i)
    {
        cout << "Vnesi element: ";
        cin >> doubleArr[i];
    }

    cout << "Sumata od int nizata e: " << 
         sum(intArr, 0, intSize - 1, intSize);

    cout << "\nSumata od double nizata e: " << 
         sum(doubleArr, 0, doubleSize - 1, doubleSize);

    return 0;
}

