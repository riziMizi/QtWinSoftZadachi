#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    float a;
    float A, L;

    printf("Vnesete kolku strani ima mnoguagolnikot: ");
    scanf("%d", &n);

    printf("Vnesete ja dolzinata na stranata: ");
    scanf("%f", &a);

    A = ((n * a * a) / (4 * tan(3.14 / n)));
    L = n * a;

    printf("Plostinata na mnoguagolnikot iznesuva %.2f \n", A);
    printf("Perimetarot na mnoguagolnikot iznesuva %.2f", L);

    return 0;
}
