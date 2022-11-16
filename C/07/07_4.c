#include <stdio.h>

int nzd(int number1, int number2);

int main()
{
    int number1, number2;
    int result;

    printf("Vnesete dva celi broevi \n");
    scanf("%d %d", &number1, &number2);

    result = nzd(number1, number2);
    printf("NZD na broevite %d i %d e %d \n", number1, number2, result);

    return 0;
}

int nzd(int number1, int number2)
{
    int i = 1;
    int max = 0;

    while(i <= number1 && i <= number2)
    {
        if(number1 % i == 0 && number2 % i == 0)
        {
            if(i > max)
            {
                max = i;
            }
        }
        i++;
    }
    return max;
}