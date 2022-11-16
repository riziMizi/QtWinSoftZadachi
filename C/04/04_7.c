#include <stdio.h>

int main()
{
    int sum;
    int number;
    char loopCharacter; //ova ke bide karakterot d ili n

    sum = 0;
    loopCharacter = 'd';

    while(loopCharacter != 'n')
    {
        printf("Vnesi broj: ");
        scanf("%d", &number);

        sum += number;

        printf("Ushte? (d/n):");
        scanf(" %c", &loopCharacter);
        printf("\n");
    } 

    printf("Sumata na vnesenite broevi e %d", sum);

    return 0;
}