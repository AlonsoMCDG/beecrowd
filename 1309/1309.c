// bee 1309 - Formatacao Monetaria
// Alonso Martins
// 12/09/2024
#include <stdio.h>
#include <string.h>

int main()
{
    char N[20], C[4];
    int i, k, sz;

    while (scanf("%s %s", N, C) != EOF)
    {
        char saida[20] = {};
        sz = strlen(N);
        i = k = 0;

        while (i < sz - 1 && N[i] == '0')
            i ++;

        for (; i < sz; i ++)
        {
            saida[k ++] = N[i];
            if ((sz - i) % 3 == 1)
                saida[k ++] = ',';
        }

        saida[k - 1] = '.';
        saida[k ++] = '0';

        for (i = strlen(C) - 1; i + 1; i --)
            saida[k --] = C[i];

        printf("$%s\n", saida);
    }

    return 0;
}
