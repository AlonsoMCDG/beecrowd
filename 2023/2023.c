// bee 2023 - A Ultima Crianca Boa
// Alonso Martins
// 25/09/2024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Crianca
{
    char nome[82];
    char nome_low[82];
} Crianca;

int comp(const void *a, const void *b)
{
    Crianca *A = (Crianca *)a, *B = (Crianca *)b;

    return strcmp(A->nome_low, B->nome_low);
}

int main()
{
    Crianca criancas[1000];
    int num_criancas = 0, i, sz;

    while (scanf(" %[^\n]", criancas[num_criancas].nome) != EOF)
    {
        sz = strlen(criancas[num_criancas].nome);

        for (i = 0; i <= sz; i ++)
            criancas[num_criancas].nome_low[i] = tolower(criancas[num_criancas].nome[i]);

        num_criancas ++;
    }

    qsort(criancas, num_criancas, sizeof(criancas[0]), comp);

    printf("%s\n", criancas[num_criancas - 1].nome);

    return 0;
}
