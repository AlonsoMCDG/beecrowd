// bee 1414 - Copa do Mundo
// Alonso Martins
// 11/07/2024
#include <stdio.h>

int main()
{
    int T, N, pontos;
    char time[12];

    while (scanf("%d %d", &T, &N), T)
    {
        int total = 0, i;

        for (i = 0; i < T; i ++)
        {
            scanf(" %s %d", time, &pontos);
            total += pontos;
        }

        printf("%d\n", 3 * N - total); // cada empate == -1 ponto da pontuacao maxima (3 * N)
    }

    return 0;
}
