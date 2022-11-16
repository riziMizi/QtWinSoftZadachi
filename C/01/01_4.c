#include <stdio.h>

int main() 
{
   int number1, number2, number3;

   printf("Vnesete tri celi broevi \n");
   scanf("%d %d %d", &number1, &number2, &number3);

   printf("Celobrojna sredna vrednost e %d \n", (number1 + number2 + number3) / 3);
   printf("Sumata od broevite e %d \n", number1 + number2 + number3);
   printf("Proizvodot od broevite e %d \n", number1 * number2 * number3);

   return 0;
}