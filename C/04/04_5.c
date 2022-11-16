#include <stdio.h>

int main()
{
    int niza[10];
    int counter;
    int result;

    counter = 0;
    result = 1;

    printf("Vnesete 10 broevi \n");

    while(counter < 10)
    {
       scanf("%d", &niza[counter]);
       ++counter;
    }

    counter = 0;
    while(counter < 10)
    {
       result *= niza[counter];
       ++counter;
    }

    printf("Proizvodot od vnesenite 10 broevi e %d", result);

    return 0;

}