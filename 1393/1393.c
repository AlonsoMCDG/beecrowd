// bee 1393 - Lajotas Hexagonais
// Alonso Martins
// 24/05/2024
#include <stdio.h>

int main()
{
    int i, N, passos[45] = {1, 1};

    for (i = 2; i <= 40; i ++)
        passos[i] = passos[i - 1] + passos[i - 2];

    while (scanf("%d",  &N) && N)
        printf("%d\n", passos[N]);

    return 0;
}
