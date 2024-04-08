// bee 2556 - Reinauguracao do CEI
// Alonso Martins
// 08/04/2024
#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}
int main()
{
    int N, i, tempos[1000];

    while (scanf("%d", &N) != EOF)
    {
        for (i = 0; i < N; i ++)
            scanf("%d", &tempos[i]);

        qsort(tempos, N, sizeof(int), comparar);

        printf("%d %d\n", N / 2, tempos[N / 2] - tempos[N / 2 - 1]);
    }

    return 0;
}
