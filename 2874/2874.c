// bee 2874 - Frase Binaria
// Alonso Martins
// 26/09/2024
#include <stdio.h>
#include <string.h>

char getascii(char *b)
{
    int sz = strlen(b), i, dec = 0;

    for (i = 0; i < sz; i ++)
        dec = ((1 & (b[sz - 1 - i] - '0')) << i) | dec;

    return dec;
}

int main()
{
    int N, i;
    char byte[10], frase[100002];

    while (scanf("%d", &N) != EOF)
    {
        for (i = 0; i < N; i ++)
        {
            scanf(" %s", byte);
            frase[i] = getascii(byte);
        }
        frase[N] = '\0';

        printf("%s\n", frase);
    }

    return 0;
}
