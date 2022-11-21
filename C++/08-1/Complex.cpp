#include <iostream>
#include <iomanip>

using namespace std;

#include "Complex.h"

// Konstruktor
Complex::Complex( double r, double i ) 
   : real( r ), imaginary( i ) { }

// Preklopi operator za sobiranje
Complex Complex::operator+( const Complex &operand2 ) const
{
   return Complex( real + operand2.real, 
                   imaginary + operand2.imaginary );
} // kraj na funkcijata operator+ 

// Preklopi operator za odzemanje
Complex Complex::operator-( const Complex &operand2 ) const
{
   return Complex( real - operand2.real, 
                   imaginary - operand2.imaginary );
} // kraj na funkcijata operator- 

// Preklopi operator = 
const Complex& Complex::operator=( const Complex &right )
{
   real = right.real;
   imaginary = right.imaginary;
   return *this;   // ovozmozhuva kaskadiranje
} // ekraj na funkcijata operator= 

Complex Complex::operator*(const Complex &operand2) const
{
    double iSquared = imaginary * operand2.imaginary;
    double imaginaryResult = (real * operand2.imaginary) + 
                        (imaginary * operand2.real);
    double realResult = (real * operand2.real) + 
                    (iSquared * (-1));
    return Complex(realResult, imaginaryResult);
}

Complex Complex::operator*(const int number) const
{
    return Complex(real * number, imaginary * number);
}

Complex Complex::operator+=(const Complex &operand2)
{
    *this = *this + operand2;
}

Complex Complex::operator-=(const Complex &operand2)
{
    *this = *this - operand2;
}

Complex Complex::operator*=(const Complex &operand2)
{
    *this = *this * operand2;
}

bool operator==(Complex operand1, Complex operand2)
{
    if(operand1.real == operand2.real && 
      operand1.imaginary == operand2.imaginary)
      return true;
    else return false;
}

bool operator!=(Complex operand1, Complex operand2)
{
    if(operand1.real != operand2.real || 
      operand1.imaginary != operand2.imaginary)
      return true;
    else return false;
} 

ostream &operator<<(ostream &output, const Complex &number)
{
    output << "(" << number.real << ", "
           << number.imaginary << ")";
    return output;
}

istream &operator>>(istream &input , Complex &number)
{
    input >> number.real;
    input >> number.imaginary;
    return input;
}

Complex operator*(int number, Complex operand2)
{
    return Complex(number * operand2.real,
                    number * operand2.imaginary);
}

