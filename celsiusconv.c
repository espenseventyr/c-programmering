// celsiusconv.c
// Enkel kalkulator for å konvertere C til F eller K.
// Forsøke å få getchar() til å fungere.
#include <stdio.h>

int main()
{
    printf("Tast inn temperatur i grader Celsius: ");
    int celsius = 0;
    scanf("%d", &celsius);
    printf("Skal denne temperaturen konverteres til F eller K?\n");
    int valg = getchar();
    while (valg!='F' || valg!='f' || valg!='K' || valg!='k')
        printf("%d\t%c", valg, valg);

    if (valg=='F' || valg=='f') {
        int fahren = 32 + celsius*(9/5);
        printf("\n%d C tilsvarer %d F.\n", celsius, fahren);
    }
    if (valg=='K' || valg=='k') {
        int kelvin = 273+celsius;
        printf("\n%d C tilsvarer %d K.\n", celsius, kelvin);
    }
    return 0;
}
