#include <stdio.h>

int paren(int number);

int main()
{
    int i;
    int number;
    int checkNumber;
    for(i = 0; i < 10; ++i)
    {
        printf("Vnesete cel broj \n");
        scanf("%d", &number);
        checkNumber = paren(number);
        if(checkNumber == 1)
        {
            printf("Brojot %d e paren broj. \n", number);
        }
        else
        {
             printf("Brojot %d e neparen broj. \n", number);
        }
    }

    return 0;
}

int paren(int number)
{
    if(number % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}