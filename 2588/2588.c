// bee 2588 - Jogo dos Palindromos
// Alonso Martins
// 17/06/2024
#include <stdio.h>
#include <string.h>

#define toi(x) (x - 'a')

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    char p[1002];
    int i, sz, k, l;

    while (scanf(" %s", p) != EOF)
    {
        sz = strlen(p);
        int qtd[26] = {}; // quantidade de cada letra
        int pr[2] = {sz, 0}; // quantidade de valores pares e impares em qtd

        for (i = 0; i < sz; i ++)
        {
            int t = toi(p[i]);
            k = ++ qtd[t];
            pr[k % 2] ++;
            pr[(k + 1) % 2] --;
        }

        printf("%d\n", max(pr[1], 1) - 1);
    }

    return 0;
}
