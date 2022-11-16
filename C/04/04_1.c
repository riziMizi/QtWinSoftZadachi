#include <stdio.h>
 
/* pocnuva izvrshuvanjeto */
int main()
{
   int mesec;              /* definiraj promenliva za mesec*/
 
   printf("Vnesi go mesecot so negoviot reden broj: ");
   scanf("%d", &mesec);
 
   /* vo zavisnost od vneseniot mesec najdi kolku dena ima */
   switch (mesec) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
                printf("Ima 31 den\n");
                
    case 4:
    case 6:
    case 9:
    case 11:
                printf("Ima 30 dena\n");
               
    case 2:
                printf("Vo prestapni godini ima 29, a vo obichni 28 dena\n");
                
    default:
                printf("Greshen broj na mesec!\n");
   } /* kraj na switch (mesec) */
 
   return 0; /* uspeshen kraj na programot */
                            
} // Dokolku se izbrishat break naredbite site poraki pod case-ot sto bil
  // povikan ke bidat ispechateni na ekran, odnosno dokolku od tastatura se
  // vnese 4 na ekran ke bidat ispechateni site poraki pod case 4.
