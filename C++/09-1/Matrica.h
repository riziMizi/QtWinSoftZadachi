#ifndef MATRICA_H
#define MATRICA_H
 
#include <iostream>
 
using namespace std;
 
class Matrica {
public:
   Matrica(int = 3, int =3);              
   Matrica(const Matrica &);  
   ~Matrica();                                          
   const Matrica &operator=(const Matrica &); 
   bool operator==(const Matrica &) const; 
   bool operator!=(const Matrica &) const; 
   int &operator[](int);             
   const int &operator[](int) const;
   Matrica operator+(const Matrica &) const; 
   Matrica operator-(const Matrica &) const; 
   Matrica operator*(const Matrica &) const;
   Matrica operator*(const int) const; 

   friend Matrica operator*(int, Matrica);
   friend ostream &operator<<(ostream&, const Matrica &);
   friend istream &operator>>(istream&, Matrica & );
private:
   int rows;
   int cols; 
   int *ptr; 
}; 
 
#endif
 
