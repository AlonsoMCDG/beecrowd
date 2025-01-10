// bee 2654 - Godofor
// Alonso Martins
// 10/01/2025
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Candidato
{
    char nome[102];
    int poder;
    int deuses_mortos;
    int num_morreu;
} Candidato;

int comp(const void *a, const void *b)
{
    Candidato *A = (Candidato *)a, *B = (Candidato *)b;

    if (A->poder != B->poder)
        return B->poder - A->poder;

    if (A->deuses_mortos != B->deuses_mortos)
        return B->deuses_mortos - A->deuses_mortos;

    if (A->num_morreu != B->num_morreu)
        return A->num_morreu - B->num_morreu;

    return strcmp(A->nome, B->nome);
}

int main()
{
    int N, i;
    Candidato candidatos[100];

    scanf("%d", &N);

    for (i = 0; i < N; i ++)
        scanf(" %s %d %d %d", candidatos[i].nome, &candidatos[i].poder, &candidatos[i].deuses_mortos, &candidatos[i].num_morreu);

    qsort(candidatos, N, sizeof(Candidato), comp);

    printf("%s\n", candidatos[0].nome);

    return 0;
}
