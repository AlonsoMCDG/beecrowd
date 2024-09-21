// bee 1307 - Tudo o que Voce Precisa e Amor
// Alonso Martins
// 20/09/2024
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int lista_primos[4000];
int qtd_primos = 0;

void sieve()
{
    int i, j;
    bool nao_eh_primo[32800] = {1, 1};

    for (i = 0; i < 32800; i ++)
        if (!nao_eh_primo[i])
        {
            lista_primos[qtd_primos ++] = i;

            for (j = i * i; j <= 32768; j += i)
                nao_eh_primo[j] = true;
        }
}

int bintodec(char *s)
{ // binario para decimal
    int i, n = 0, sz = strlen(s);

    for (i = 0; i < sz; i ++)
        n = ((s[sz - i - 1] - '0') << i) | n;

    return n;
}

int main()
{
    int N, i, j, p, A, B;
    char s1[32], s2[32];

    sieve();

    for (scanf("%d", &N), i = 1; i <= N && scanf(" %s %s", s1, s2); i ++)
    {
        bool love = false;
        A = bintodec(s1);
        B = bintodec(s2);

        for (j = 0; j < qtd_primos && !love; j ++)
        {
            p = lista_primos[j];
            love = love || (A % p == 0 && B % p == 0);

            if (p > A || p > B)
            {
                love = love || (A % B == 0 || B % A == 0);
                break;
            }
        }

        printf("Pair #%d: %s\n", i, love ? "All you need is love!" : "Love is not all you need!");
    }

    return 0;
}
