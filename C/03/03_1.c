#include <stdio.h>

int main() 
{
    int number1, number2;
    printf("Vnesete dva broevi za sporedba \n");
    scanf("%d %d", &number1, &number2);

    if(number1 > number2)
    {
        printf("%d e pogolem od %d", number1, number2);
    }
    else if(number1 < number2)
    {
        printf("%d e pogolem od %d", number2, number1);
    }
    else
    {
        printf("Broevite se ednakvi");
    }

    return 0;
}