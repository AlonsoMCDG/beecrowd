#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b)
{
    return *(const int *)b - *(const int *)a;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int N, i, j, A, resto, q, k, t;
    int revisores[100];

    while (scanf("%d", &N), N)
    {
        for (t = i = 0; i < N; t += revisores[i], i ++)
            scanf("%d", &revisores[i]);

        scanf("%d", &A);
        
        if (t < A)
        {
            printf("Impossible\n");
            continue;
        }

        qsort(revisores, N, sizeof(revisores[0]), comparar);
        int ans[100] = {}, uso;

        for (uso = 0, i = N; i > 0; i --)
        {
            revisores[i - 1] -= uso;

            if (A < i) 
                break;

            k = min(revisores[i - 1], A / i);
            uso += k;
            A -= k * i;
            ans[i - 1] = uso;
        }

        for (j = 0; j < N; j ++)
        {
            if (j < i)
                ans[j] += uso + (j < A);

            printf("%d\n", ans[j]);
        }
    }

    return 0;
}
