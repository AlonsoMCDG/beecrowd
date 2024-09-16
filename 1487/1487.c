// bee 1487 - Six Flags
// Alonso Martins
// 15/09/2024
#include <stdio.h>

enum
{
    TEMPO_ESPERA = 0,
    PONTOS = 1
};

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int N, T, i, j, instancia = 1;
    int atracoes[100][2];

    while (scanf("%d %d", &N, &T), N)
    { // knapsack com repetição
        int dp[601] = {};

        for (i = 0; i < N; i ++)
            scanf("%d %d", &atracoes[i][TEMPO_ESPERA], &atracoes[i][PONTOS]);
        
        for (i = 1; i <= T; i ++)
        {
            for (j = 0; j < N; j ++)
            {
                if (atracoes[j][TEMPO_ESPERA] <= i)
                {
                    int novo_ponto = atracoes[j][PONTOS] + dp[i - atracoes[j][TEMPO_ESPERA]];
                    dp[i] = max(dp[i], novo_ponto);
                    dp[i] = max(dp[i], dp[i - 1]);
                }
            }
        }

        printf("Instancia %d\n%d\n\n", instancia ++, dp[T]);
    }

    return 0;
}
