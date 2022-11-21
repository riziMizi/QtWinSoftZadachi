#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

using namespace std;

class Complex {
public:
   Complex( double = 0.0, double = 0.0 );       // konstruktor
   Complex operator+( const Complex & ) const;  // sobiranje
   Complex operator-( const Complex & ) const;  // odzemanje
   const Complex &operator=( const Complex & ); // dodeluvanje
   // mnozenje na dva kompleksni
   Complex operator*(const Complex &) const;
   // mnozenje na kompleksen so broj 
   Complex operator*(const int) const; 
   Complex operator+=(const Complex &);
   Complex operator-=(const Complex &);
   Complex operator*=(const Complex &);
   friend bool operator==(Complex, Complex);
   friend bool operator!=(Complex, Complex);
    // mnozenje na cel broj so kompleksen
   friend Complex operator*(int, Complex);
   friend ostream &operator<<(ostream&, const Complex &);
   friend istream &operator>>(istream&, Complex & );
private:
   double real;       // realen del
   double imaginary;  // imaginaren del
}; // kraj na klasta Complex

#endif
