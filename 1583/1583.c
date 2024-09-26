// bee 1583 - Contaminacao
// Alonso Martins
// 25/09/2024
#include <stdio.h>
#include <string.h>

#define CONTAMINANTE 'T'
#define ROCHA 'X'
#define AGUA 'A'

void floodfill(char m[50][52], int i, int j, int N, int M)
{
    if (i < 0 || i == N || j < 0 || j == M || m[i][j] == CONTAMINANTE || m[i][j] == ROCHA)
        return;

    m[i][j] = CONTAMINANTE;
    floodfill(m, i - 1, j, N, M);
    floodfill(m, i + 1, j, N, M);
    floodfill(m, i, j - 1, N, M);
    floodfill(m, i, j + 1, N, M);
}

int main()
{
    int N, M, i, j;
    char mapa[50][52];

    while (scanf("%d %d", &N, &M), N && M)
    {
        for (i = 0; i < N; i ++)
        {
            scanf(" %s", mapa[i]);
            for (j = 0; j < M; j ++)
                if (mapa[i][j] == 'T')
                    mapa[i][j] = 't';
        }

        for (i = 0; i < N; i ++)    
            for (j = 0; j < M; j ++)
                if (mapa[i][j] == 't')
                    floodfill(mapa, i, j, N, M);

        for (i = 0; i < N; i ++)
            printf("%s\n", mapa[i]);
        printf("\n");
    }

    return 0;
}
