#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct stackNode {
   char data;
   struct stackNode *nextPtr;
};

typedef struct stackNode StackNode; /* sinonim za struct stackNode */
typedef StackNode *StackNodePtr; /* sinonim za StackNode* */

/* prototipovi */
void push( StackNodePtr *topPtr, char info );
char pop( StackNodePtr *topPtr );

/* pochetok na izvrshuvanjeto */
int main()
{
   StackNodePtr stackPtr = NULL; /* pokazhuva na vrvot na stekot */
   char text[100];
   int i;

   printf("Vnesete tekst: ");
   gets(text);

   for(i = 0; i < strlen(text); ++i)
   {
       push(&stackPtr, text[i]);
   }

   for(i = 0; i < strlen(text); ++i)
   {
       printf("%c", pop(&stackPtr));
   }

   return 0;

}

/* Vnesi jazel na vrvot na stekot */
void push( StackNodePtr *topPtr, char info )
{
   StackNodePtr newPtr; /* pokazhuvach do noviot jazel */

   newPtr = malloc( sizeof( StackNode ) );

   /* vnesi jazel na vrvot na stekot */
   if ( newPtr != NULL ) {
      newPtr->data = info;
      newPtr->nextPtr = *topPtr;
      *topPtr = newPtr;
   } /* kraj if */
   else { /* nema mesto */
      printf( "%d ne e vnesen. Nema dovolno memorija.\n", info );
   } /* kraj else */

} /* kraj na funkcijata push */

/* Izvadi jazel od vrvot na stekot */
char pop( StackNodePtr *topPtr )
{
   StackNodePtr tempPtr; /* pokazhuvach do privremen jazol */
   char popValue; /* vrednost na jazelot */

   tempPtr = *topPtr;
   popValue = ( *topPtr )->data;
   *topPtr = ( *topPtr )->nextPtr;
   free( tempPtr );

   return popValue;

} /* kraj na funkcijata pop */
