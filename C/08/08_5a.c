#include <stdio.h>

/* 5. v) Procesirackite kapaciteti na ova sortiranje se slicni na
bubble sort poradi toa sto i dvete sortiranja imaat vremenska
kompleksnost O(N^2), odnosno i vo dvata slucaevi imame 2 vgnezdeni
for ciklusi koi iteriraat od index 0 do index n.
*/

void selekcija(int arrSort[], int n);

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

    selekcija(arrSort, n);

    printf("\nSortiranata niza izgleda vaka: \n");
    for(i = 0; i < n; ++i)
    {
        printf("%d ", arrSort[i]);
    }
    return 0;
}

void selekcija(int arrSort[], int n)
{
    int i, j;
    int min;
    int tempIndex;
    int tempValue;

    for(i = 0; i < n; ++i)
    {
        min = 1000;
        tempIndex = i;
        for(j = i; j < n; ++j)
        {
            if(min > arrSort[j])
            {
                min = arrSort[j];
                tempIndex = j;
            }
        }
        tempValue = arrSort[i];
        arrSort[i] = min;
        arrSort[tempIndex] = tempValue;
    }
}
