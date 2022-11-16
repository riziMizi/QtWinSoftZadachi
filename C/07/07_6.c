#include <stdio.h>

int nzd(int number1, int number2, int divisor);

int main()
{
   int number1, number2;
   int divisor;

   printf("Vnesete dva celi broevi. \n");
   scanf("%d %d", &number1, &number2);

   divisor = (number1 <= number2) ? number1 : number2;

   printf("NZD na broevite %d i %d e %d. \n", number1, number2, nzd(number1, number2, divisor));

   return 0;
}

int nzd(int number1, int number2, int divisor)
{
    if(number1 % divisor == 0 && number2 % divisor == 0) return divisor;
    nzd(number1, number2, --divisor);
}