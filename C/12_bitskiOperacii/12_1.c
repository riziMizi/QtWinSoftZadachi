#include <stdio.h>

int mnoziSoStepenOdDva(int broj, int stepen);

int main()
{
    int broj, stepen;

    printf("Vnesete broj: ");
    scanf("%d", &broj);
    printf("Vnesete stepen: ");
    scanf("%d", &stepen);

    printf("Rezultatot od operacijata %d * 2^%d iznesuva %d",
                                            broj, stepen, mnoziSoStepenOdDva(broj, stepen));

    return 0;
}

int mnoziSoStepenOdDva(int broj, int stepen)
{
    return broj << stepen;
}
