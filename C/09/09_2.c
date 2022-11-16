#include <stdio.h>

//Resenie so Kramerovo pravilo
float determinantaNaMatrica(int matrix[3][3]);
void reshiRavenka(int matrix[3][4]);

int main()
{
    int a1, a2, a3;
    int b1, b2, b3;
    int c1, c2, c3;
    int d1, d2, d3;

    printf("Vnesete gi vrednostite za a, b, c i d na prvata ravenka: ");
    scanf("%d%d%d%d", &a1, &b1, &c1, &d1);

    printf("Vnesete gi vrednostite za a, b, c i d na vtorata ravenka: ");
    scanf("%d%d%d%d", &a2, &b2, &c2, &d2);

    printf("Vnesete gi vrednostite za a, b, c i d na tretata ravenka: ");
    scanf("%d%d%d%d", &a3, &b3, &c3, &d3);

    int matrix[3][4] = {{a1, b1, c1, d1}, {a2, b2, c2, d2}, {a3, b3, c3, d3}};

    reshiRavenka(matrix);

    return 0;
}

float determinantaNaMatrica(int matrix[3][3])
{
    float determinant;

    determinant = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2])
          - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
          + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);

    return determinant;
}

void reshiRavenka(int matrix[3][4])
{
    int d[3][3] = {
        { matrix[0][0], matrix[0][1], matrix[0][2] },
        { matrix[1][0], matrix[1][1], matrix[1][2] },
        { matrix[2][0], matrix[2][1], matrix[2][2] },
    };

    int d1[3][3] = {
        { matrix[0][3], matrix[0][1], matrix[0][2] },
        { matrix[1][3], matrix[1][1], matrix[1][2] },
        { matrix[2][3], matrix[2][1], matrix[2][2] },
    };

    int d2[3][3] = {
        { matrix[0][0], matrix[0][3], matrix[0][2] },
        { matrix[1][0], matrix[1][3], matrix[1][2] },
        { matrix[2][0], matrix[2][3], matrix[2][2] },
    };

    int d3[3][3] = {
        { matrix[0][0], matrix[0][1], matrix[0][3] },
        { matrix[1][0], matrix[1][1], matrix[1][3] },
        { matrix[2][0], matrix[2][1], matrix[2][3] },
    };


    int D = determinantaNaMatrica(d);
    int D1 = determinantaNaMatrica(d1);
    int D2 = determinantaNaMatrica(d2);
    int D3 = determinantaNaMatrica(d3);


    if (D != 0)
    {
        float x = D1 / D;
        float y = D2 / D;
        float z = D3 / D;
        printf("Vrednosta na x iznesuva: %.2f \n", x);
        printf("Vrednosta na y iznesuva: %.2f \n", y);
        printf("Vrednosta na z iznesuva: %.2f \n", z);
    }
    else
    {
        if (D1 == 0 && D2 == 0 && D3 == 0)
            printf("Sistemot ima beskonevno mnogu reshenija. \n");
        else if (D1 != 0 || D2 != 0 || D3 != 0)
            printf("Sistemot nema reshenie. \n");
    }
}
