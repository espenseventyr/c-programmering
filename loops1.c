// loops1.c
// Program for å lese inn alder på 10 studenter og så regne
// ut gjennomsnittsalderen.
#include<stdio.h>

int main()
{
    printf("Skriv inn alder på 10 studenter.\n");
    printf("Trykk enter mellom hver gang.\n");
    int alder[10];
    for(int i = 0; i<10; i++)
        scanf("%d", &alder[i]);
    printf("Alderen på studentene du skrev inn var:\n");
    for(int i = 0; i<10; i++)
        printf("%d: %d\n", i+1, alder[i]);
    int sum_alder = 0;
    for(int i = 0; i<10; i++)
        sum_alder += alder[i];
    double snittalder = sum_alder/10.0;
    printf("\nGjennomsnittsalderen er: %.2f\n", snittalder);


    char valg = 0;
    while(1) {
        printf("Ønsker du å korrigere alder på en student?\n");
        printf("Velg studentnummer eller skriv 'n' for å avslutte.\n");
        getchar(); // Be om forklaring på dette, skjønner ikke hvorfor det er nødvendig.
        scanf("%c", &valg);
        if(valg==78 || valg==110)
            break;
        if(valg>48 && valg<58) {
            printf("Skriv inn ny alder: ");
            scanf("%d", &alder[(int)valg-49]);
            printf("Alderen på studentene du skrev inn var:\n");
            for(int i = 0; i<10; i++) {
                if(i==(int)valg-49) {
                    printf("%d: %d (korrigert)\n", i+1, alder[i]);
                    continue;
                }
                printf("%d: %d\n", i+1, alder[i]);
            }
            sum_alder = 0;
            for(int i = 0; i<10; i++)
                sum_alder += alder[i];
            snittalder = sum_alder/10.0;
            printf("\nGjennomsnittsalderen er: %.2f\n", snittalder);
        }
    }

    return 0;
}
