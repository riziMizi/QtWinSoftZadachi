#include <stdio.h>

#define SIZE 10

void clearArrayValues(int arrNumbers[]);
void checkIfAllDigitsExist(int arrNumers[], int number);

int main()
{
    int n;
    int i, j;
    int squaredNumber;
    int cubedNumber;
    int digit;
    int arrCheckIfNumberExists[SIZE] = {0};

    printf("Vnesete do koj priroden broj da se prebaruva: ");
    scanf("%d", &n);

    for(i = 1; i <= n; ++i)
    {
        squaredNumber = i * i;
        cubedNumber = i * i * i;

        while(squaredNumber != 0 || cubedNumber != 0)
        {
            if(squaredNumber != 0) // podelba na kvadratot na brojot
            {
                digit = squaredNumber % 10;
                squaredNumber /= 10;
                if(arrCheckIfNumberExists[digit] > 0)
                {
                    clearArrayValues(arrCheckIfNumberExists);
                    break;
                }
                else
                {
                    arrCheckIfNumberExists[digit]++;
                }
            }

             if(cubedNumber != 0) // podelba na cifrite na kubot na brojot
            {
                digit = cubedNumber % 10;
                cubedNumber /= 10;
                if(arrCheckIfNumberExists[digit] > 0)
                {
                    clearArrayValues(arrCheckIfNumberExists);
                    break;
                }
                else
                {
                    arrCheckIfNumberExists[digit]++;
                }
            }

        }
        checkIfAllDigitsExist(arrCheckIfNumberExists, i);
    }

    return 0;
}

void clearArrayValues(int arrNumbers[])
{
    int i;

    for(i = 0; i < SIZE; ++i)
    {
        arrNumbers[i] = 0;
    }
}

void checkIfAllDigitsExist(int arrNumbers[], int number)
{
    int i;
    int allDigitsExist = 1;

    for(i = 0; i < SIZE; ++i)
    {
        if(arrNumbers[i] < 1)
        {
            allDigitsExist = 0;
            break;
        }
    }

    if(allDigitsExist == 1)
    {
        printf("Brojot %d go ispolnuva uslovot. \n", number);
    }
}
