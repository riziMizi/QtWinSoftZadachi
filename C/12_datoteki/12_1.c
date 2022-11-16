#include <stdio.h>

struct product {
    int productNumber;
    char productName[30];
    int productQuantity;
    float productPrice;
};

typedef struct product Product;

void postaviProdukti(FILE *ptr, int numberOfProducts);
void kompletenListing(FILE *ptr);
void izlistajSpecificenProdukt(FILE *ptr);
void izbrishiProdukt(FILE *ptr);
void azurirajProdukt(FILE *ptr);
void dodadiProdukt(FILE *ptr);
void prodazba(FILE *ptr);
int enterChoice(void);



int main()
{
    FILE *ptr;
    int choice;
    int i;
    int numberOfProducts;

    Product prod = {0, "", 0, 0.0};

    printf("Vnesete kolku produkti ima vashata prodacniva: ");
    scanf("%d", &numberOfProducts);



    if ((ptr = fopen( "hardware.dat", "wb+")) == NULL)
    {
      printf("Datotekata ne mozhe da se otvori.\n");
    }
    else
    {
        for(i = 1; i <= numberOfProducts; ++i)
        {
            fwrite(&prod, sizeof(Product), 1, ptr);
        }
        rewind(ptr);
        postaviProdukti(ptr, numberOfProducts);

        while((choice = enterChoice()) != 7)
        {
             switch ( choice )
             {
             case 1:
                 kompletenListing(ptr);
                 break;
             case 2:
                izlistajSpecificenProdukt(ptr);
                break;
             case 3:
                izbrishiProdukt(ptr);
                break;
             case 4:
                azurirajProdukt(ptr);
             case 5:
                dodadiProdukt(ptr);
                break;
             case 6:
                prodazba(ptr);
                break;
            default:
               printf( "Greshen izbor\n" );
               break;
             }
        }
        fclose(ptr);
    }

   return 0;
}

void postaviProdukti(FILE *ptr, int numberOfProducts)
{
    Product prod = {0, "", 0, 0.0};
    printf("Vnesete broj na produkt od 1 do %d. Za kraj vnesete 0.\n",
            numberOfProducts);
    scanf("%d", &prod.productNumber);

    while(prod.productNumber != 0)
    {
        printf("Vnesete ime, kolicina i cena na produktot: \n");
        scanf("%s%d%f",prod.productName,
              &prod.productQuantity, &prod.productPrice);

        fseek(ptr, (prod.productNumber - 1) *
              sizeof(Product), SEEK_SET);
        fwrite(&prod, sizeof(Product), 1, ptr);
        printf("Vnesete broj na produkt: ");
        scanf("%d", &prod.productNumber);
    }
}

void kompletenListing(FILE *ptr)
{
    Product prod = {0, "", 0, 0.0};
    rewind(ptr);
    printf("%-8s%-16s%-11s%10s\n", "Kod", "Ime na del",
        "Kolichina", "Cena");

    while(!feof(ptr))
    {
        fread(&prod, sizeof(Product), 1, ptr );

        if(prod.productNumber != 0)
        {
            printf("%-8d%-16s%-11d%10.2f\n", prod.productNumber,
                   prod.productName, prod.productQuantity,
                   prod.productPrice);
        }
    }
}

void izlistajSpecificenProdukt(FILE *ptr)
{
    Product prod = {0, "", 0, 0.0};
    int productNumber;

    printf("Vnesi broj na produkt: ");
    scanf("%d", &productNumber);

    fseek(ptr, (productNumber - 1) * sizeof(Product),
          SEEK_SET);
    fread(&prod, sizeof(Product), 1, ptr);

    if(prod.productNumber == 0)
        printf("Produktot %d nema informacii.\n", productNumber);
    else
         printf( "%-8d%-16s%-11d%10.2f\n",
         prod.productNumber, prod.productName,
         prod.productQuantity, prod.productPrice );
}

void izbrishiProdukt(FILE *ptr)
{
    Product prod;
    Product blankProduct = {0, "", 0, 0.0};
    int productNumber;

    printf("Vnesi broj na produkt: ");
    scanf("%d", &productNumber);

    fseek(ptr, (productNumber - 1) * sizeof(Product),
          SEEK_SET);
    fread(&prod, sizeof(Product), 1, ptr);
    if(prod.productNumber == 0)
    {
      printf("Produktot %d nema informacii.\n",
            productNumber);
    }
    else
    {
         if(prod.productQuantity != 0)
        {
            printf("Produktot %d nemoze da bide izbrishan"
                   " bidejki go ima na zaliha.\n", productNumber);
        }
        else
        {
            fseek(ptr, (productNumber - 1) * sizeof(Product),
              SEEK_SET);
            fwrite(&blankProduct, sizeof(Product), 1, ptr);
        }
    }
}

void azurirajProdukt(FILE *ptr)
{
    Product prod = {0, "", 0, 0.0};
    int productNumber;

    printf("Vnesi broj na produkt: ");
    scanf("%d", &productNumber);

    fseek(ptr, (productNumber - 1) * sizeof(Product),
          SEEK_SET);
    fread(&prod, sizeof(Product), 1, ptr);
    if(prod.productNumber == 0)
    {
      printf("Produktot %d nema informacii.\n",
            productNumber);
    }
    else
    {
         printf( "%-8d%-16s%-11d%10.2f\n",
         prod.productNumber, prod.productName,
         prod.productQuantity, prod.productPrice );
        printf("Vnesete ime, kolicina i cena na produktot: \n");
        scanf("%s%d%f",prod.productName,
              &prod.productQuantity, &prod.productPrice);

        fseek(ptr, (productNumber - 1) * sizeof(Product),
          SEEK_SET);
        fwrite(&prod, sizeof(Product), 1, ptr);
    }
}

void dodadiProdukt(FILE *ptr)
{
   Product prod = {0, "", 0, 0.0};

   int productNumber;

   printf("Vnesi broj na produkt: ");
    scanf("%d", &productNumber);

   fseek(ptr, (productNumber - 1) * sizeof(Product),
          SEEK_SET);
   fread(&prod, sizeof(Product), 1, ptr);


   if (prod.productNumber != 0)
   {
      printf( "Produktot %d e veke vnesen.\n",
              productNumber);
   }
   else
   {
       printf("Vnesete ime, kolicina i cena na produktot: \n");
       scanf("%s%d%f",prod.productName,
              &prod.productQuantity, &prod.productPrice);
      prod.productNumber = productNumber;

      fseek(ptr, (productNumber - 1) * sizeof(Product),
          SEEK_SET);

      fwrite(&prod, sizeof(Product), 1, ptr);
   }
}

void prodazba(FILE *ptr)
{
    Product prod = {0, "", 0, 0.0};
    int productNumber, productQuantity;

    printf("Vnesi broj na produkt i potrebna kolicina: ");
    scanf("%d%d", &productNumber, &productQuantity);

    fseek(ptr, (productNumber - 1) * sizeof(Product),
          SEEK_SET);
    fread(&prod, sizeof(Product), 1, ptr);
    if(prod.productNumber == 0)
    {
        printf("Produktot %d nema informacii.\n",
            productNumber);
    }
    else
    {
         printf( "%-8d%-16s%-11d%10.2f\n",
         prod.productNumber, prod.productName,
         prod.productQuantity, prod.productPrice );
         if(productQuantity > prod.productQuantity)
         {
             printf("Produktot %d ja nema baranata "
                    "kolicina na zaliha.\n");
         }
         else
         {
             prod.productQuantity -= productQuantity;
              printf( "%-8d%-16s%-11d%10.2f\n",
                 prod.productNumber, prod.productName,
                 prod.productQuantity, prod.productPrice );
             fseek(ptr, (productNumber - 1) * sizeof(Product),
                SEEK_SET);
             fwrite(&prod, sizeof(Product), 1, ptr);
         }
    }
}

int enterChoice()
{
   int menuChoice;

   printf( "\nVnesi izbor\n"
      "1 - Kompleten listing\n"
      "2 - Izlistaj produkt\n"
      "3 - Izbrishi produkt\n"
      "4 - Azuriraj Produkt\n"
      "5 - Dodadi produkt\n"
      "6 - Prodazba\n"
      "7 - Kraj na programot\n? ");

   scanf("%d", &menuChoice);

   return menuChoice;
}
