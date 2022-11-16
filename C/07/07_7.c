#include <stdio.h>

void dzvezdi(int n);
void printStars(int n);

int main()
{
    int n;

    printf("Vnesete cel broj: ");
    scanf("%d", &n);

    dzvezdi(n);

    return 0;
}

void dzvezdi(int n)
{
    if(n == 0)
    {
        return;
    }
    else
    {
        printStars(n);
        dzvezdi(--n);
    }
}

void printStars(int n)
{
    if(n == 0)
    {
        printf("\n");
        return;
    }
    else
    {
        printf("* ");
        printStars(--n);
    }
}