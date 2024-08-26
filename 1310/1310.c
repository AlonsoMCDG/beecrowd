// bee 1310 - Lucro
// Alonso Martins
// 26/08/2024
#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int dias, custoPorDia, i, j, lucro[51];

    while (scanf("%d %d", &dias, &custoPorDia) != EOF)
    {
        int dp[51][51] = {}, lucroMaximo = 0;

        for (i = 1; i <= dias; i ++)
            scanf("%d", &lucro[i]);
        
        for (i = 1; i <= dias; i ++)
        {
            for (j = i; j <= dias; j ++)
            {
                dp[i][j] = dp[i - 1][j - 1] + lucro[j] - custoPorDia;
                lucroMaximo = max(lucroMaximo, dp[i][j]);
            }
        }

        printf("%d\n", lucroMaximo);
    }

    return 0;
}
