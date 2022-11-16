
#include <stdio.h>

void selekcija(int arrSort[], int n, int i, int j, int min, int tempIndex);

int main()
{
    int n;
    int i;

    printf("Vnesete dimenzii na nizata: ");
    scanf("%d", &n);

    int arrSort[n];

    for(i = 0; i < n; ++i)
    {
        printf("Vnesi element vo nizata: ");
        scanf("%d", &arrSort[i]);
    }

    printf("Nesortiranata niza izgleda vaka: \n");
    for(i = 0; i < n; ++i)
    {
        printf("%d ", arrSort[i]);
    }

    selekcija(arrSort, n, 0, 0, 1000, 0);

    printf("\nSortiranata niza izgleda vaka: \n");
    for(i = 0; i < n; ++i)
    {
        printf("%d ", arrSort[i]);
    }
    return 0;
}

void selekcija(int arrSort[], int n, int i, int j, int min, int tempIndex)
{
    if(i == n && j == n) return;

    if(j < n)
    {
        if(min > arrSort[j])
        {
            min = arrSort[j];
            tempIndex = j;
        }
        selekcija(arrSort, n, i, ++j, min, tempIndex);
    }
    else
    {
        int tempValue = arrSort[i];
        arrSort[i] = min;
        arrSort[tempIndex] = tempValue;
        selekcija(arrSort, n, ++i, i, 1000, i);
    }
}
