// bee 1516 - Imagem
// Alonso Martins
// 24/06/2024
#include <stdio.h>

int main()
{
    int N, M, A, B, i, j, k, l;
    char desenho[100][102];

    while (scanf("%d %d", &N, &M), N && M)
    {
        for (i = 0; i < N; i ++)
            scanf(" %s", desenho[i]);

        scanf("%d %d", &A, &B);
        A /= N, B /= M;

        for (i = 0; i < N; i ++)
        {
            char linha[102];
            for (j = 0; j < M; j ++)
                for (k = 0; k < B; k ++)
                    linha[j * B + k] = desenho[i][j];

            linha[N * B] = '\0';

            for (l = 0; l < A; l ++)
                printf("%s\n", linha);
        }
        printf("\n");
    }

    return 0;
}
