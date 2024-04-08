// bee 2534 - Exame Geral
// Alonso Martins
// 08/04/2024
#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}
int main()
{
    int N, Q, i, c;
    int notas[100];

    while (scanf("%d %d", &N, &Q) != EOF)
    {
        for (i = 0; i < N; i ++)
            scanf("%d", &notas[i]);

        qsort(notas, N, sizeof(int), comparar);

        for (i = 0; i < Q; i ++)
        {
            scanf("%d", &c);
            printf("%d\n", notas[c - 1]);
        }
    }
    return 0;
}
