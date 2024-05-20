// bee 2378 - Elevador
// Alonso Martins
// 19/05/2024
#include <stdio.h>

int main()
{
    int N, M, S, E, p = 0; scanf("%d %d", &N, &M);

    while (N -- && scanf("%d %d", &S, &E))
    {
        p -= S, p += E;
        if (p > M)
        {
            printf("S\n");
            return 0;
        }
    }

    printf("N\n");
    return 0;
}
