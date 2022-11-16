#include <stdio.h>

void addPolynomial(int arrPolynomial1[], int n, int arrPolynomial2[], int m, int min, int max);

int main()
{
    int n, m;
    int i;
    int min, max;

    printf("Vnesete go stepenot na prviot polinom: ");
    scanf("%d", &n);
    printf("Vnesete go stepenot na vtoriot polinom: ");
    scanf("%d", &m);

    if(n < m)
    {
        min = n;
        max = m;
    }
    else
    {
        min = m;
        max = n;
    }

    int arrPolynomial1[n + 1];
    int arrPolynomial2[m + 1];

    printf("Vnesete vrednosti za polinomot na stepen %d. \n", n);
    for(i = 0; i <= n; ++i)
    {
        if(i == 0)
        {
            printf("Vnesete ja konstantata: ");
            scanf("%d", &arrPolynomial1[i]);
        }
        else
        {
            printf("Vnesete ja vrednosta za x^%d: ", i);
            scanf("%d", &arrPolynomial1[i]);
        }
    }

    printf("Vnesete vrednosti za polinomot na stepen %d. \n", m);
    for(i = 0; i <= m; ++i)
    {
        if(i == 0)
        {
            printf("Vnesete ja konstantata: ");
            scanf("%d", &arrPolynomial2[i]);
        }
        else
        {
            printf("Vnesete ja vrednosta za x^%d: ", i);
            scanf("%d", &arrPolynomial2[i]);
        }
    }

    addPolynomial(arrPolynomial1, n, arrPolynomial2, m, min, max);

    return 0;
}

void addPolynomial(int arrPolynomial1[], int n, int arrPolynomial2[], int m, int min, int max)
{
    int counter = 0;
    int arrSumPolynominal[max + 1];
    int i;

    while(counter <= min)
    {
        arrSumPolynominal[counter] = arrPolynomial1[counter] + arrPolynomial2[counter];
        ++counter;
    }

    if(counter <= n)
    {
        while(counter <= n)
        {
            arrSumPolynominal[counter] = arrPolynomial1[counter];
            ++counter;
        }
    }

    if(counter <= m)
    {
        while(counter <= m)
        {
            arrSumPolynominal[counter] = arrPolynomial2[counter];
            ++counter;
        }
    }

    printf("(");
    for(i = n; i >= 0; --i)
    {
        if(arrPolynomial1[i] == 0) continue;
        if(i == 0)  printf("%+d", arrPolynomial1[i]);
        else printf("%+dx^%d", arrPolynomial1[i], i);
    }
    printf(") + ");

    printf("(");
    for(i = m; i >= 0; --i)
    {
        if(arrPolynomial2[i] == 0) continue;
        if(i == 0)  printf("%+d", arrPolynomial2[i]);
        else printf("%+dx^%d", arrPolynomial2[i], i);
    }
    printf(") = ");

    for(i = max; i >= 0; --i)
    {
        if(arrSumPolynominal[i] == 0) continue;
        if(i == 0)  printf("%+d", arrSumPolynominal[i]);
        else printf("%+dx^%d", arrSumPolynominal[i], i);
    }
}
