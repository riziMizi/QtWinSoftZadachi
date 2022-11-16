#include <stdio.h>

int reverseNumber(int n);
void checkNumbersInRange(int n1, int n2);

int main()
{
    int n1, n2;

    printf("Vnesete gi intervalite n1 i n2: ");
    scanf("%d%d", &n1, &n2);

    if(n2 < n1)
    {
        printf("Intervalot n2 mora da bide pogolem od intervalot n1!!");
        exit(0);
    }

    checkNumbersInRange(n1, n2);

    return 0;
}

void checkNumbersInRange(int n1, int n2)
{
    int i;
    int reversed;

    printf("Broevite sto go ispolnuvaat uslovot se: ");
    for(i = n1; i <= n2; ++i)
    {
        reversed = reverseNumber(i);
        if(i % reversed == 0)
            printf("%d ", i);
    }
}

int reverseNumber(int n)
{
    int digit;
    int reversedNumber = 0;
    while(n != 0)
    {
        digit = n % 10;
        n /= 10;
        reversedNumber = (reversedNumber + digit) * 10;
    }

    return reversedNumber / 10;
}

