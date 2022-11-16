#include <stdio.h>

void findAscendingArrays(float arrNumbers[], int n);

int main()
{
    int n;
    int i;

    printf("Vnesete dimnezii na nizata: ");
    scanf("%d", &n);

    float arrNumbers[n];

    for(i = 0; i < n; ++i)
    {
        printf("Vnesete element vo nizata: ");
        scanf("%f", &arrNumbers[i]);
    }

    findAscendingArrays(arrNumbers, n);

    return 0;
}

void findAscendingArrays(float arrNumbers[], int n)
{
    int i;
    int counter = 0;

    printf("Rastecki podnizi se: \n");
    for(i = 1; i < n; ++i)
    {
        if(arrNumbers[i] > arrNumbers[i - 1])
        {
            counter++;
            if(counter > 0) printf("%.2f ", arrNumbers[i - 1]);
        }
        else
        {
            if(counter > 0) printf("%.2f \n", arrNumbers[i - 1]);
            counter = 0;
        }
    }

    if(counter > 0) printf("%.2f ", arrNumbers[n - 1]); // za da se ispechati i posledniot element
                                                        // ako pripaga vo rasteckata niza
}
