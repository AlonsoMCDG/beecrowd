// bee 1258 - Camisetas
// Alonso Martins
// 18/08/2024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Demanda
{
    char cor[10];
    char tamanho;
    char aluno[100];
} Demanda;

int comp(const void *a, const void *b)
{
    Demanda *A = (Demanda *)a, *B = (Demanda *)b;

    return strcmp(A->cor, B->cor) * 100 + (B->tamanho - A->tamanho) * 10 + strcmp(A->aluno, B->aluno);
}

int main()
{
    int N, i = 0;
    Demanda camisas[60];

    while (scanf("%d", &N), N)
    {
        if (i) printf("\n");

        for (i = 0; i < N; i ++)
        {
            scanf(" %[^\n] %s %c", camisas[i].aluno, camisas[i].cor, &camisas[i].tamanho);
        }

        qsort(camisas, N, sizeof(camisas[0]), comp);

        for (i = 0; i < N; i ++)
        {
            printf("%s %c %s\n", camisas[i].cor, camisas[i].tamanho, camisas[i].aluno);
        }
    }

    return 0;
}
