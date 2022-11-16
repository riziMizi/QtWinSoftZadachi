#include <stdio.h>
#include <stdlib.h>

struct listNode {
    int broj;
    struct listNode *next;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void vnesi(ListNodePtr *sPtr, int broj);
void printList(ListNodePtr currentPtr);
void sortOpaganje(ListNodePtr currentPtr);
void sortRastenje(ListNodePtr currentPtr);
void brisi(ListNodePtr *currentPtr, int number);
void instructions(void);

int main()
{
   ListNodePtr startPtr = NULL;
   int choice;
   int broj;

   instructions();
   printf("? ");
   scanf( "%d", &choice );

   while (choice != 5) {

      switch (choice) {

         case 1:
            printf("Vnesi cel broj: ");
            scanf("%d", &broj);
            vnesi(&startPtr, broj);
            printList(startPtr);
            break;
         case 2:
             sortOpaganje(startPtr);
             break;
         case 3:
            sortRastenje(startPtr);
            break;
         case 4:
            printf("Vnesi koj element da se izbrishe: ");
            scanf("%d", &broj);
            brisi(&startPtr, broj);
            printList(startPtr);
            break;
         default:
            printf("Greshen izbor.\n");
            instructions();
            break;
      }

      printf("? ");
      scanf("%d", &choice);
   }

   printf("Kraj.\n");

   return 0;
}

void instructions(void)
{
   printf("Vnesi izbor:\n"
      "   1 za vnesuvanje element vo lista.\n"
      "   2 za sortiranje na listata vo opagacki redosled.\n"
      "   3 za sortiranje na listata vo rastecki redosled.\n"
      "   4 za brisenje na element vo lista.\n"
      "   5 za kraj.\n" );
}

void vnesi(ListNodePtr *sPtr, int broj)
{
   ListNodePtr newPtr;
   ListNodePtr previousPtr;
   ListNodePtr currentPtr;

   newPtr = malloc(sizeof(ListNode));

   if(newPtr != NULL)
    {
      newPtr->broj = broj;
      newPtr->next = NULL;

      previousPtr = NULL;
      currentPtr = *sPtr;

      while(currentPtr != NULL)
      {
         previousPtr = currentPtr;
         currentPtr = currentPtr->next;
      }

    if (previousPtr == NULL)
      {
         newPtr->next = *sPtr;
         *sPtr = newPtr;
      }
      else
      {
         previousPtr->next = newPtr;
         newPtr->next = currentPtr;
      }
   }
   else
   {
      printf("Nema dovolno memorija.\n");
   }
}

void printList(ListNodePtr currentPtr)
{
   if (currentPtr == NULL)
   {
      printf("Listata e prazna.\n");
   }
   else
   {
      printf("Listata e:\n");

      while (currentPtr != NULL) {
         printf("%d --> ", currentPtr->broj);
         currentPtr = currentPtr->next;
      }
      printf("NULL\n\n");
   }
}

void sortOpaganje(ListNodePtr currentPtr)
{
    ListNodePtr newPtr;
    ListNodePtr strPtr = currentPtr;
    if(strPtr == NULL)
    {
        printf("Listata e prazna. \n");
    }
    else
    {
        while(strPtr->next != NULL)
        {
            newPtr = strPtr->next;
            while(newPtr != NULL)
            {
                if(strPtr->broj < newPtr->broj)
                {
                    int tempValue = strPtr->broj;
                    strPtr->broj = newPtr->broj;
                    newPtr->broj = tempValue;
                }
                newPtr = newPtr->next;
            }
            strPtr = strPtr->next;
        }
        printList(currentPtr);
    }
}

void sortRastenje(ListNodePtr currentPtr)
{
    ListNodePtr newPtr;
    ListNodePtr strPtr = currentPtr;
    if(strPtr == NULL)
    {
        printf("Listata e prazna. \n");
    }
    else
    {
        while(strPtr->next != NULL)
        {
            newPtr = strPtr->next;
            while(newPtr != NULL)
            {
                if(strPtr->broj > newPtr->broj)
                {
                    int tempValue = strPtr->broj;
                    strPtr->broj = newPtr->broj;
                    newPtr->broj = tempValue;
                }
                newPtr = newPtr->next;
            }
            strPtr = strPtr->next;
        }
        printList(currentPtr);
    }
}

void brisi(ListNodePtr *sPtr, int number)
{
   ListNodePtr previousPtr;
   ListNodePtr currentPtr;
   ListNodePtr tempPtr;

   if (number == (*sPtr)->broj)
    {
       tempPtr = *sPtr;
       *sPtr = (*sPtr)->next;
       free(tempPtr);
    }
   else
   {
      previousPtr = *sPtr;
      currentPtr = (*sPtr)->next;

      while (currentPtr != NULL && currentPtr->broj != number)
      {
         previousPtr = currentPtr;
         currentPtr = currentPtr->next;
      }

      if (currentPtr != NULL)
      {
         tempPtr = currentPtr;
         previousPtr->next = currentPtr->next;
         free(tempPtr);
      }
   }
}




