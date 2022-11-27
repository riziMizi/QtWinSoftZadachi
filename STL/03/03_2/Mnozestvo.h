#ifndef MNOZESTVO_H
#define MNOZESTVO_H

template<class T>
class Mnozestvo {
public:
    Mnozestvo();
    void addElement(T);
    void printArray() const;
    int getNumElements() const;
    T maxElement();
private:
    T arr[100];
    static int numElements;
};

#endif