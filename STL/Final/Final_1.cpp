#include <iostream>
#include <string>

using namespace std;

template<class T>
class Pole {
public:
    Pole();
    void print() const;
    void setElement(T value);

    T getElement(int index) const { return arr[index];}
    int getCounter() const { return counter;}

private:
    T arr[50];
    int counter;
};

template<class T>
Pole<T>::Pole()
{
    counter = 0;
}

template<class T>
void Pole<T>::print() const
{
    for(int i = 0; i < counter; ++i)
    {
        cout << arr[i] << " ";
    }
}

template<class T>
void Pole<T>::setElement(T value)
{
    arr[counter++] = value;
}

template<class T>
T max(Pole<T> *arr);

template<>
string max(Pole<string> *arr);

int main()
{
    Pole<int> intPole;
    Pole<char> charPole;
    Pole<string> stringPole;

    cout << "Vnesi 5 celi broevi: ";
    for(int i = 0; i < 5; ++i)
    {
        int temp;
        cin >> temp;
        intPole.setElement(temp);
    }

    cout << "Vnesi 5 karakteri: ";
    for(int i = 0; i < 5; ++i)
    {
        char temp;
        cin >> temp;
        charPole.setElement(temp);
    }

    cout << "Vnesi 5 zbora: ";
    for(int i = 0; i < 5; ++i)
    {
        string temp;
        cin >> temp;
        stringPole.setElement(temp);
    }

    cout << "Nizata int: ";
    intPole.print();
    cout << endl;
    cout << "Nizata char: ";
    charPole.print();
    cout << endl;
    cout << "Nizata string: ";
    stringPole.print();
    cout << endl;

    cout << "Najgolem element vo int nizata e: "
         << max(&intPole) << endl;
    cout << "Najgolem element vo char nizata e: "
         << max(&charPole) << endl;
    cout << "Najgolem element vo string nizata e: "
         << max(&stringPole) << endl;

    return 0;
}

template<class T>
T max(Pole<T> *arr)
{
    T max = arr->getElement(0);
    for(int i = 1; i < arr->getCounter(); ++i)
    {
        if(arr->getElement(i) > max)
        {
            max = arr->getElement(i);
        }
    }
    return max;
}

template<>
string max(Pole<string> *arr)
{
    string max = arr->getElement(0);
    for(int i = 0; i < arr->getCounter(); ++i)
    {
        if(arr->getElement(i).length() > max.length())
        {
            max = arr->getElement(i);
        }
    }
    return max;
}
