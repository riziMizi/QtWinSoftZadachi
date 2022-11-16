#include <stdio.h>

int vreme(int hour, int minutes, int seconds);

int main()
{
    int hour, minutes, seconds;
    int remainingSeconds;

    printf("Vnesete saat \n");
    scanf("%d", &hour);

    printf("Vnesete minuti \n");
    scanf("%d", &minutes);

    printf("Vnesete sekundi \n");
    scanf("%d", &seconds);

    remainingSeconds = vreme(hour, minutes, seconds);

    printf("Do 12 casot preostanuvaat uste %d sekundi. \n", remainingSeconds);

    return 0;
}

int vreme(int hour, int minutes, int seconds)
{
    if(hour < 12)
    {
        return ((12 - hour - 1) * 3600) + ((60 - minutes - 1) * 60) + (60 - seconds); 
    }
    else
    {
       return ((24 - hour - 1) * 3600) + ((60 - minutes - 1) * 60) + (60 - seconds) + (3600 * 12);
    }
}