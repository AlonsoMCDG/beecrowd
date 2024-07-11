// bee 2394 - Corrida 1
// Alonso Martins
// 11/07/2024
#include <stdio.h>
#include <limits.h>

int main()
{
    int N, M, i, j, tempoMax = INT_MAX, vencedor, tempo;

    scanf("%d %d", &N, &M);

    for (i = 1; i <= N; i ++)
    {
        int total = 0;

        for (j = 0; j < M; j ++)
        {
            scanf("%d", &tempo);
            total += tempo;
        }

        if (total < tempoMax)
        {
            tempoMax = total;
            vencedor = i;
        }
    }

    printf("%d\n", vencedor);

    return 0;
}
