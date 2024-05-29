// Maratona SBC 2024 - fase 0
// questão J - Jogos de Xadrez e a Mula Sem Cabeça
// Alonso Martins
// 25/05/2024
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int linha, coluna, ataques, livre;
} Casa;

int main()
{
    int N, M, K, L;
    int i, j, p;
    int lin, col;
    char c;
    scanf("%d %d %d %d", &N, &M, &K, &L);
    K --, L --;
    char tabuleiro[N][M + 2];
    int casas[N][M];

    for (i = 0; i < N; i ++)
    {
        for (getchar(), j = 0; j < M; j ++)
        {
            scanf("%c", &c);
            tabuleiro[i][j] = c;
            casas[i][j] = 0 - (c == '*');
        }
    }


    for (i = 0; i < N; i ++)
    {
        for (j = 0; j < M; j ++)
        {
            c = tabuleiro[i][j];
            if (c == '*')
            {
                casas[i][j] = -1;

                if (lin = i - K, col = j - L, p = lin * N + col, lin >= 0 && col >= 0 && casas[lin][col] + 1)
                    casas[lin][col] ++;
                if (lin = i - K, col = j + L, p = lin * N + col, lin >= 0 && col < M && casas[lin][col] + 1)
                    casas[lin][col] ++;
                if (lin = i - L, col = j - K, p = lin * N + col, lin >= 0 && col >= 0 && casas[lin][col] + 1)
                    casas[lin][col] ++;
                if (lin = i - L, col = j + K, p = lin * N + col, lin >= 0 && col < M && casas[lin][col] + 1)
                    casas[lin][col] ++;
                if (lin = i + L, col = j - K, p = lin * N + col, lin < N && col >= 0 && casas[lin][col] + 1)
                    casas[lin][col] ++;
                if (lin = i + L, col = j + K, p = lin * N + col, lin < N && col < M && casas[lin][col] + 1)
                    casas[lin][col] ++;
                if (lin = i + K, col = j - L, p = lin * N + col, lin < N && col >= 0 && casas[lin][col] + 1)
                    casas[lin][col] ++;
                if (lin = i + K, col = j + L, p = lin * N + col, lin < N && col < M && casas[lin][col] + 1)
                    casas[lin][col] ++;
            }
        }
    }

    int linha, coluna, max = 0, flag = 0;

    for (i = 0; i < N; i ++)
        for (j = 0; j < M; j ++)
            if (casas[i][j] + 1 && casas[i][j] >= max)
                if (casas[i][j] == max && !flag || casas[i][j] > max)
                    linha = i + 1, coluna = j + 1, max = casas[i][j], flag++;

    printf("%d %d\n", linha, coluna);

    return 0;
}
