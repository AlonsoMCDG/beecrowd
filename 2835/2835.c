// bee 2835 - Elevador
// Alonso Martins
// 09/08/2024
#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

int main()
{
    int N, pesos[10000], i, p;
    char ans = 'S';

    scanf("%d", &N);

    for (i = 0; i < N; i ++)
        scanf("%d", &pesos[i]);

    p = 0;

    qsort(pesos, N, sizeof(int), comp);

    for (i = 0; i < N; i ++)
    {
        if (pesos[i] - p > 8)
        {
            ans = 'N';
            break;
        }
        p = pesos[i];
    }

    printf("%c\n", ans);

    return 0;
}
