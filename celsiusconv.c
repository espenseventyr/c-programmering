// lab1-9.c
// Enkel kalkulator for å konvertere C til F eller K.
// Forsøke å få getchar() til å fungere.
#include <stdio.h>
#include <unistd.h>

int main()
{
    int celsius = 0;
    printf("Tast inn temperatur i grader Celsius: ");
    scanf("%d", &celsius);
    printf("Skal denne temperaturen konverteres til F eller K?\n");
//    int max = 100;
 //   char* valg = (char*)malloc(max);
    char c;
    while(c!=49 | c!=50) {
        printf("Trykk 1 for F eller 2 for K: ");
        if(c!=EOF)
            c = getchar();
            if(c==49 | c==50)
                break;
    }

    int kelvin = 0;
    int fahrenheit = 0;
    kelvin = 273+celsius;
    fahrenheit = 32 + celsius*(9/5);

    if (c=='1')
        printf("\n%d C tilsvarer %d F.\n", celsius, fahrenheit);
    if (c=='2')
        printf("\n%d C tilsvarer %d K.\n", celsius, kelvin);

    printf("Trykk Ctrl-C for å fortsette...\n");
    pause();
    return 0;
}
