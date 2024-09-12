// bee 1611 - Elevador Lotado
// Alonso Martins
// 12/09/2024
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int comp(const void *a, const void *b)
{
    return *(const int *)b - *(const int *)a;
}

int main()
{
    int T, N, C, M, i;
    int andares[50000];

    scanf("%d", &T);

    while (T -- && scanf("%d %d %d", &N, &C, &M))
    {
        int ans = 0;
        for (i = 0; i < M; i ++)
            scanf("%d", &andares[i]);
        
        qsort(andares, M, sizeof(andares[0]), comp);

        for (i = 0; i < ceil(1.0 * M / C); i ++)
            ans += 2 * andares[(int)fmin(i * C, M - 1)];

        printf("%d\n", ans);
    }

    return 0;
}
