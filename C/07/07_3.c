#include <stdio.h>

int obratno(int number);

int main()
{
    int number;
    int reveresedNumber;

    printf("Ve molime da vnesete cel broj \n");
    scanf("%d", &number);

    reveresedNumber = obratno(number);
    printf("Brojot %d vo obraten redosled e %d \n", number, reveresedNumber);

    return 0;
}

int obratno(int number)
{
    int reveresedNumber = 0;
    int digit;
    while(number != 0)
    {
        digit = number % 10;
        number /= 10;
        reveresedNumber = (reveresedNumber + digit) * 10;
    }
    return reveresedNumber / 10;
}