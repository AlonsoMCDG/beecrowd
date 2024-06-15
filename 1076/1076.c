// bee 1076 - Desenhando Labirintos
// Alonso Martins
// 14/06/2024
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T, N, V, A, i, ans, p, q;

    scanf("%d", &T);

    while (T -- && scanf("%d %d %d", &N, &V, &A))
    {
        int nodes[49][49] = {};
        ans = 0;

        for (i = 0; i < A; i ++)
        {
            scanf("%d %d", &p, &q);
            ans += !nodes[p][q];
            nodes[p][q] = nodes[q][p] = 1;
        }

        printf("%d\n", ans * 2);
    }
    
    return 0;
}
