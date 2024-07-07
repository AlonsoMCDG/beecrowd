// bee 2404 - Reduzindo Detalhes em um Mapa
// Alonso Martins
// 07/07/2024
#include <stdio.h>
#include <stdlib.h>

typedef struct Edge
{
    int p;
    int q;
    int w;
} Edge;

int comp(const void *a, const void *b)
{
    return ((Edge *)a)->w - ((Edge *)b)->w;
}

int find(int *v, int id)
{
    int root = id, nxt;
    while (v[root] != root)
        root = v[root];

    while (v[id] != root)  // compressao de caminho
        nxt = v[id], v[id] = root, id = nxt;

    return root;
}

int main()
{
    int N, M, ans = 0, i, j, p, q, w;
    scanf("%d %d", &N, &M);
    Edge edges[M];
    int vertices[500];

    for (i = 0; i < N; i ++)
        vertices[i] = i;

    for (i = 0; i < M; i ++)
    {
        scanf("%d %d %d", &p, &q, &edges[i].w);
        edges[i].p = p - 1;
        edges[i].q = q - 1;
    }
    
    qsort(edges, M, sizeof(edges[0]), comp);

    /* Kruskal */
    for (i = 0; i < M; i ++)
    {
        int r1 = find(vertices, edges[i].p);
        int r2 = find(vertices, edges[i].q);

        if (r1 == r2)
            continue;

        ans += edges[i].w; // adiciona o comprimento do caminho na resposta
        vertices[r2] = r1; // une os conjuntos

        // se todos os vértices estão no mesmo conjunto, terminamos
        if (-- N == 1)
            break;
    }

    printf("%d\n", ans);

    return 0;
}
