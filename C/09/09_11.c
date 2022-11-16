#include <stdio.h>

void findSubarray(float arrNumbers[], int n);

int main()
{
    int n;
    int i;

    printf("Vnesete dimenzii na nizata: ");
    scanf("%d", &n);

    float arrNumbers[n];

    for(i = 0; i < n; ++i)
    {
        printf("Vnesete element vo nizata: ");
        scanf("%f", &arrNumbers[i]);
    }

    findSubarray(arrNumbers, n);

    return 0;
}

void findSubarray(float arrNumbers[], int n)
{
    int i;
    int checkCondition = 0;

    printf("Pilesti podnizi se: \n");

    for(i = 1; i < n - 1; ++i)
    {
        if((arrNumbers[i - 1] > arrNumbers[i] && arrNumbers[i + 1] > arrNumbers[i]) || (arrNumbers[i - 1] < arrNumbers[i] && arrNumbers[i + 1] < arrNumbers[i]))
        {
            checkCondition = 1;
            printf("%.2f ", arrNumbers[i - 1]);
        }
        else
        {
            if(checkCondition == 1)
            {
                printf("%.2f %.2f \n", arrNumbers[i - 1], arrNumbers[i]);
                checkCondition = 0;
            }
        }
    }
    if(checkCondition == 1) printf("%.2f %.2f ", arrNumbers[n - 2], arrNumbers[n - 1]);
}
