// bee 2567 - Virus
// Alonso Martins
// 08/04/2024
#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}
int letalidade(int *v, int n)
{
    int i, let;
    for (i = 0, let = 0; i < n / 2; let += v[n-i-1] - v[i], i ++)
        continue;
    return let;
}
int main()
{
    int N, i, virus[1000];

    while (scanf("%d", &N) != EOF)
    {
        for (i = 0; i < N; i ++)
            scanf("%d", &virus[i]);

        qsort(virus, N, sizeof(int), comparar);

        printf("%d\n", letalidade(virus, N));
    }
    
    return 0;
}
