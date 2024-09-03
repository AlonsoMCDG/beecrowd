// bee 2294 - Duende Perdido
// Alonso Martins
// 02/09/2024
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define DEBUG 0
#define debug if (DEBUG)

#define I 0
#define J 1
#define DIST 2
#define SAIDA 0
#define CRISTAL 2
#define VISITADO 4

typedef struct Fila
{
    int itens[100][3];
    int inicio;
    int fim;
} Fila;

void insert(Fila *fila, int i, int j, int dist)
{
    fila->fim ++;
    fila->itens[fila->fim][I] = i;
    fila->itens[fila->fim][J] = j;
    fila->itens[fila->fim][DIST] = dist;
}

void explorar(int map[10][10], bool visitado[10][10], int i, int j, int N, int M, int dist, Fila *fila)
{
    if (i >= 0 && i < N && j >= 0 && j < M)
        if (map[i][j] != CRISTAL && !visitado[i][j])
        {
            insert(fila, i, j, dist);
            visitado[i][j] = true;
        }
}

Fila *create_fila()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->inicio = 0;
    f->fim = -1;

    return f;
}

int main()
{
    int N, M, i, j, dist, map[10][10];
    int duende[2];

    scanf("%d %d", &N, &M);

    for (i = 0; i < N; i ++)
    {
        for (j = 0; j < M; j ++)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 3)
            {
                duende[I] = i;
                duende[J] = j;
            }
        }
    }

    Fila *fila = create_fila();
    bool visitado[10][10] = {};
    explorar(map, visitado, duende[I], duende[J], N, M, 0, fila);
    i = duende[I], j = duende[J];
    fila->inicio = -1;

    while (map[i][j] != SAIDA)
    {
        fila->inicio ++;
        dist = fila->itens[fila->inicio][DIST];
        i = fila->itens[fila->inicio][I];
        j = fila->itens[fila->inicio][J];

        explorar(map, visitado, i - 1, j, N, M, dist + 1, fila);
        explorar(map, visitado, i + 1, j, N, M, dist + 1, fila);
        explorar(map, visitado, i, j - 1, N, M, dist + 1, fila);
        explorar(map, visitado, i, j + 1, N, M, dist + 1, fila);

    }

    printf("%d\n", fila->itens[fila->inicio][DIST]);

    return 0;
}
