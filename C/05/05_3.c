#include <stdio.h>

int main()
{
    int i, j, k;

    for(i = 2; i < 100; ++i)
    {
        for(j = i + 1; j < 100; ++j)
        {
            for(k = j + 1; k < 100; ++k)
            {
                if((i * i) + (j * j) == k * k)
                {
                    printf("%d %d %d \n", i, j, k);
                }
            }
        }

    }

    return 0;
}