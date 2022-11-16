#include <stdio.h>

void pechatiBitovi(unsigned number);
unsigned prevtiBitovi(unsigned number);

int main()
{
    unsigned number;
    unsigned reversedNumber;

    printf("Vnesete unsigned vrednost: ");
    scanf("%u", &number);

    printf("Bitovite pred da bidat prevrteni: ");
    pechatiBitovi(number);

    reversedNumber = prevtiBitovi(number);
    printf("Prevrteni bitovi: ");
    pechatiBitovi(reversedNumber);

    return 0;
}

unsigned prevtiBitovi(unsigned number)
{
    unsigned reversedNumber = 0;

    while(number > 0)
    {
        if(number & 1 == 1) reversedNumber ^= 1;
        reversedNumber <<= 1;
        number >>= 1;
    }
    printf("%u\n", reversedNumber);

    return reversedNumber;
}

void pechatiBitovi(unsigned number)
{
    unsigned i;

    unsigned pechatiMaska = 1 << 31;

   for (i = 1; i <= 32; ++i)
   {
      putchar(number & pechatiMaska ? '1' : '0');
      number <<= 1;

      if (i % 8 == 0)
      {
         putchar(' ');
      }
   }
   putchar('\n');
}
