#include <stdio.h>

int main()
{
    // Realizirano e so dve nizi vo slucaj korisnikot da ne gi vnesuva
    // produktite po pravilen redosled da se znae koja vrednost za koj produkt e.
    int counter;
    float arrayIncomePerProduct[5]; // niza sto ke cuva prodadena vrednost po produkt
    int arrayForProductNumber[5];  // niza sto ke cuva reden broj na produkt
    int numberOfSoldProducts;
    int productNumber;
    float productPrice;
    float totalSum;
    
    counter = 0;
    totalSum = 0;

    while(counter < 5)
    {
        printf("Vnesete go redniot broj na produktot i prodadenata kolicina: \n");
        scanf("%d %d", &productNumber, &numberOfSoldProducts);

        switch(productNumber)
        {
            case 1:
                  productPrice = 50.5;
                  break;
            case 2:
                  productPrice = 45.6;
                  break;
            case 3:
                  productPrice = 32.8;
                  break;
            case 4:
                  productPrice = 65.3;
                  break;
            case 5:
                  productPrice = 20.0;
                  break;
            default:
                  printf("Ne postoi produkt so reden broj %d \n", productNumber);
        }
        arrayForProductNumber[counter] = productNumber;
        arrayIncomePerProduct[counter] = productPrice * numberOfSoldProducts;
        totalSum += arrayIncomePerProduct[counter];
        ++counter;
    }

    counter = 0;

    while(counter < 5)
    {
        printf("Proizvodot so reden broj %d ima %.2f vkupna prodadena vrednost \n", arrayForProductNumber[counter], 
                                                                                  arrayIncomePerProduct[counter]);
        ++counter;
    }

    printf("Vkupnata suma od site prodadeni proizvodi iznesuva %.2f", totalSum);

    return 0;
}