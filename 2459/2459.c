// bee 2459 - Copa do Mundo
// Alonso Martins
// 19/05/2024
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int p, q, custo;
} Edge;

int comparar(const void *a, const void *b)
{
    Edge *A = (Edge *)a, *B = (Edge *)b;
    return A->custo - B->custo;
}

int findRoot(int *id, int p)
{
    int root = p;
    while (id[root] != root)
        root = id[root];

    // faz a compressao do caminho de p ate root
    while (p != root)
    {
        int next = id[p];
        id[p] = root;
        p = next;
    }

    return root;
}

int main()
{
    int N, i, F, R, A, B, custo, custoTotal = 0;
    scanf("%d %d %d", &N, &F, &R);
    int id[N], sz[N], componentes = N;
    Edge edges[F + R];

    for (i = 0; i < N; i ++)
        id[i] = i, sz[i] = 1;

    for (i = 0; i < F + R; i ++)
        scanf("%d %d %d", &A, &B, &custo),
            edges[i].p = A - 1, edges[i].q = B - 1, edges[i].custo = custo;

    // algoritmo de kruskal
    qsort(edges, F, sizeof(edges[0]), comparar);
    qsort(&edges[F], R, sizeof(edges[0]), comparar);

    for (i = 0; i < F + R && componentes > 1; i ++)
    {
        int root1 = findRoot(id, edges[i].p);
        int root2 = findRoot(id, edges[i].q);

        if (root1 == root2) // ja estao conectadas
            continue;

        // conecta o menor componente no maior
        if (sz[root1] >= sz[root2])
            id[root2] = root1, sz[root1] += sz[root2];
        else
            id[root1] = root2, sz[root2] += sz[root1];

        custoTotal += edges[i].custo;
        componentes --;
    }

    printf("%d\n", custoTotal);

    return 0;
}
