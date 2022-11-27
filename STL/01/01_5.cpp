#include <iostream>

using namespace std;

template<class T>
class Array{
public:
    Array(int = 10);
    void postaviNiza();
    void print() const;
    T getElement(int) const;
    void setElement(int, T);
private:
    int size;
    T* ptr;
};

template<class T>
Array<T>::Array(int length)
{
    size = (length > 0) ? length : 10;
    ptr = new T[10];
}

template<class T>
void Array<T>::postaviNiza()
{
    for(int i = 0; i < size; ++i)
    {
        cout << "Vnesi element: ";
        cin >> ptr[i];
    }
}

template<class T>
void Array<T>::print() const
{
    for(int i = 0; i < size; ++i)
    {
        cout << ptr[i] << " ";
    }
    cout << endl;
}

template<class T>
T Array<T>::getElement(int index) const
{
    if(index > size || index < 1)
    {
        cout << "Pogresen index.\n";
        return 0;
    }
    return ptr[index - 1];
}

template<class T>
void Array<T>::setElement(int index, T val)
{
    if(index > size || index < 1)
    {
        cout << "Pogresen index.\n";
        return;
    }
    cout << "Elementot " << ptr[index - 1] <<
         " e zamenet so elementot " <<
         val << endl;
    ptr[index - 1] = val;    
}

int main()
{
    int intSize, doubleSize;
    cout << "Vnesi dolzina na int nizata: ";
    cin >> intSize;
    cout << "Vnesi dolzina na double nizata: ";
    cin >> doubleSize;

    Array<int> intArray(intSize);
    Array<double> doubleArray(doubleSize);
    
    cout << "Vnesi element za int nizata:\n";
    intArray.postaviNiza();
    cout << "Vnesi element za double nizata:\n";
    doubleArray.postaviNiza();

    cout << "Vtoriot element vo int nizata: "
         << intArray.getElement(2) << endl;
    cout << "Vtoriot element vo double nizata: "
         << doubleArray.getElement(2) << endl;
    
    intArray.setElement(2, 3);
    doubleArray.setElement(2, 6.6);

    intArray.print();
    doubleArray.print();

    return 0;
}

