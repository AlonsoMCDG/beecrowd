// bee 2769 - Linha de Montagem
// Alonso Martins
// 17/09/2024
#include <stdio.h>

int min(int x, int y)
{
    return x < y ? x : y;
}

int main()
{
    int N, e1, e2, x1, x2, i, j;
    int S[1000][2], T[1000][2] = {};

    while (scanf("%d", &N) != EOF)
    {
        scanf("%d %d", &e1, &e2);

        for (j = 0; j < 2; j ++)
            for (i = 0; i < N; i ++)
                scanf("%d", &S[i][j]);

        for (j = 0; j < 2; j ++)
            for (i = 1; i < N; i ++)
                scanf("%d", &T[i][j]);
        
        scanf("%d %d", &x1, &x2);

        S[0][0] += e1;
        S[0][1] += e2;

        for (i = 1; i < N; i ++)
            for (j = 0; j < 2; j ++)
                S[i][j] += min(S[i - 1][j], S[i - 1][!j] + T[i][!j]);

        x1 += S[N - 1][0];
        x2 += S[N - 1][1];

        printf("%d\n", min(x1, x2));
    }

    return 0;
}
