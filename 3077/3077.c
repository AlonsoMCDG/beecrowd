// bee 3077 - Distribuindo Pequis
// Alonso Martins
// 21/07/2024
#include <stdio.h>
#include <math.h>

int main()
{
    int N, K, i, j, t;
    int pequis[1000] = {}, p;

    scanf("%d %d", &N, &K);
    t = (int)fmin(N, K);

    for (i = 0; i < N; i ++)
    {
        scanf("%d", &p);
        for (j = 0; j < t; j ++)
        {
            if (p == 0)
                continue;

            pequis[(i + j) % N] += p * (K / N + (j < K % N));
        }
    }

    for (i = 0; i < N; i ++)
        printf("%d%s", pequis[i], i < N - 1 ? " " : "\n");

    return 0;
}
