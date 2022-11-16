#include <stdio.h>
#include <string.h>

void converDate(char *date);

int main()
{
    char date[10];

    while(1)
    {
        printf("Vnesete datum vo oblik dd/mm/yyyy. Za kraj vnesete 'q'\n");
        gets(date);
        if(strcmp(date, "q") == 0) break;
        converDate(date);
    }

    return 0;
}

void converDate(char *date)
{
    char *day;
    char *month;
    char *year;

    day = strtok(date, "/");
    month = strtok(NULL, "/");
    year = strtok(NULL, "/");

    if(strcmp(month, "01") == 0) printf("%s januari %s\n", day, year);
    else if(strcmp(month, "02") == 0) printf("%s fevruari %s\n", day, year);
    else if(strcmp(month, "03") == 0) printf("%s mart %s\n", day, year);
    else if(strcmp(month, "04") == 0) printf("%s april %s\n", day, year);
    else if(strcmp(month, "05") == 0) printf("%s maj %s\n", day, year);
    else if(strcmp(month, "06") == 0) printf("%s juni %s\n", day, year);
    else if(strcmp(month, "07") == 0) printf("%s juli %s\n", day, year);
    else if(strcmp(month, "08") == 0) printf("%s avgust %s\n", day, year);
    else if(strcmp(month, "09") == 0) printf("%s septemvri %s\n", day, year);
    else if(strcmp(month, "10") == 0) printf("%s oktomvri %s\n", day, year);
    else if(strcmp(month, "11") == 0) printf("%s noemvri %s\n", day, year);
    else if(strcmp(month, "12") == 0) printf("%s dekemvri %s\n", day, year);
}
