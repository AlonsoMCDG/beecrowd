// bee 2372 - Reuniao
// Alonso Martins
// 06/07/2024
#include <stdio.h>
#include <math.h>

#define INF 100000

int main()
{
    int N, M, i, j, u, v, W, k, ans = INF;

    scanf("%d %d", &N, &M);

    int dist[N][N];
    int maxdist[N];

    for (i = 0; i < N; i ++)
    {
        for (j = 0; j < N; j ++)
            dist[i][j] = INF * (i != j);
        maxdist[i] = 0;
    }

    for (i = 0; i < M; i ++)
    {
        scanf("%d %d %d", &u, &v, &W);
        dist[u][v] = dist[v][u] = W;
    }

    //// Algoritmo de Floyd-Warshall
    for (k = 0; k < N; k ++)
        for (u = 0; u < N; u ++)
            for (v = 0; v < N; v ++)
                if (dist[u][v] > dist[u][k] + dist[k][v])
                    dist[u][v] = dist[u][k] + dist[k][v];
    ////

    // calcular a menor distancia maxima
    for (i = 0; i < N; i ++)
    {
        int d = 0;
        for (j = 0; j < N; j ++)
            d = (int)fmax(d, dist[i][j]);
        ans = (int)fmin(d, ans);
    }

    printf("%d\n", ans);

    return 0;
}
