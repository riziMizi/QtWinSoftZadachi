#include <stdio.h>

void vnesiMatrica(int rows, int cols, int matrix[rows][cols]);
void pechatiMatrica(int rows, int cols, int matrix[rows][cols]);

int main()
{
    int cols, rows;

    printf("Vnesete broj na redici: ");
    scanf("%d", &rows);
    printf("Vnesete broj na koloni: ");
    scanf("%d", &cols);

    int matrix[rows][cols];

    vnesiMatrica(rows, cols, matrix);
    pechatiMatrica(rows, cols, matrix);

    return 0;
}

void vnesiMatrica(int rows, int cols, int matrix[rows][cols])
{
    int i, j;

    for(i = 0; i < rows; ++i)
    {
        for(j = 0; j < cols; ++j)
        {
            printf("Vnesete elementi na matricata: ");
            scanf("%d", &matrix[i][j]);
        }
    }
}

void pechatiMatrica(int rows, int cols, int matrix[rows][cols])
{
    int i, j;

     for(i = 0; i < rows; ++i)
    {
        for(j = 0; j < cols; ++j)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
