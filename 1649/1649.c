// bee 1649 - Ferramenta Irritante de Pintura
// Alonso Martins
// 12/09/2024
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int main()
{
    int N, M, R, C, i, j, ii, jj;
    int alvo[MAX][MAX];
    char aux[102];

    while (scanf("%d %d %d %d%*c", &N, &M, &R, &C), N && M && R && C)
    {
        int mat[MAX][MAX] = {};
        int ans = 0;

        for (i = 0; i < N; i ++, getchar())
        {
            scanf(" %s", aux);

            for (j = 0; j < M; j ++)
                alvo[i][j] = aux[j] - '0';            
        }

        for (i = 0; i < N && ans != -1; i ++)
        {
            for (j = 0; j < M && ans != -1; j ++)
            {
                if (mat[i][j] != alvo[i][j])
                {
                    if (i + R <= N && j + C <= M)
                    {
                        for (ii = 0; ii < R; ii ++)
                            for (jj = 0; jj < C; jj ++)
                                mat[i + ii][j + jj] = !mat[i + ii][j + jj];

                        ans ++;
                    }
                    else
                    {
                        ans = -1;
                    }
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
