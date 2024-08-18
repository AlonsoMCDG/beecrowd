// bee 1244 - Ordenacao por Tamanho
// Alonso Martins
// 18/08/2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Texto
{
    char texto[52];
    int tamanho;
    int posicao;
} Texto;

int comp(const void *a, const void *b)
{
    Texto *A = (Texto *)a, *B = (Texto *)b;

    return (B->tamanho - A->tamanho) * 100 + (A->posicao - B->posicao);
}

int main()
{
    char entrada[400], c;
    Texto strings[50];
    int N, i, quantidadeStrings;

    scanf("%d", &N);

    while (N --)
    {
        quantidadeStrings = 0;
        for (i = 0; i < 50; i ++)
        {
            scanf(" %s", strings[i].texto);
            strings[i].tamanho = strlen(strings[i].texto);
            strings[i].posicao = i;
            quantidadeStrings ++;

            if (c = getchar(), c == '\n' || c == EOF)
                break;
        }

        qsort(strings, quantidadeStrings, sizeof(strings[0]), comp);

        for (i = 0; i < quantidadeStrings; i ++)
        {
            printf("%s%s", strings[i].texto, i == quantidadeStrings - 1 ? "\n" : " ");
        }
    }

    return 0;
}
