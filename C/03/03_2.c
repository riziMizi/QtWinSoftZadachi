#include <stdio.h>

int main() 
{
    int number1, number2;

    printf("Vnesete dva celi broevi \n");
    scanf("%d %d", &number1, &number2);

    if(number1 % 2 == 0)
    {
        printf("Brojot %d e paren \n", number1);
    }
    else
    {
        printf("Brojot %d e neparen \n", number1);
    }

     if(number2 % 2 == 0)
    {
        printf("Brojot %d e paren \n", number2);
    }
    else
    {
        printf("Brojot %d e neparen \n", number2);
    }

    return 0;
}