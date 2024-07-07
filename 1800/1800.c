// bee 1800 - Onde Estao Minhas Chaves
// Alonso Martins
// 07/07/2024
#include <stdio.h>

int main()
{
    int Q, E, i, C; scanf("%d %d", &Q, &E);
    int visitados[1000] = {};

    for (i = 0; i < E; i ++)
        scanf("%d", &C), visitados[C - 1] = 1;

    for (i = 0; i < Q; i ++)
        scanf("%d", &C), printf("%d\n", !visitados[C - 1]), visitados[C - 1] = 1;

    return 0;
}
