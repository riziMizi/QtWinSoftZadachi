#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char number[20];
    char *countryNumber;
    char phoneNumber[] = "";
    char *tempValue;
    int intCountryNumber;
    long longPhoneNumber;

    printf("Vnesete telefonski broj od oblik (333) 333-3333: ");
    gets(number);

    tempValue = strtok(&number[1], ")");
    countryNumber = tempValue;
    intCountryNumber = atoi(countryNumber);
    while(tempValue != NULL)
    {
        tempValue = strtok(NULL, "-");
        if(tempValue != NULL)
        {
             strcat(phoneNumber, tempValue);
        }
    }
    longPhoneNumber = atol(phoneNumber);

    printf("Brojot na drzavata e %d\n", intCountryNumber);
    printf("%Telefonskiot broj e %ld\n", longPhoneNumber);

    return 0;
}
