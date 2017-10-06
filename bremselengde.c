// bremselengde.c
// Regner ut bremselengde langs en vei. Føre + hastighet => bremselengde.
#include <stdio.h>
#define GRAVITASJON 9.81 // gravitasjonskonstanten

float fore(void);
void clearscr(void);
int hastighet_kmt(void);
float kmt2mps(int kmt);
float bremselengde(float mps, float fore);
float power(float base, int exp);

int main()
{
    float friksjon = fore();
    int kmt = hastighet_kmt();
    float mps = kmt2mps(kmt);
    printf("Koeffisienten til friksjonen mot underlaget er %3.2f.\n", friksjon);
    printf("Hastigheten er %d kmt eller %.1f m/s.\n", kmt, mps);
    printf("Bremselengden blir %3.2f m.\n", bremselengde(mps,friksjon));
    return 0;
}

float fore(void)
{
    int valg = '0';
    float friksjon = 0.0;
    while (valg<'1' || valg>'5') {
        printf("Hvilket føre kjører du på?\n");
        printf("1. Tørr asfalt\n");
        printf("2. Våt asfalt eller grus\n");
        printf("3. Snø\n");
        printf("4. Vinterdekk med pigg\n");
        printf("5. Vinterdekk uten pigg\n");
        printf("Velg et tall: \n");
        scanf("%c", &valg);
        switch(valg) {
        case '1': friksjon = 0.95;
            break;
        case '2': friksjon = 0.6;
            break;
        case '3': friksjon = 0.3;
            break;
        case '4': friksjon = 0.25;
            break;
        case '5': friksjon = 0.15;
            break;
        default : clearscr();
        }
    }
    return friksjon;
}

void clearscr(void)
{
    for (int i = 0; i<50; ++i)
        printf("\n");
}

int hastighet_kmt(void)
{
    int kmt = 0;
    printf("Hvor raskt kjører du (i kmt)? ");
    scanf("%d", &kmt);
    return kmt;
}

float kmt2mps(int kmt)
{
    float mps = kmt/3.6;
    return mps;
}

float power(float base, int exp)
{
    int sum;
    for (sum = 0; exp>0; --exp)
        sum += base;
    return sum;
}

float bremselengde(float mps, float fore)
{
    float bremselengde = power(mps,2)/(2*fore*GRAVITASJON);
    return bremselengde;
}
