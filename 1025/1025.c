// bee 1025 - Onde esta o Marmore?
// Alonso Martins
// 07/04/2024
#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
void search(int *v, int search, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (v[i] == search)
        {
            printf("%d found at %d\n", search, i + 1);
            return;
        }
    }
    printf("%d not found\n", search);
    return;
}
int main()
{
    int N, Q, i, caso = 0, x;
    int marbles[10001];
    while (scanf("%d %d", &N, &Q) && N + Q && ++caso)
    {
        printf("CASE# %d:\n", caso);

        for (i = 0; i < N; i++)
            scanf("%d", &marbles[i]);

        qsort(marbles, N, sizeof(int), comparar);

        for (i = 0; i < Q; i++)
        {
            scanf("%d", &x);
            search(marbles, x, N);
        }
    }
    return 0;
}
