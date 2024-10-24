// bee 2135 - Recuperacao
// Alonso Martins
// 23/10/2024
#include <stdio.h>

#define INVALIDO -100

int main()
{
    int N, i, k, soma, a, instancia = 1;

    while (scanf("%d", &N) != EOF)
    {
        soma = 0;
        k = INVALIDO;
        for (i = 0; i < N; i ++)
        {
            scanf("%d", &a);

            if (k == INVALIDO && soma == a)
                k = a;

            soma += a;
        }

        printf("Instancia %d\n", instancia ++);
        printf(k == INVALIDO ? "nao achei\n" : "%d\n", k);
        printf("\n");
    }

    return 0;
}
