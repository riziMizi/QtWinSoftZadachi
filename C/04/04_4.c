#include <stdio.h>

int main()
{
    int sum;
    int counter;

    sum = 0;
    counter = 1;

    while(counter <= 10)
    {
        sum += counter;
        ++counter;
    }

    printf("Sumata na broevite od 1 do 10 e %d \n", sum);

    return 0;
}