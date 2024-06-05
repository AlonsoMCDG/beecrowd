// bee 1547 - Advinha
// Alonso Martins
// 05/06/2024
#include <stdio.h>

int abs(int x)
{
    return x < 0 ? -x : x;
}

int diferenca(int a, int b)
{
    return abs(a - b);
}

int main()
{
    int N, Q, S, i, ganhador, melhorChute, chute, dif;

    scanf("%d", &N);

    while (N -- && scanf("%d %d %d", &Q, &S, &melhorChute))
    {
        for (ganhador = 1, melhorChute = diferenca(melhorChute, S), i = 2; i <= Q && scanf("%d", &chute); i ++)
        {
            dif = diferenca(S, chute);
            if (dif < melhorChute)
                melhorChute = dif, ganhador = i;
        }

        printf("%d\n", ganhador);
    }

    return 0;
}
