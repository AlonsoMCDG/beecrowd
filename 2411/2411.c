// bee 2411 - O Tabuleiro Esburacado
// Alonso Martins
// 13/06/2024
#include <stdio.h>

typedef struct pos
{
    int x, y;
} pos;

int main()
{
    int N, m, passos = 0;
    pos C = {4, 3};
    pos movs[] = {{0, 0}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
    int tab[8][8] = {};
    tab[1][3] = tab[2][3] = tab[2][5] = tab[5][4] = 1;

    scanf("%d", &N);

    while (N -- && scanf("%d", &m) && !tab[C.x][C.y])
        C.x += movs[m].x, C.y += movs[m].y, passos ++;

    printf("%d\n", passos);

    return 0;
}
