// bee 2392 - Pulo do Sapo
// Alonso Martins
// 11/07/2024
#include <stdio.h>

int main()
{
    int N, K, i, s, p;
    int pedras[1000] = {};

    scanf("%d %d", &N, &K);

    while (K -- && scanf("%d %d", &s, &p))
        for (i = 0; s + i <= N || s - i >= 1; i += p)
            pedras[499 + s + i] = pedras[499 + s - i] = 1;

    for (i = 500; i < N + 500; i ++)
        printf("%d\n", pedras[i]);

    return 0;
}
