#include <stdio.h>

int countAverageTemperature(int size);

int main()
{
    int month;
    int numberOfDays;
    printf("Vnesete mesec kako cel broj: ");
    scanf("%d", &month);

    switch (month)
    {
    case 1:
        numberOfDays = 31;
        printf("Sredna mesecna temperatura za mesec januari iznesuva %d C", countAverageTemperature(numberOfDays));
        break;
    case 2:
        numberOfDays = 28;
        printf("Sredna mesecna temperatura za mesec fevruari iznesuva %d C", countAverageTemperature(numberOfDays));
        break;
    case 3:
        numberOfDays = 31;
        printf("Sredna mesecna temperatura za mesec mart iznesuva %d C", countAverageTemperature(numberOfDays));
        break;
    case 4:
        numberOfDays = 30;
        printf("Sredna mesecna temperatura za mesec april iznesuva %d C", countAverageTemperature(numberOfDays));
        break;
    case 5:
        numberOfDays = 31;
        printf("Sredna mesecna temperatura za mesec maj iznesuva %d C", countAverageTemperature(numberOfDays));
        break;
    case 6:
        numberOfDays = 30;
        printf("Sredna mesecna temperatura za mesec juni iznesuva %d C", countAverageTemperature(numberOfDays));
        break;
    case 7:
        numberOfDays = 31;
        printf("Sredna mesecna temperatura za mesec juli iznesuva %d C", countAverageTemperature(numberOfDays));
        break;
    case 8:
        numberOfDays = 31;
        printf("Sredna mesecna temperatura za mesec avgust iznesuva %d C", countAverageTemperature(numberOfDays));
        break;
    case 9:
        numberOfDays = 30;
        printf("Sredna mesecna temperatura za mesec septemvri iznesuva %d C", countAverageTemperature(numberOfDays));
        break;
    case 10:
        numberOfDays = 31;
        printf("Sredna mesecna temperatura za mesec oktomvri iznesuva %d C", countAverageTemperature(numberOfDays));
        break;
    case 11:
        numberOfDays = 30;
        printf("Sredna mesecna temperatura za mesec noemvri iznesuva %d C", countAverageTemperature(numberOfDays));
        break;
    case 12:
        numberOfDays = 31;
        printf("Sredna mesecna temperatura za mesec dekemvri iznesuva %d C", countAverageTemperature(numberOfDays));
        break;
    default:
        printf("Vnesovte pogresen mesesec");
        break;
    }

    return 0;
}

int countAverageTemperature(int size)
{
    int i;
    int temperatureValue;
    int temperatureSum = 0;

    for(i = 1; i <= size; ++i)
    {
        printf("Vnesete ja temperaturata za den %d: ", i);
        scanf("%d", &temperatureValue);
        temperatureSum += temperatureValue;
    }

    return temperatureSum / size;
}