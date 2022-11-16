#include <stdio.h>

int main() 
{    
   int number1, number2, number3, number4;
   printf("Vnesete cetiri celi broevi \n");
   scanf("%d %d %d %d", &number1, &number2, &number3, &number4);

   printf("Sumata od %d, %d, %d i %d e %d \n", number1, number2, number3, number4, 
                                             number1 + number2 + number3 + number4);
   
   return 0;
}