#include <iostream>
#include <iomanip>

using namespace std;

#include "Dropki.h"

Dropki::Dropki(int broitel, int imenitel)
{
    setValues(broitel, imenitel);
}

void Dropki::setValues(int numenator, int denominator)
{
    broitel = numenator;
    imenitel = (denominator == 0) ? 1 : denominator;
}

int findGCD(int number1, int number2) {
   if (number2 == 0)
      return number1;
      return findGCD(number2, number1 % number2);
}

void reduceFraction(int &number1, int &number2){
    int gcd;
    gcd = findGCD(number1, number2);
    number1 /= gcd;
    number2 /= gcd;
}

Dropki Dropki::operator+(Dropki fraction)
{
    Dropki temp;
    int numenator1 = broitel;
    int numenator2 = fraction.getBroitel();
    int denominator1 = imenitel;
    int denominator2 = fraction.getImenitel();
    int denominatorResult;
    int numenatorResult;

    if((denominator1 % denominator2 == 0) || (denominator2 % denominator1 == 0))
    {
        if(denominator1 >= denominator2) denominatorResult = denominator1;
        else denominatorResult = denominator2;
    }
    else
    {
        denominatorResult = denominator1 * denominator2;
    }

    numenator1 = (denominatorResult / denominator1) * numenator1;
    numenator2 = (denominatorResult / denominator2) * numenator2;
    
    numenatorResult = numenator1 + numenator2;

    reduceFraction(numenatorResult, denominatorResult);

    temp.broitel = numenatorResult;
    temp.imenitel = denominatorResult;

    return temp;
}

Dropki Dropki::operator+(int number)
{
    Dropki temp;
    int numenator1 = broitel;
    int denominator1 = imenitel;
    int numenator2 = number * denominator1;
    int numenatorResult;
    
    numenatorResult = numenator1 + numenator2;

    reduceFraction(numenatorResult, denominator1);

    temp.broitel = numenatorResult;
    temp.imenitel = denominator1;

    return temp;
}

Dropki Dropki::operator-(Dropki fraction)
{
    Dropki temp;
    int numenator1 = broitel;
    int numenator2 = fraction.getBroitel();
    int denominator1 = imenitel;
    int denominator2 = fraction.getImenitel();
    int denominatorResult;
    int numenatorResult;

    if((denominator1 % denominator2 == 0) || (denominator2 % denominator1 == 0))
    {
        if(denominator1 >= denominator2) denominatorResult = denominator1;
        else denominatorResult = denominator2;
    }
    else
    {
        denominatorResult = denominator1 * denominator2;
    }

    numenator1 = (denominatorResult / denominator1) * numenator1;
    numenator2 = (denominatorResult / denominator2) * numenator2;
    
    numenatorResult = numenator1 - numenator2;

    reduceFraction(numenatorResult, denominatorResult);

    temp.broitel = numenatorResult;
    temp.imenitel = denominatorResult;

    return temp;
}

Dropki Dropki::operator-(int number)
{
    Dropki temp;
    int numenator1 = broitel;
    int denominator1 = imenitel;
    int numenator2 = number * denominator1;
    int numenatorResult;
    
    numenatorResult = numenator1 - numenator2;

    reduceFraction(numenatorResult, denominator1);

    temp.broitel = numenatorResult;
    temp.imenitel = denominator1;

    return temp;
}

Dropki Dropki::operator*(Dropki fraction)
{
    Dropki temp;
    int numenator1 = broitel;
    int numenator2 = fraction.getBroitel();
    int denominator1 = imenitel;
    int denominator2 = fraction.getImenitel();
    int denominatorResult;
    int numenatorResult;

    numenatorResult = numenator1 * numenator2;
    denominatorResult = denominator1 * denominator2;

    reduceFraction(numenatorResult, denominatorResult);

    temp.broitel = numenatorResult;
    temp.imenitel = denominatorResult;

    return temp;
}

Dropki Dropki::operator*(int number)
{
    Dropki temp;
    int numenator1 = broitel;
    int denominator1 = imenitel;
    int numenatorResult;

    numenatorResult = numenator1 * number;

    reduceFraction(numenatorResult, denominator1);

    temp.broitel = numenatorResult;
    temp.imenitel = denominator1;

    return temp;
}

Dropki Dropki::operator/(Dropki fraction)
{
    Dropki temp;
    int numenator1 = broitel;
    int numenator2 = fraction.getBroitel();
    int denominator1 = imenitel;
    int denominator2 = fraction.getImenitel();
    int denominatorResult;
    int numenatorResult;

    numenatorResult = numenator1 * denominator2;
    denominatorResult = numenator2 * denominator1;

    reduceFraction(numenatorResult, denominatorResult);

    temp.broitel = numenatorResult;
    temp.imenitel = denominatorResult;

    return temp;
}

Dropki Dropki::operator/(int number)
{
    Dropki temp;
    int numenator1 = broitel;
    int denominator1 = imenitel;
    int denominatorResult;

    denominatorResult = denominator1 * number;

    reduceFraction(numenator1, denominatorResult);

    temp.broitel = numenator1;
    temp.imenitel = denominatorResult;

    return temp;
}

void Dropki::printFractionAsString()
{
    cout << setprecision(2);
    cout << broitel << "/" << imenitel <<
    " = " << printFractionAsFloat() << endl;;
}

float Dropki::printFractionAsFloat()
{
    return (float) broitel / imenitel;
}

