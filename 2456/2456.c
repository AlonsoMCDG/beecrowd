// bee 2156 - As Aventuras de Pak-man
// Alonso Martins
// 18/08/2024
#include <stdio.h>
#include <string.h>

#define X 0
#define Y 1

enum // ULRD
{
    UP,
    LEFT,
    RIGHT,
    DOWN
};

int directions[][2] = { // {x, y}
    { 0, -1}, // UP
    {-1,  0}, // LEFT
    {+1,  0}, // RIGHT
    { 0, +1}  // DOWN
};

typedef struct Pakman
{
    int x;
    int y;
    int dir;
} Pakman;

int walk(Pakman *p, char map[100][102], int L, int C)
{
    int x = p->x + directions[p->dir][X];
    int y = p->y + directions[p->dir][Y];

    if (0 <= x && x <= C && 0 <= y && y <= L)
    {
        if (map[y][x] != '#')
        {
            map[p->y][p->x] = ' ';
            p->x = x;
            p->y = y;

            return map[y][x] == '*';
        }
    }

    return 0;
}

int main()
{
    int L, C, I, i, pastilhasColetadas;
    Pakman pakman;

    char map[100][102], *c;

    while (scanf("%d %d %d", &L, &C, &I), L)
    {
        int flag = 0;
        for (i = 0; i < L; i ++)
        {
            scanf(" %[^\n]", map[i]);

            if (flag) continue;
            if (c = strchr(map[i], '<'))
            {
                pakman.x = (c - map[i]);
                pakman.y = i;
                pakman.dir = RIGHT;
                flag = 1;
            }
        }

        char comando[I + 2];
        scanf(" %s", comando);

        pastilhasColetadas = 0;
        for (i = 0; i < I; i ++)
        {
            if (comando[i] == 'W')
                pastilhasColetadas += walk(&pakman, map, L - 1, C - 1);
            else
                pakman.dir = (comando[i] % 5); // ULRD
        }

        printf("%d\n", pastilhasColetadas);
    }
    

    return 0;
}
