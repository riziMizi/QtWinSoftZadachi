#include <stdio.h>
#include <string.h>

#define SIZE 100

int palindrom(char arrPalindrom[]);

int main()
{
    int i;
    char arrPalindrom[SIZE];
    int isPalindrom;

    printf("Vnesete nekoj zbor: ");
    scanf("%s", arrPalindrom);

    isPalindrom = palindrom(arrPalindrom);

    if(isPalindrom == 1)
    {
        printf("Zborot %s e palindrom.", arrPalindrom);
    }
    else
    {
        printf("Zborot %s ne e palindrom.", arrPalindrom);
    }

    return 0;
}

int palindrom(char arrPalindrom[])
{
    int i, j;
    int stringSize = strlen(arrPalindrom);

    for(i = 0, j = stringSize - 1; i < stringSize; i++, j--)
    {
        if(arrPalindrom[i] != arrPalindrom[j]) return 0;
    }

    return 1;
}
