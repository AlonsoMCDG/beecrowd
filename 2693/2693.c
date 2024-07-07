// bee 2693 - Van
// Alonso Martins
// 07/07/2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno
{
    char nome[100];
    char regiao;
    int custo;
} Aluno;

int comp(const void *a, const void *b)
{
    Aluno *A = (Aluno *)a, *B = (Aluno *)b;
    return (A->custo - B->custo) * 1000 + (A->regiao - B->regiao) * 10 + (strcmp(A->nome, B->nome));
}

int main()
{
    int Q, C, i;
    char regiao;
    Aluno alunos[100];

    while (scanf("%d", &Q) != EOF)
    {
        for (i = 0; i < Q; i ++)
            scanf(" %s %c %d", alunos[i].nome, &alunos[i].regiao, &alunos[i].custo);

        qsort(alunos, Q, sizeof(alunos[0]), comp);

        for (i = 0; i < Q; i ++)
            printf("%s\n", alunos[i].nome);
    }

    return 0;
}
