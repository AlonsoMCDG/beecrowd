// bee 2947 - Gabarito
// Alonso Martins
// 10/09/2024
#include <stdio.h>
#include <stdlib.h>

typedef struct Alt // alternativa
{
    char letra;
    int frequencia;
} Alt;

int comp(const void *a, const void *b)
{
    return ((Alt *)b)->frequencia - ((Alt *)a)->frequencia;
}

int main()
{
    int K, N, i, j;
    Alt respostas[100][26]; // frequencia de cada alternativa em cada questao
    char erradas[102], aluno[102];

    scanf("%d %s %d", &K, erradas, &N);

    // inicializa o vetor
    for (i = 0; i < K; i ++)
    {
        for (j = 0; j < 26; j ++)
        {
            respostas[i][j].letra = j + 'A';
            respostas[i][j].frequencia = 0;
        }

        // aplica penalidade para as questoes erradas
        respostas[i][erradas[i] - 'A'].frequencia = -1000;
    }

    for (i = 0; i < N; i ++)
    {
        scanf(" %s", aluno);

        // aumenta a frequencia de cada alternativa escolhida pelo aluno
        for (j = 0; j < K; j ++)
            respostas[j][aluno[j] - 'A'].frequencia ++;
    }

    // para cada questao, pega a alternativa mais escolhida 
    // que eh diferente da alternativa escolhida por Desafortunato
    int ans = 0;
    for (i = 0; i < K; i ++)
    {
        qsort(respostas[i], 26, sizeof(respostas[i][0]), comp);
        ans += respostas[i][0].frequencia;
    }

    printf("%d\n", ans);

    return 0;
}
