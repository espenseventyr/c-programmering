// celsiusconv.c
// Enkel kalkulator for å konvertere C til F eller K.
#include <stdio.h>

const MAXLINE = 5;

int getline2(char line[], int maxline);
int string_to_int(char temp[]);

int main()
{
    char valg[MAXLINE] = { 0 };
    char temp[MAXLINE] = { 0 };
    int len_valg = getline2(valg, MAXLINE);
    int celsius = string_to_int(temp);

    printf("Tast inn temperatur i grader Celsius: ");
    getline2(temp, MAXLINE);
    printf("Skal denne temperaturen konverteres til F eller K?\n");
    while (valg[0]!='F' && valg[0]!='f' && valg[0]!='K' && valg[0]!='k')
        ;

    if (valg[0]=='F' || valg[0]=='f') {
        int fahren = 32 + celsius*(9/5);
        printf("\n%d C tilsvarer %d F.\n", celsius, fahren);
    }
    if (valg[0]=='K' || valg[0]=='k') {
        int kelvin = 273+celsius;
        printf("\n%d C tilsvarer %d K.\n", celsius, kelvin);
    }
    return 0;
}

// getline: les inn en linje i s
int getline2(char s[], int lim)
{
    int i, c;
    for (i = 0; i<lim-1 && (c=getchar())!='\n'; ++i)
        s[i] = c;
    s[i] = '\0';
    return i+1;
}

int string_to_int(char s[])
{
    int sign = 0, offset = 0;

    if (s[0]=='-') // behandle negative tall
        sign = -1;

    if (sign==-1) // startposisjon for konvertering
        offset = 1;
    else
        offset = 0;

    int n = 0;
    for (int c = offset; s[c]!='\0'; ++c)
        n = n*10 + s[c] - '0';
    if (sign==-1)
        n = -n;
    return n;
}
