#include <stdio.h>

void perfectNumber(int n);

int main()
{
    int n;

    printf("Vnesete nekoj priroden broj pogolem od 1: ");
    scanf("%d", &n);

    perfectNumber(n);

    return 0;
}

void perfectNumber(int n)
{
    int i, j;
    int sum;
    printf("Sovrsheni broevi pomali od brojot %d se broevite: ", n);
    for(i = 2; i < n; ++i)
    {
        sum = 0;
        for(j = i - 1; j > 0; j--)
        {
            if(i % j == 0) sum += j;
        }
        if(sum == i)
            printf("%d ", sum);
    }
}
