#include<stdio.h>
#include<string.h>

void convertMorseCodeToText(char *morseCode);

int main()
{
        char text[100];
        char texrMorseCode[500];
        int i;
        int counter = 0;
        char morseText[500];

        printf("Vnesete tekst od brojki i bukvi: ");
        gets(text);

        for(i=0; i<strlen(text); ++i)
        {
            switch(toupper(text[i]))
            {
                case 'A':
                    texrMorseCode[counter++]='.';
                    texrMorseCode[counter++]='-';
                    break;
                case 'B':
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      break;
                case 'C':
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='.';
                      break;
                case 'D':
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      break;
                case 'E':
                      texrMorseCode[counter++]='.';
                      break;
                case 'F':
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='.';
                      break;
                case 'G':
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='.';
                      break;
                case 'H':
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      break;
                case 'I':
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      break;
                case 'J':
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='-';
                      break;
               case 'K':
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='-';
                      break;
               case 'L':
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      break;
               case 'M':
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='-';
                      break;
               case 'N':
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='.';
                      break;
              case 'O':
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='-';
                      break;

              case 'P':
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='.';
                      break;
              case 'Q':
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='-';
                      break;
              case 'R':
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='.';
                      break;
              case 'S':
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      break;
              case 'T':
                      texrMorseCode[counter++]='-';
                      break;
              case 'U':
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='-';
                    break;
              case 'V':
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='-';
                      break;
              case 'W':
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='-';
                      break;
              case 'X':
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='-';
                      break;
              case 'y':
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='-';
                      break;
              case 'Z':
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      break;
              case '0':
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='-';
                      break;
              case '1':
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='-';
                      break;
              case '2':
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='-';
                      break;
              case '3':
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='-';
                      break;
              case '4':
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='-';
                      break;
              case '5':
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      break;
              case '6':
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      break;
              case '7':
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      break;
              case '8':
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='.';
                      texrMorseCode[counter++]='.';
                      break;
              case '9':
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='-';
                      texrMorseCode[counter++]='.';
                      break;
              case ' ':
                      texrMorseCode[counter++] = ' ';
                      break;
              default:
                    printf("nevaliden znak %c", text[i]);
            }
            texrMorseCode[counter++] = ' ';
        }
        texrMorseCode[counter] = '\0';
        printf("%s\n", texrMorseCode);

        printf("Vnesete nekoj Morzeov tekst: ");
        gets(morseText);
        convertMorseCodeToText(morseText);

        return 0;
}

void convertMorseCodeToText(char *morseCode)
{
    char text[100];
    int counter = 0;
    char *tempValue;

    tempValue = strtok(morseCode, " ");

    while(tempValue != NULL)
    {
        if(strcmp(tempValue, ".-") == 0) text[counter++] = 'A';
        else if(strcmp(tempValue, "-...") == 0) text[counter++] = 'B';
        else if(strcmp(tempValue, "-...") == 0) text[counter++] = 'B';
        else if(strcmp(tempValue, "-.-.") == 0) text[counter++] = 'C';
        else if(strcmp(tempValue, "-..") == 0) text[counter++] = 'D';
        else if(strcmp(tempValue, ".") == 0) text[counter++] = 'E';
        else if(strcmp(tempValue, "..-.") == 0) text[counter++] = 'F';
        else if(strcmp(tempValue, "--.") == 0) text[counter++] = 'G';
        else if(strcmp(tempValue, "....") == 0) text[counter++] = 'H';
        else if(strcmp(tempValue, "..") == 0) text[counter++] = 'I';
        else if(strcmp(tempValue, ".---") == 0) text[counter++] = 'J';
        else if(strcmp(tempValue, "-.-") == 0) text[counter++] = 'K';
        else if(strcmp(tempValue, ".-..") == 0) text[counter++] = 'L';
        else if(strcmp(tempValue, "--") == 0) text[counter++] = 'M';
        else if(strcmp(tempValue, "-.") == 0) text[counter++] = 'N';
        else if(strcmp(tempValue, "---") == 0) text[counter++] = 'O';
        else if(strcmp(tempValue, ".--.") == 0) text[counter++] = 'P';
        else if(strcmp(tempValue, ".-.") == 0) text[counter++] = 'R';
        else if(strcmp(tempValue, "...") == 0) text[counter++] = 'S';
        else if(strcmp(tempValue, "-") == 0) text[counter++] = 'T';
        else if(strcmp(tempValue, "..-") == 0) text[counter++] = 'U';
        else if(strcmp(tempValue, "...-") == 0) text[counter++] = 'V';
        else if(strcmp(tempValue, ".--") == 0) text[counter++] = 'W';
        else if(strcmp(tempValue, "-..-") == 0) text[counter++] = 'X';
        else if(strcmp(tempValue, "-.--") == 0) text[counter++] = 'Y';
        else if(strcmp(tempValue, "--..") == 0) text[counter++] = 'Z';
        else if(strcmp(tempValue, "----") == 0) text[counter++] = '0';
        else if(strcmp(tempValue, ".---") == 0) text[counter++] = '1';
        else if(strcmp(tempValue, "..--") == 0) text[counter++] = '2';
        else if(strcmp(tempValue, "...--") == 0) text[counter++] = '3';
        else if(strcmp(tempValue, "....-") == 0) text[counter++] = '4';
        else if(strcmp(tempValue, ".....") == 0) text[counter++] = '5';
        else if(strcmp(tempValue, "-....") == 0) text[counter++] = '6';
        else if(strcmp(tempValue, "--...") == 0) text[counter++] = '7';
        else if(strcmp(tempValue, "---..") == 0) text[counter++] = '8';
        else if(strcmp(tempValue, "----.") == 0) text[counter++] = '9';
        else if(strcmp(tempValue, "/") == 0) text[counter++] = ' ';

        tempValue = strtok(NULL, " ");
    }
    text[counter] = '\0';
    printf("%s", text);
}


