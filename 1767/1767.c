// bee 1767 - Saco do Papai Noel
// Alonso Martins
// 29/09/2024
#include <stdio.h>
#include <stdlib.h>

typedef struct Pacote
{
    int peso;
    int toys;
} Pacote;

int main()
{
    int T, N, i, j;

    scanf("%d", &T);

    while (T -- && scanf("%d", &N))
    {
        Pacote pacotes[101] = {};
        Pacote dp[101][51] = {};
        int pacotes_coletados[101][51] = {};

        for (i = 1; i <= N; i ++)
            scanf("%d %d", &pacotes[i].toys, &pacotes[i].peso);

        for (j = 1; j <= 50; j ++)
        {
            for (i = 1; i <= N; i ++)
            {
                int peso = pacotes[i].peso; 
                if (peso <= j)
                {
                    int new_toys = pacotes[i].toys + dp[i - 1][j - peso].toys;
                    int new_peso = pacotes[i].peso + dp[i - 1][j - peso].peso;
                    if (new_toys > dp[i - 1][j].toys)
                    {
                        dp[i][j].toys = new_toys;
                        dp[i][j].peso = new_peso;
                        pacotes_coletados[i][j] = pacotes_coletados[i - 1][j - peso] + 1;
                    }
                    else 
                    {
                        dp[i][j] = dp[i - 1][j];
                        pacotes_coletados[i][j] = pacotes_coletados[i - 1][j];
                    }
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                    pacotes_coletados[i][j] = pacotes_coletados[i - 1][j];
                }
            }
        }

        printf("%d brinquedos\n", dp[N][50].toys);
        printf("Peso: %d kg\n", dp[N][50].peso);
        printf("sobra(m) %d pacote(s)\n\n", N - pacotes_coletados[N][50]);
    }

    return 0;
}
