#include <stdio.h>

int main()
{
    char c1, c2, c3, c4, c5;

    printf("Vnesete pet bukvi \n");
    scanf("%c %c %c %c %c", &c1, &c2, &c3, &c4, &c5);

    printf("Se dobi: %c%c%c%c%c", c5, c3, c2, c1, c4);

    return 0;
}