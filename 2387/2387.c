// bee 2387 - Dentista
// Alonso Martins
// 01/09/2024
#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
    return ((const void **)a)[1] - ((const void **)b)[1];
}

int main()
{
    int N, i, ans = 0, fim = 0, horarios[10000][2];

    scanf("%d", &N);

    for (i = 0; i < N; i ++)
        scanf("%d %d",  &horarios[i][0], &horarios[i][1]);
    
    qsort(horarios, N, sizeof(horarios[0]), comp);

    for (i = 0; i < N; i ++)
    {
        if (horarios[i][0] >= fim)
        {
            fim = horarios[i][1];
            ans ++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
