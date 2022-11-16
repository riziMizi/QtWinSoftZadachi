#include <stdio.h>

int main()
{
    float radius;

    printf("Vnesete radius na krugot. \n");
    scanf("%f", &radius);

    printf("Plostinata na krugot e %f \n", 2 * radius * 3.14);
    printf("Perimetarot na krugot e %f \n", radius * radius * 3.14);

    return 0;
}