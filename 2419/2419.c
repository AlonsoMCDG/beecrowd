// bee 2419 - Costa
// Alonso Martins
// 19/07/2024
#include <stdio.h>

#define MAX_SIZE 1000

int main()
{
    int N, M, i, j, ans = 0;
    char tile, mapa[MAX_SIZE][MAX_SIZE + 2];

    scanf("%d %d", &N, &M);

    for (i = 0; i < N; i ++)
        scanf(" %s", mapa[i]);

    for (i = 0; i < N; i ++)
    {
        for (j = 0; j < M; j ++)
        {
            if (mapa[i][j] == '#')
            {
                if (i == 0 || i == N - 1 || j == 0 || j == M - 1)
                    ans ++;
                else if (i > 0 && mapa[i - 1][j] == '.') 
                    ans ++;
                else if (i < N - 1 && mapa[i + 1][j] == '.')
                    ans ++;
                else if (j > 0 && mapa[i][j - 1] == '.')
                    ans ++;
                else if (j < N - 1 && mapa[i][j + 1] == '.')
                    ans ++;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
