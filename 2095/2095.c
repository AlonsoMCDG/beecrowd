// bee 2095 - Guerra
// Alonso Martins
// 18/09/2024
#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
    return *(const int *)b - *(const int *)a;
}

int main()
{
    int N, i, j, nog[100000], quad[100000], ans;

    scanf("%d", &N);

    for (i = 0; i < N; i ++)
        scanf("%d", &quad[i]);

    for (i = 0; i < N; i ++)
        scanf("%d", &nog[i]);

    qsort(nog, N, sizeof(nog[0]), comp);
    qsort(quad, N, sizeof(quad[0]), comp);

    ans = i = j = 0;

    while (i < N && j < N)
    {
        if (nog[j] > quad[i])
        {
            ans ++;
            j ++;
        }
        i ++;
    }

    printf("%d\n", ans);

    return 0;
}
