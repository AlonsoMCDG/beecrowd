// bee 2871 - Colheita de Cafe
// Alonso Martins
// 13/09/2024
#include <stdio.h>

int main()
{
    int N, M, sacas, litros, k, i, j;

    while (scanf("%d %d", &N, &M) != EOF)
    {
        for (i = litros = 0; i < N; i ++)
            for (j = 0; j < M; j ++)
                scanf("%d", &k), litros += k;
        
        sacas = litros / 60;
        litros %= 60;

        printf("%d saca(s) e %d litro(s)\n", sacas, litros);
    }

    return 0;
}
