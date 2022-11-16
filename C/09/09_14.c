#include <stdio.h>

void recursiveFunction(int n, int goToZero, int goToN);
void printNumbers(int n, int m);

int main()
{
    int n;

    printf("Vnesete priroden broj: ");
    scanf("%d", &n);

    recursiveFunction(n, n, 2);

    return 0;
}

void recursiveFunction(int n, int goToZero, int goToN)
{
    if(goToN == n + 1)
    {
        return;
    }

    if(goToZero > 0)
    {
        printNumbers(n, goToZero);
        recursiveFunction(n, --goToZero, goToN);
    }
    else
    {
        printNumbers(n, goToN);
        recursiveFunction(n, goToZero, ++goToN);
    }
}

void printNumbers(int n, int m)
{
    if(n == m)
    {
        printf("%d\n", n);
        return;
    }
    printf("%d ", m);
    printNumbers(n, ++m);
}



