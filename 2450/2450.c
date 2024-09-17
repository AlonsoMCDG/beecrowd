// bee 2450 - Matriz Escada
// Alonso Martins
// 16/09/2024
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int N, M, i, j, x;
    int nonzero_lin[500] = {}; // indice coluna do primeiro elemento diferente de zero na linha i

    for (i = 0; i < 500; i ++)
        nonzero_lin[i] = 501 + i;

    scanf("%d %d", &N, &M);

    for (i = 0; i < N; i ++)
    {
        for (j = 0; j < M; j ++)
        {
            scanf("%d", &x);

            if (x != 0 && nonzero_lin[i] >= 500)
                nonzero_lin[i] = j;
        }
    }

    int l = N - 2, c = nonzero_lin[N - 1];
    bool eh_triangular = true;

    while (l >= 0)
    {
        if (nonzero_lin[l] >= c)
        {
            eh_triangular = false;
            break;
        }
        c = nonzero_lin[l --];
    }

    printf(eh_triangular ? "S\n" : "N\n");

    return 0;
}
