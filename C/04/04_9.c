#include <stdio.h>

int main()
{
    float monthlySales;
    float salary;

    monthlySales = 0;

    while(monthlySales != -1)
    {
        printf("Vnesi prometvo evra (-1 za kraj): ");
        scanf("%f", &monthlySales);

        if(monthlySales == -1) break;

        salary = 200 + (monthlySales * 0.09);
        printf("Platata e: %.2f evra \n", salary);
    }

    return 0;
}