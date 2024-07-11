// bee 1940 - Jogo da Estrategia
// Alonso Martins
// 11/07/2024
#include <stdio.h>

int main()
{
    int N, R, pontosMax = 0, vencedor, i, j;
    int placar[500] = {}, pontos;

    scanf("%d %d", &N, &R);

    for (j = 0; j < R; j ++)
        for (i = 0; i < N; i ++)
        {
            scanf("%d", &pontos);
            placar[i] += pontos;
            if (placar[i] > pontosMax)
                pontosMax = placar[i];
        }

    for (vencedor = N - 1; vencedor >= 0; vencedor --)
        if (placar[vencedor] == pontosMax)
            break;

    printf("%d\n", vencedor + 1);

    return 0;
}
