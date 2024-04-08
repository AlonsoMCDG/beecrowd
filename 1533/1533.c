// bee 1533 - Detetive Watson
// Alonso Martins
// 08/04/2024
#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b)
{
    return *(const int *)b - *(const int *)a;
}
int prender(int *s, int suspeito, int size)
{
    int i;
    for (i = 0; i < size && s[i] != suspeito; i ++)
        continue;
    return i + 1;
}
int main()
{
    int N, i;
    int suspeitos[1000], suspeitosOrd[1000];

    while (scanf("%d", &N) && N)
    {
        for (i = 0; i < N; i ++)
        {
            scanf("%d", &suspeitos[i]);
            suspeitosOrd[i] = suspeitos[i];
        }

        qsort(suspeitosOrd, N, sizeof(int), comparar);
        
        printf("%d\n", prender(suspeitos, suspeitosOrd[1], N));
    }

    return 0;
}
