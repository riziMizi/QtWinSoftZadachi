
#include <stdio.h>

int main()
{
    int i;
    float celsius;

    for(i = 0; i <= 212; ++i)
    {
         celsius = 5.0 / 9.0 * (i - 32);

         printf("%10d%+10.3f \n", i, celsius);
    }

    return 0;
}