// bee 2341 - Numero de Envelopes
// Alonso Martins
// 05/09/2024
#include <stdio.h>

int main()
{
    int N, K, i, rotulos[1000] = {}, r;

    scanf("%d %d", &N, &K);

    for (i = 0; i < N; i ++)
    {
        scanf("%d", &r);
        rotulos[r - 1] ++;
    }

    // coloca na primeira posicao a menor quantidade de rotulos
    for (i = 1; i < K; i ++)
        if (rotulos[i] < rotulos[0])
            rotulos[0] = rotulos[i];

    printf("%d\n", rotulos[0]);

    return 0;
}
