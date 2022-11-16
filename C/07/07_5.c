#include <stdio.h>

long fibonacii(long number);

int main()
{
    int firstNumber = 1;
    int secondNumber = 1;
    int sum;
    int i;
    long number;
    long result;

    printf("Vnesete cel broj \n");
    scanf("%ld", &number);

    result = fibonacii(number);

    printf( "Fibonacci( %ld ) = %ld\n", number, result );

    return 0;
}

long fibonacii(long number)
{
    int firstNumber = 1;
    int secondNumber = 1;
    int sum, i;

    if(number == 1 || number == 2) return 1;

    for(i = 2; i < number; i++)
    {
        sum = firstNumber + secondNumber;
        firstNumber = secondNumber;
        secondNumber = sum;
    }

    return sum;
}