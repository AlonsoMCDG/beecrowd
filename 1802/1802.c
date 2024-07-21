// bee 1802 - Catalogo de Livros
// Alonso Martins
// 21/07/2024
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
    return *(const int *)b - *(const int *)a;
}

int main()
{
    int qtd[5], maxN = 1, j, k, i, ii, iii, iv, v;
    int conjuntos[100000];
    int preco_livros[5][10];
    int K, ans;

    for (i = 0; i < 5; i ++)
    {
        scanf("%d", &qtd[i]);

        maxN *= qtd[i];

        for (j = 0; j < qtd[i]; j ++)
            scanf("%d", &preco_livros[i][j]);
    }

    scanf("%d", &K);

    for (i = k = 0; i < qtd[0]; i ++)
    {
        int somaI = preco_livros[0][i];
        for (ii = 0; ii < qtd[1]; ii ++)
        {
            int somaII = somaI + preco_livros[1][ii];
            for (iii = 0; iii < qtd[2]; iii ++)
            {
                int somaIII = somaII + preco_livros[2][iii];
                for (iv = 0; iv < qtd[3]; iv ++)
                {
                    int somaIV = somaIII + preco_livros[3][iv];
                    for (v = 0; v < qtd[4]; v ++, k ++)
                    {
                        int somaV = somaIV + preco_livros[4][v];
                        conjuntos[k] = somaV;
                    }
                }
            }
        }
    }

    qsort(conjuntos, k, sizeof(conjuntos[0]), comp);

    for (i = ans = 0; i < K; i ++)
        ans += conjuntos[i];

    printf("%d\n", ans);

    return 0;
}
