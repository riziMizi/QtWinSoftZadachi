#include <iostream>

using namespace std;


template<class T>
void sortArray(T *arr, int const n);

int main()
{
    int intLength, doubleLength;

    cout << "Vnesi kolku elementi ima int nizata: ";
    cin >> intLength;

    int intArr[intLength];
    for(int i = 0; i < intLength; ++i)
    {
        cout << "Vnesi element vo int nizata: ";
        cin >> intArr[i];
    }

    cout << "Vnesi kolku elementi ima double nizata: ";
    cin >> doubleLength;

    double doubleArr[doubleLength];
    for(int i = 0; i < doubleLength; ++i)
    {
        cout << "Vnesi element vo double nizata: ";
        cin >> doubleArr[i];
    }

    sortArray(intArr, intLength);
    sortArray(doubleArr, doubleLength);

    cout << "int nizata po soritranje: \n";
    for(int i = 0; i < intLength; ++i)
    {
        cout << intArr[i] << " ";
    }

    cout << "\ndouble nizata po soritranje: \n";
    for(int i = 0; i < doubleLength; ++i)
    {
        cout << doubleArr[i] << " ";
    }

    return 0;

}


template<class T>
void sortArray(T *arr, int const n)
{
    for(int i = 0; i < n - 1; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(arr[j] < arr[i])
            {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
