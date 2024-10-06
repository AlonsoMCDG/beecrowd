// bee 2151 - Soco do Rulk
// Alonso Martins
// 06/10/2024
#include <stdio.h>

int abs(int x)
{
    return x < 0 ? -x : x;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int T, t = 1, N, M, i, j, L, C, bloco, dist, dx, dy;

    scanf("%d", &T);

    while (T -- && scanf("%d %d %d %d", &N, &M, &L, &C))
    {
        printf("Parede %d:\n", t ++);

        for (i = 1; i <= N; i ++)
            for (j = 1; j <= M; j ++)
            {
                scanf("%d", &bloco);

                dx = abs(j - C);
                dy = abs(i - L);
                dist = max(dx, dy);
                bloco = bloco + max(1, 10 - dist);

                printf("%d%s", bloco, j == M ? "\n" : " ");
            }
    }
    
    return 0;
}
