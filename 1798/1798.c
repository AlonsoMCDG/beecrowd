// bee 1798 - Cortando Canos
// Alonso Martins
// 28/10/2024
#include <stdio.h>

typedef struct Cano
{
    int tam;
    int val;
} Cano;

int max(int x, int y) { return x > y ? x : y; }

int main()
{
    int N, T, C, V, i, j, dp[2001] = {};
    Cano canos[1000];

    scanf("%d %d", &N, &T);

    for (i = 0; i < N; i ++)
        scanf("%d %d", &canos[i].tam, &canos[i].val);

    for (j = 1; j <= T; j ++)
        for (i = 0; i < N; i ++)
            if (canos[i].tam <= j)
                dp[j] = max(dp[j], dp[j - canos[i].tam] + canos[i].val);

    printf("%d\n", dp[T]);

    return 0;
}
