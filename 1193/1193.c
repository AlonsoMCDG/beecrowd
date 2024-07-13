// bee 1193 - Conversao entre Bases
// Alonso Martins
// 12/07/2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

unsigned todec(char *n, char b)
{
    if (b == 'd')
        return atoi(n);

    int i;
    unsigned res = 0, r = 1;
    b = (b == 'b' ? 2 : 16);

    for (i = strlen(n) - 1; i >= 0; i --)
    {
        if (isalpha(n[i]))
            res += (n[i] - 'a' + 10) * r;
        else
            res += (n[i] - '0') * r;
        r *= b;
    }

    return res;
}

void print_bits(unsigned n)
{
    char bits[33];
    int i = 33;
    bits[33] = '\0';

    do
    {
        bits[-- i] = (n & 1) + '0';
        n >>= 1;
    } while (n > 0);

    printf("%s bin\n", &bits[i]);
}

int main()
{
    int T, t = 1;
    char n[50], b[20];

    scanf("%d%*c", &T);

    while (T -- && scanf("%s %s", n, b))
    {
        unsigned valor = todec(n, b[0]);

        printf("Case %d:\n", t ++);
        if (b[0] != 'd') printf("%u dec\n", valor);
        if (b[0] != 'h') printf("%x hex\n", valor);
        if (b[0] != 'b') print_bits(valor);
        printf("\n");
    }

    return 0;
}
