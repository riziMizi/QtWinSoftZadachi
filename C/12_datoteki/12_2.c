#include <stdio.h>
#include <string.h>

int main()
{
    char *arrayLetter[] = {"YZ", "", "ABC", "DEF", "GHI",
                    "JKL", "MNO", "PQR", "STU", "VWX"};
    char word[8];
    int number[8];
    int counter = 0;
    char *tempArray;
    int i;
    int j;

    printf("Vnesete sedumbukven string: ");
    scanf("%s", word);
    if(strlen(word) != 7)
    {
        printf("mora da vnesete string od 7 karakteri.\n");
        exit(1);
    }

    for(i = 0; i < 7; ++i)
    {
        for(j = 0; j < 10 ; ++j)
        {
            if(j == 1) continue;
            tempArray = arrayLetter[j];
            if(j == 0)
            {
                if(tempArray[0] == toupper(word[i]) ||
                   tempArray[1] == toupper(word[i]))
                {
                        number[counter++] = j;
                        printf("%d", number[counter - 1]);
                }
            }
            else
            {
                 if(tempArray[0] == toupper(word[i]) ||
                   tempArray[1] == toupper(word[i]) ||
                    tempArray[2] == toupper(word[i]))
                {
                        number[counter++] = j;
                }
            }
        }
    }

    printf("%s = ", word);
    for(i = 0; i < 7; i++)
    {
        printf("%d",number[i]);
    }

    return 0;
}
