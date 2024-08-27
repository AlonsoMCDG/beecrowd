// bee 1524 - Fila do Bandejao
// Alonso Martins
// 27/08/2024
#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
    return *(const int *)b - *(const int *)a;
}

int main()
{
    int N, K, ans, i, p0, p1, dist[1010];

    while (scanf("%d %d", &N, &K) != EOF)
    {
        dist[0] = p0 = 0;
        for (i = 1; i < N; i ++)
        {
            scanf("%d", &p1);
            dist[i] = p1 - p0;
            p0 = p1;
        }

        qsort(dist, N, sizeof(dist[0]), comp);

        for (ans = 0, i = K - 1; i < N; i ++)
            ans += dist[i];

        printf("%d\n", ans);
    }

    return 0;
}
