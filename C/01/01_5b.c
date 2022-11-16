#include <stdio.h>

int main() 
{
    int number;
    int digit1, digit2, digit3, digit4, digit5;

    printf("Vnesete petcifren broj \n");
    scanf("%d", &number);

    digit5 = number % 10;
    number /= 10;
    digit4 = number % 10;
    number /= 10;
    digit3 = number % 10;
    number /= 10;
    digit2 = number % 10;
    number /= 10;
    digit1 = number % 10;

    printf("%d   %d   %d   %d   %d \n", digit1, digit2, digit3, digit4, digit5);

    return 0;
}