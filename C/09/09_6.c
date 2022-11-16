#include <stdio.h>

void sumOfCubes(int n);

int main()
{
    int n;

    printf("Vnesete priroden broj: ");
    scanf("%d", &n);

    sumOfCubes(n);

    return 0;
}

void sumOfCubes(int n)
{
    int i;
    int sum;
    int digit;
    int tempNumber;

    printf("Broevi pomali od brojot %d sto go ispolnuvaat uslovot se: ", n);
    for(i = 1; i < n; ++i)
    {
        sum = 0;
        tempNumber = i;
        while(tempNumber != 0)
        {
            digit = tempNumber % 10;
            tempNumber /= 10;
            sum = sum + (digit * digit * digit);
        }
        if(sum == i)
            printf("%d ", sum);
    }
}
