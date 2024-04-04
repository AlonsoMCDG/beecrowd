// 2420 - Guerra por Territorio
// Alonso Martins
// 03/04/2024
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, *t, t1, i, total = 0;

    scanf("%d", &N);
    
    t = (int *)malloc(N * sizeof(int));

    for (i = 0; i < N; i ++)
    {
        scanf("%d", &t[i]);
        total += t[i];
    }

    for (i = 0, t1 = 0; t1 != total / 2; i ++)
        t1 += t[i];

    printf("%d\n", i);

    return 0;
}
