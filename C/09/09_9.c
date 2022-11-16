#include <stdio.h>


int main()
{
    float n;
    int i;
    float percentageOfDyingBacteria;
    int minutesI, minutesJ, minutesK;
    int counterMinutesI, counterMinutesJ;

    counterMinutesI = 0;
    counterMinutesJ = 0;

    printf("Vnesete kolku bakterii: ");
    scanf("%f", &n);
    printf("Vnesete na kolku minuti se razdeluvaat bakteriite: ");
    scanf("%d", &minutesI);
    printf("Vnesete na kolku minuti i kolku procenti od bateriite izumiraat: ");
    scanf("%d%f", &minutesJ, &percentageOfDyingBacteria);
    printf("Vnesete za kolku minuti da zavrshi procesot: ");
    scanf("%d", &minutesK);

    percentageOfDyingBacteria /= 100;

    for(i = 0; i < minutesK; ++i)
    {
        counterMinutesI++;
        counterMinutesJ++;

        if(counterMinutesI == minutesI)
        {
            n *= 2;
            counterMinutesI = 0;
        }
        if(counterMinutesJ == minutesJ)
        {
            n = n - (n * percentageOfDyingBacteria);
            counterMinutesJ = 0;
        }
    }

    printf("Po %d minuti ke ima %.2f bakterii. ", minutesK, n);

    return 0;
}
