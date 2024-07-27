// bee 2405 - Colorindo
// Alonso Martins
// 26/07/2024
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_POINTS 201

typedef struct Pos { int x, y; } Pos;

typedef struct Queue
{
    Pos pos[MAX_POINTS * MAX_POINTS];
    int start;
    int end;
} Queue;

void insert(Queue *q, int x, int y)
{
    q->pos[q->end].x = x;
    q->pos[q->end].y = y;
    q->end ++;
}

Pos dequeue(Queue *q)
{
    return q->pos[q->start ++];
}

bool is_empty(Queue *q)
{
    return q->start >= q->end;
}

bool indice_eh_valido(int y, int x, int L, int C)
{
    return 1 <= x && x <= C && 1 <= y && y <= L;
}

int main()
{
    int N, M, X, Y, K, A, B, i, j, x, y, ans = 0;
    bool is_colorido[MAX_POINTS][MAX_POINTS] = {};
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    Pos p;
    queue->start = 0;
    queue->end = 0;

    scanf("%d %d %d %d %d", &N, &M, &Y, &X, &K);

    while (K -- && scanf("%d %d", &A, &B))
        is_colorido[A][B] = true;

    insert(queue, X, Y);

    is_colorido[Y][X] = true;

    while (!is_empty(queue))
    {
        p = dequeue(queue);
        ans ++;

        for (i = -1; i <= 1; i ++)
        {
            for (j = -1; j <= 1; j ++)
            {
                x = p.x + i, y = p.y + j;

                if ((i || j) && indice_eh_valido(y, x, N, M) && !is_colorido[y][x])
                {
                    is_colorido[y][x] = true;

                    insert(queue, x, y);
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
