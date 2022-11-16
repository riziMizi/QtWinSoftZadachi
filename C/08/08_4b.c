#include <stdio.h>

void vnesiMatrica(int rows, int cols, int matrix[rows][cols], int currentRow, int currentCo);
void pechatiMatrica(int rows, int cols, int matrix[rows][cols], int currentRow, int currentCol);

int main()
{
    int cols, rows;

    printf("Vnesete broj na redici: ");
    scanf("%d", &rows);
    printf("Vnesete broj na koloni: ");
    scanf("%d", &cols);

    int matrix[rows][cols];

    vnesiMatrica(rows, cols, matrix, 0, 0);
    pechatiMatrica(rows, cols, matrix, 0, 0);

    return 0;
}

void vnesiMatrica(int rows, int cols, int matrix[rows][cols], int currentRow, int currentCol)
{
    if(currentRow + 1 == rows && currentCol == cols) return;

    if(currentCol < cols)
    {
        printf("Vnesete elementi na matricata: ");
        scanf("%d", &matrix[currentRow][currentCol]);
        vnesiMatrica(rows, cols, matrix, currentRow, ++currentCol);
    }
    else
    {
        vnesiMatrica(rows, cols, matrix, ++currentRow, 0);
    }
}

void pechatiMatrica(int rows, int cols, int matrix[rows][cols], int currentRow, int currentCol)
{
   if(currentRow + 1 == rows && currentCol == cols) return;

    if(currentCol < cols)
    {
        printf("%d ", matrix[currentRow][currentCol]);
        pechatiMatrica(rows, cols, matrix, currentRow, ++currentCol);
    }
    else
    {
        printf("\n");
        pechatiMatrica(rows, cols, matrix, ++currentRow, 0);
    }
}

