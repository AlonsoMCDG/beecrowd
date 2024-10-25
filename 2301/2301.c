// bee 2301 - Vivo ou Morto
// Alonso Martins
// 25/10/2024
#include <stdio.h>
#include <stdlib.h>

typedef struct Jogador
{
    int id;
    struct Jogador *next;
    struct Jogador *prev;
} Jogador;

typedef struct Fila
{
    Jogador *head;
} Fila;

Jogador mem_pool[100] = {};
int count_pool = 0;

Jogador *new_jogador(int id, Jogador *prev)
{
    Jogador *jogador = &mem_pool[count_pool ++];

    jogador->id = id;
    jogador->next = NULL;
    jogador->prev = prev;

    return jogador;
}

void delete(Fila *fila, int id)
{
    Jogador *atual = fila->head;

    while (atual != NULL && atual->id != id)
        atual = atual->next;

    if (atual == fila->head)
        fila->head = atual->next;

    if (atual->prev != NULL)
        atual->prev->next = atual->next;

    if (atual->next != NULL)
        atual->next->prev = atual->prev;
}

void inicializar_fila(Fila *fila, int P)
{
    int i, id;
    count_pool = 0;

    // inicializa o inicio da fila
    scanf("%d", &id);
    fila->head = new_jogador(id, NULL);

    Jogador *jogador = fila->head;

    // preenche o resto da fila
    for (i = 1; i < P; i ++)
    {
        scanf("%d", &id);
        jogador->next = new_jogador(id, jogador);
        jogador = jogador->next;
    }
}

void imprimir_fila(Fila *fila)
{
    Jogador *jogador = fila->head;

    while (jogador)
    {
        printf("%d -> ", jogador->id);
        jogador = jogador->next;
    }
    printf("NULL\n");
}

int main()
{
    int P, R, N, J, i, j, n, num_teste = 1;
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    Jogador *jogador = NULL;

    while (scanf("%d %d", &P, &R), P)
    {
        // faz a leitura da organizacao inicial da fila
        inicializar_fila(fila, P);

        // processa as rodadas
        for (i = 0; i < R; i ++)
        {
            scanf("%d %d", &N, &J);
            jogador = fila->head;

            for (j = 0; j < N; j ++)
            {
                scanf("%d", &n);

                if (n != J)
                    delete(fila, jogador->id);

                jogador = jogador->next;
            }
        }

        printf("Teste %d\n%d\n\n", num_teste ++, fila->head->id);
    }

    return 0;
}
