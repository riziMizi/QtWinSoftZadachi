#include <stdio.h>

int main()
{
    int n, m;
    int i,j,k;
    int pointer = -1; // -1 - dvizi se nadole po redicite
                      // 0 - ostani vo mesto
                      // 1 - dvizi se nagore po redicite

    i = 0; // redici
    j = 0; // koloni

    printf("Vnesete kolku redici ima matricata: ");
    scanf("%d", &n);
    printf("Vnesete kolku koloni ima matricata: ");
    scanf("%d", &m);

    int matrix[n][m];

    for(k = 0; k < n * m; ++k)
    {
        printf("Vnesete element vo matricata: ");
        scanf("%d", &matrix[i][j]);

        if(pointer == -1)
        {
            ++i;
            if(i == n - 1) pointer = 0;
        }
        else if(pointer == 0)
        {
            ++j;
            if(i == n - 1) pointer = 1;
            else pointer = -1;
        }
        else
        {
            --i;
            if(i == 0) pointer = 0;
        }

    }

    for(i = 0; i < n; ++i)
    {
        for(j = 0; j < m; ++j)
        {
           printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
