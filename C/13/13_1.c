#include <stdio.h>
#include <stdlib.h>

struct listNode {
    char karakter;
    int broj;
    struct listNode *next;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insert( ListNodePtr *sPtr, char karakter, int broj );
void printList( ListNodePtr currentPtr );
void pechatiListaNanazad(ListNodePtr currentPtr);
void instructions( void );


int main()
{
   ListNodePtr startPtr = NULL; /* vo pochetokot nema jazli */
   int choice; /* korisnichki izbor */
   char karakter;
   int broj;  /* korisnichki vnesen karakter */

   instructions(); /* pechati meni */
   printf( "? " );
   scanf( "%d", &choice );

    /* vrti dodeka korisnikot ne vnese 3 */
   while (choice != 3) {

      switch (choice) {

         case 1:
            printf("Vnesi karakter: ");
            scanf("\n%c", &karakter); // vnesi karakter
            printf("Vnesi cel broj: ");
            scanf("%d", &broj); // vnesi cel broj
            insert(&startPtr, karakter, broj); /* vnesi element vo listata */
            printList(startPtr);
            break;
         case 2:
             pechatiListaNanazad(startPtr);
             printf("\n");
             break;
         default:
            printf( "Greshen izbor.\n\n" );
            instructions();
            break;

      } /* kraj switch */

      printf( "? " );
      scanf( "%d", &choice );
   } /* kraj while */

   printf( "Kraj.\n" );

   return 0; /* uspeshen kraj */

}

/* ispechati gi instrukciite za korisnikot */
void instructions( void )
{
   printf( "Vnesi izbor:\n"
      "   1 za vnesuvanje element vo lista.\n"
      "   2 za pechatenje na listata nanazad.\n"
      "   3 za kraj.\n" );
} /* kraj na funkcijata instructions */

void insert( ListNodePtr *sPtr, char karakter, int broj )
{
   ListNodePtr newPtr;      /* pointer do nov jazel */
   ListNodePtr previousPtr; /* pokazhuvach do prethodniot jazel vo listata */
   ListNodePtr currentPtr;  /* pokazhuvach do tekovniot jazel */

   newPtr = malloc( sizeof( ListNode ) ); /* sozdadi jazel */

   if ( newPtr != NULL ) { /* ako ima mesto */
      newPtr->karakter = karakter;/* stavi vrednost vo jazelot */
      newPtr->broj = broj;
      newPtr->next = NULL; /* jazelot ne e povrzan so drug jazel */

      previousPtr = NULL;
      currentPtr = *sPtr;

      /* vrti dodeka ne ja najdesh tochnata pozicija vo listata */
      while ( currentPtr != NULL ) {
         previousPtr = currentPtr;          /* odi do ...   */
         currentPtr = currentPtr->next;  /* ... sledniot jazel */
      } /* kraj while */

      /* vnesi nov jazel na pochetokot na listata */
      if ( previousPtr == NULL ) {
         newPtr->next = *sPtr;
         *sPtr = newPtr;
      } /* kraj if */
      else { /* vnesi nov jazel megju previousPtr i currentPtr */
         previousPtr->next = newPtr;
         newPtr->next = currentPtr;
      } /* kraj else */

   } /* kraj if */
   else {
      printf( "Nema dovolno memorija.\n");
   } /* kraj else */
} /* kraj na funkcijata insert */

/* Ispechati ja listata */
void printList( ListNodePtr currentPtr )
{

   /* ako listata e prazna */
   if ( currentPtr == NULL ) {
      printf( "Listata e prazna.\n\n" );
   } /* kraj if */
   else {
      printf( "Listata e:\n" );

      /* dodeka ne e kraj na listata */
      while ( currentPtr != NULL ) {
         printf( "%d%c --> ", currentPtr->broj, currentPtr->karakter );
         currentPtr = currentPtr->next;
      } /* kraj while */

      printf( "NULL\n\n" );
   }
} /* kraj else */

void pechatiListaNanazad(ListNodePtr currentPtr)
{
    if(currentPtr != NULL)
    {
        pechatiListaNanazad(currentPtr->next);
        printf("%d%c --> ", currentPtr->broj, currentPtr->karakter);
    }
}


