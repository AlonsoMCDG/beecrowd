// bee 1895 - Jogo do Limite
// Alonso Martins
// 16/06/2024
#include <stdio.h>
#include <math.h>

int main()
{
    int N, T, L, C, d;
    int pontos[2] = {}, vez = 0;

    scanf("%d %d %d", &N, &T, &L);

    while (-- N && scanf("%d", &C))
    {
        d = (int)fabs(T - C);

        if (d <= L)
            pontos[vez] += d, T = C;

        vez = (vez + 1) % 2;
    }

    printf("%d %d\n", pontos[0], pontos[1]);

    return 0;
}
