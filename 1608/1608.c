// bee 1608 - Bolos da Maria
// Alonso Martins
// 17/05/2024
#include <stdio.h>

#define VALOR_ALTO 10000000000

int main()
{
    int T, D, I, B, Q, i, q; scanf("%d", &T);
    int menorCusto, custo;
    int precos[100];

    while (menorCusto = VALOR_ALTO, T -- && scanf("%d %d %d", &D, &I, &B))
    {
        for (i = 0; i < I; i ++)
            scanf("%d", &precos[i]);
        
        while (custo = 0, B -- && scanf("%d", &Q))
        {
            while (Q -- && scanf("%d %d", &i, &q))
                custo += precos[i] * q;

            if (custo < menorCusto) 
                    menorCusto = custo;
        }
        
        printf("%d\n", D / menorCusto);
    }

    return 0;
}
