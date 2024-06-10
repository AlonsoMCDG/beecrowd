// bee 1774 - Roteadores
// Alonso Martins
// 09/06/2024
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int r1, r2, custo;
} Cabo;

int comparar(const void *a, const void *b)
{
    Cabo *A = (Cabo *)a, *B = (Cabo *)b;
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
    int R, C, p, q, v, i, restantes, ans = 0;
    int roteadores[60];
    Cabo cabos[200];

    scanf("%d %d", &R, &C);

    for (i = 0; i < R; i ++)
        roteadores[i] = i;

    for (i = 0; i < C; i ++)
    {
        scanf("%d %d %d", &p, &q, &v);
        cabos[i].r1 = p;
        cabos[i].r2 = q;
        cabos[i].custo = v;
    }

    qsort(cabos, C, sizeof(cabos[0]), comparar);

    for (restantes = R, i = 0; i < C && restantes > 0; i ++)
    {
        p = findRoot(roteadores, cabos[i].r1 - 1), q = findRoot(roteadores, cabos[i].r2 - 1);

        if (p == q)
            continue;

        roteadores[q] = p;
        restantes --;
        ans += cabos[i].custo;
    }

    printf("%d\n", ans);

    return 0;
}
