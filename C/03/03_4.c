#include <stdio.h>

float result; 
int main()
{
    //Na ekran se pecati nekoj golem broj poradi toa sto so %d kompajlerot ocekuva da se dodeli
    //int vrednost, a nie mu dodeluvame float.
result = 7.0 / 22.0;
printf("Rezultatot e %d\n", result);
return (0);
}
