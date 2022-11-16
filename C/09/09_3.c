#include <stdio.h>

int reverseNumber(int n);

int main()
{
    int n;

    printf("Vnesi nekoj priroden broj: ");
    scanf("%d", &n);

    printf("Sprotivniot broj na brojot %d e brojot %d.", n, reverseNumber(n));

    return 0;
}

int reverseNumber(int n)
{
    int digit;
    int reversedNumber = 0;
    while(n != 0)
    {
        digit = n % 10;
        n /= 10;
        reversedNumber = (reversedNumber + digit) * 10;
    }

    return reversedNumber / 10;
}
