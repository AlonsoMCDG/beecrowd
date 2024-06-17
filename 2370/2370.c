// bee 2370 - Times
// Alonso Martins
// 17/06/2024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nome[100];
    int nivel;
} jogador;

typedef struct
{
    jogador selecao[500];
    int qtd_jogadores;
} time;

int comp_nivel(const void *a, const void *b)
{
    jogador *A = (jogador *)a, *B = (jogador *)b;
    return B->nivel - A->nivel;
}

int comp_nome(const void *a, const void *b)
{
    jogador *A = (jogador *)a, *B = (jogador *)b;
    return strcmp(A->nome, B->nome);
}

int main()
{
    int N, T, i, t;

    scanf("%d %d", &N, &T);

    jogador jogadores[N];

    for (i = 0; i < N; i ++)
        scanf(" %s %d", jogadores[i].nome, &jogadores[i].nivel);

    qsort(jogadores, N, sizeof(jogador), comp_nivel);

    time time;

    for (t = 0; t < T; t ++)
    {
        time.qtd_jogadores = 0;

        for (i = t; i < N; i += T)
            time.selecao[time.qtd_jogadores ++] = jogadores[i];

        qsort(time.selecao, time.qtd_jogadores, sizeof(jogador), comp_nome);

        printf("Time %d\n", t + 1);
        for (i = 0; i < time.qtd_jogadores; i ++)
            printf("%s\n", time.selecao[i].nome);
        printf("\n");
    }

    return 0;
}
