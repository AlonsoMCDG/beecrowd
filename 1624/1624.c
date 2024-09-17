// bee 1624 - Promocao
// Alonso Martins
// 17/09/2024
#include <stdio.h>
#include <stdlib.h>

typedef struct Produto
{
    int peso;
    int preco;
} Produto;

int comp(const void *a, const void *b)
{
    return ((Produto *)a)->peso - ((Produto *)b)->peso;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int N, P, i, j;
    Produto produtos[1001] = {};

    while (scanf("%d", &N), N)
    {
        int dp[1001][31] = {};

        for (i = 1; i <= N; i ++)
            scanf("%d %d", &produtos[i].preco, &produtos[i].peso);

        scanf("%d", &P);

        qsort(produtos, N + 1, sizeof(produtos[0]), comp);

        for (j = 1; j <= P; j ++)
            for (i = 1; i <= N; i ++)
                if (produtos[i].peso <= j)
                    dp[i][j] = max(dp[i - 1][j], produtos[i].preco + dp[i - 1][j - produtos[i].peso]);
                else
                    dp[i][j] = dp[i - 1][j];

        printf("%d\n", dp[N][P]);
    }

    return 0;
}
