#include <stdio.h>

void prosti(int arrPrimeNumbers[], int size);

int main()
{
    int n;
    int i, j;
    int flagIsPrime;

    printf("Vnesete dimenzii na nizata: ");
    scanf("%d", &n);

    int arrPrimeNumbers[n];

    for(int i = 0; i < n; ++i)
    {
        arrPrimeNumbers[i] = 1;
    }

    for(i = 0; i < n; ++i)
    {
        printf("Vnesete broj vo nizata: ");
        scanf("%d", &arrPrimeNumbers[i]);
    }

    prosti(arrPrimeNumbers, n);

    printf("Prosti broevi vo nizata se: \n");
    for(i = 0; i < n; ++i)
    {
        flagIsPrime = 1;
        for(j = 2; j < arrPrimeNumbers[i]; ++j)
        {
            if(arrPrimeNumbers[i] % j == 0)
            {
                flagIsPrime = 0;
                break;
            }
        }
        if(flagIsPrime == 1 && arrPrimeNumbers[i] != 0 && arrPrimeNumbers[i] != 1)
        {
            printf("%d ", arrPrimeNumbers[i]);
        }
    }

    return 0;
}

void prosti(int arrPrimeNumbers[], int size)
{
    int i, j;
    int flagIsPrime; //Ako e ne e prost broj ovaa promenliva se setira na 0.

    for(i = 2; i < size; ++i)
    {
        flagIsPrime = 1;
        for(j = 2; j < i; ++j)
        {
            if(i % j == 0)
            {
                flagIsPrime = 0;
                break;
            }
        }
        if(flagIsPrime == 1)
        {
            arrPrimeNumbers[i] = 0;
        }
    }
}
