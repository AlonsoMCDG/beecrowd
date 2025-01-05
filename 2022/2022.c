// bee 2022 - Presentes de Natal
// Alonso Martins
// 05/01/2025
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Presente
{
    char nome[100];
    double valor;
    int preferencia;
} Presente;

int comp(const void *a, const void *b)
{
    Presente *A = (Presente *)a, *B = (Presente *)b;

    if (A->preferencia != B->preferencia)
        return B->preferencia - A->preferencia;

    if (A->valor != B->valor)
        return A->valor - B->valor;

    return strcmp(A->nome, B->nome);
}

int main()
{
    int N, i;
    char nome_lista[100];
    Presente presentes[100];

    while (scanf(" %s %d", nome_lista, &N) != EOF)
    {
        for (i = 0; i < N; i ++)
            scanf(" %[^\n] %lf %d", presentes[i].nome, &presentes[i].valor, &presentes[i].preferencia);

        qsort(presentes, N, sizeof(presentes[0]), comp);

        printf("Lista de %s\n", nome_lista);
        for (i = 0; i < N; i ++)
            printf("%s - R$%.2lf\n", presentes[i].nome, presentes[i].valor);
        printf("\n");
    }

    return 0;
}
