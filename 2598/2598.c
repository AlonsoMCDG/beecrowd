// bee 2598 - Colocando Radares
// Alonso Martins
// 21/06/2024
#include <stdio.h>

int main()
{
    int C, N, M;

    scanf("%d", &C);

    while (C -- && scanf("%d %d", &N, &M))
        printf("%d\n", N / M + !!(N % M));

    return 0;
}
