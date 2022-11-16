#include <stdio.h>

int main()
{
    int number;
    int sum;

    sum = 0;
    printf("Vnesuvajte broevi \n");
    scanf("%d", &number);

    while(number != -1)
    {
        sum += number;
        scanf("%d", &number);
    }

    printf("Sumata na vnesenite broevi e %d", sum);

    return 0;
}