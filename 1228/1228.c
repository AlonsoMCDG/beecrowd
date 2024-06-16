// bee 1228 - Grid de Largada
// Alonso Martins
// 16/06/2024
#include <stdio.h>

int dir(int x)
{
    return x < 0 ? -1 : !!x;
}

void swap(int *a, int *b)
{
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}

int main()
{
    int N, i, j, ans, id, p, a, b;
    int pos[25];
    int grid[24];

    while (scanf("%d", &N) != EOF)
    {
        ans = 0;

        for (i = 0; i < N; i ++)
            scanf("%d", &grid[i]), pos[grid[i]] = i;

        for (i = 0; i < N; i ++)
        {
            scanf("%d", &id);
            for (j = pos[id]; j != i; j += p)
            {
                p = dir(i - j), a = id, b = grid[j + p];
                swap(&grid[pos[a]], &grid[pos[b]]);
                pos[a] += p, pos[b] -= p;
                ans ++;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
