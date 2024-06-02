// bee 1340 - Eu Posso Adivinhar a Estrutura de Dados!
// Alonso Martins
// 01/06/2024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Elemento {
    int valor; // usado por todas as estruturas
    struct Elemento *anterior; // usado pela fila de prioridade
    struct Elemento *proximo; // fila de prioridade e pilha
} Elemento;

typedef struct
{
    int elementos[1001], inicio, fim;
} Fila;

typedef struct
{
    Elemento elementos[1001];
    Elemento *inicio;
    int tamanho;
} Pilha;

typedef struct
{
    Elemento elementos[1001];
    Elemento *inicio;
    int tamanho;
} PriorityQueue;

int zerar(Fila *q, Pilha *s, PriorityQueue *p)
{
    // fila
    q->inicio = 0;
    q->fim = -1;

    // pilha
    s->tamanho = 0;
    s->inicio = NULL;
    
    // fila de prioridade
    p->tamanho = 0;
    p->inicio = NULL;
}

void fila_guardar(Fila *q, int valor)
{
    q->elementos[++ q->fim] = valor;
}

int fila_retirar(Fila *q, int valor)
{
    if (q->fim < q->inicio) return 0;
    return q->elementos[q->inicio ++] == valor;
}

void pilha_guardar(Pilha *s, int valor)
{
    Elemento *e = &s->elementos[s->tamanho ++];
    e->valor = valor;
    e->proximo = s->inicio;
    s->inicio = e;
}

int pilha_retirar(Pilha *s, int valor)
{
    if (s->inicio == NULL) return 0;
    int v = s->inicio->valor;
    s->inicio = s->inicio->proximo;
    return v == valor;
}

void priorityQueue_guardar(PriorityQueue *p, int valor)
{
    Elemento *e = &p->elementos[p->tamanho ++];
    e->valor = valor;

    if (p->inicio == NULL || e->valor > p->inicio->valor)
    {
        e->proximo = p->inicio;
        e->anterior = NULL;
        if (p->inicio != NULL) p->inicio->anterior = e;
        p->inicio = e;
        return;
    }

    Elemento *anterior = p->inicio;
    Elemento *proximo = p->inicio->proximo;

    while (proximo != NULL && proximo->valor > e->valor)
    {
        anterior = proximo;
        proximo = proximo->proximo;
    }

    if (anterior != NULL) anterior->proximo = e;
    e->proximo = proximo;
    e->anterior = anterior;
}

int priorityQueue_retirar(PriorityQueue *p, int valor)
{
    if (p->inicio == NULL) return 0;
    int v = p->inicio->valor;
    p->inicio = p->inicio->proximo;
    return v == valor;
}

void listar_pq(PriorityQueue *p)
{
    Elemento *e = p->inicio;

    printf("\npq:\n");
    if (e == NULL) printf("Vazio\n");
    while (e != NULL)
    {
        printf("valor: %d\n", e->valor);
        e = e->proximo;
    }
}

int main()
{
    int N, C, X;
    char *ans[] = { "impossible", "queue", "stack", "priority queue", "not sure", "not sure", "not sure" };

    Fila fila;
    Pilha pilha;
    PriorityQueue pq;

    while (scanf("%d", &N) != EOF)
    {
        int ehFila, ehPilha, ehPQueue;
        ehFila = ehPilha = ehPQueue = 1;
        
        zerar(&fila, &pilha, &pq);

        while (N -- && scanf("%d %d", &C, &X))
            if (C == 1)
            {
                fila_guardar(&fila, X);
                pilha_guardar(&pilha, X);
                priorityQueue_guardar(&pq, X);
            }
            else
            {
                ehFila = (ehFila && fila_retirar(&fila, X));
                ehPilha = (ehPilha && pilha_retirar(&pilha, X));
                ehPQueue = (ehPQueue && priorityQueue_retirar(&pq, X));
            }
        
        printf("%s\n", ans[1 * ehFila + 2 * ehPilha + 3 * ehPQueue]);
    }

    return 0;
}
