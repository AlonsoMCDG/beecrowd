// bee 2303 - Margaridas
// Alonso Martins
// 17/06/2024
#include <stdio.h>
#include <math.h>

int main()
{
    int L, C, M, N, X, ans = 0, i, j, l, c;
    int lotes[1000][1000] = {};

    scanf("%d %d %d %d", &L, &C, &M, &N);

    for (i = 0; i < L; i ++)
    {
        for (j = 0; j < C; j ++)
        {
            l = i / M;
            c = j / N;

            scanf("%d", &X);
            lotes[l][c] += X;

            ans = (int)fmax(ans, lotes[l][c]);
        }
    }

    printf("%d\n", ans);

    return 0;
}
