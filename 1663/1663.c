// bee 1663 - Permutacoes Ambiguas
// Alonso Martins
// 25/06/2024
#include <stdio.h>

#define MAX 100000
int main()
{
    int N, i, X, permutacao[MAX], inversa[MAX], amb;

    while (scanf("%d", &N), N)
    {
        for (i = 0; i < N; i ++)
            scanf("%d", &X), permutacao[i] = X, inversa[X - 1] = i + 1;

        for (i = amb = 1; i < N && amb; i ++)
            if (permutacao[i] != inversa[i])
                amb = 0;
        
        printf("%sambiguous\n", amb ? "" : "not ");
    }

    return 0;
}
