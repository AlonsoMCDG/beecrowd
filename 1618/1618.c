// bee 1618 - Colisao
// Alonso Martins
// 18/08/2024
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Point
{
    int x;
    int y;
} Point;

int main()
{
    int N, i;
    Point points[4];
    Point robot;

    scanf("%d", &N);

    while (N --)
    {
        for (i = 0; i < 4; i ++)
            scanf("%d %d", &points[i].x, &points[i].y);

        scanf("%d %d", &robot.x, &robot.y);

        Point A = points[0];
        Point B = points[1];
        Point C = points[2];
        Point D = points[3];

        bool estaDentro = A.x <= robot.x && robot.x <= C.x && A.y <= robot.y && robot.y <= C.y;

        printf("%d\n", estaDentro);
    }

    return 0;
}
