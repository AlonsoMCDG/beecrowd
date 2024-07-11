// bee 1766 - O Elfo das Trevas
// Alonso Martins
// 11/07/2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Rena
{
    char nome[102];
    int peso;
    int idade;
    double altura;
} Rena;

int comp(const void *a, const void *b)
{
    Rena *r1 = (Rena *)a, *r2 = (Rena *)b;
    return (r2->peso - r1->peso) * 10000 + (r1->idade - r2->idade) * 10 + strcmp(r1->nome, r2->nome);
}

int main()
{
    int T, N, K, i, t = 1;
    char nome[102];
    Rena renas[1000];

    scanf("%d", &T);

    while (T -- && scanf("%d %d", &N, &K))
    {
        for (i = 0; i < N; i ++)
            scanf(" %s %d %d %lf", renas[i].nome, &renas[i].peso, &renas[i].idade, &renas[i].altura);

        qsort(renas, N, sizeof(renas[0]), comp);

        printf("CENARIO {%d}\n", t ++);
        for (i = 0; i < K; i ++)
            printf("%d - %s\n", i + 1, renas[i].nome);
    }

    return 0;
}
