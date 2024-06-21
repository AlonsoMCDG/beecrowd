// bee 2398 - Caca ao Tesouro
// Alonso Martins
// 20/06/2024
#include <stdio.h>
#include <math.h>

int main()
{
    int N, K, X, Y, D, x, y, q = 0, m = 0, ansx, ansy;
    int mapa[100][100] = {};
    int ehPista[100][100] = {};

    scanf("%d %d", &N, &K);

    while (K --)
    {
        scanf("%d %d %d", &X, &Y, &D);

        Y = N - 1 - Y;
        ehPista[Y][X] = D;

        for (x = -D; y = D - (int)fabs(x), x <= D; x ++)
        {
            if (X + x < 0) continue;
            else if (X + x >= N) break;

            if (Y - y >= 0) mapa[Y - y][X + x] ++;
            if (y && Y + y <  N) mapa[Y + y][X + x] ++;
        }
    }

    for (y = 0; y < N; y ++)
        for (x = 0; x < N; x ++)
            if (!ehPista[y][x])
                if (mapa[y][x] > m)
                    m = mapa[y][x], ansx = x, ansy = N - 1 - y, q = 1;
                else if (mapa[y][x] == m)
                    q ++;

    if (q == 1)
        printf("%d %d\n", ansx, ansy);
    else
        printf("-1 -1\n");

    return 0;
}
