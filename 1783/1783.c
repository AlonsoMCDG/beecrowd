// bee 1783 - Ih, Ferrou, um Buraco Negro!
// Alonso Martins
// 06/08/2024
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point
{
    double x, y;
} Point;

double get_coefficient(Point *p)
{
    double dx = p[1].x - p[0].x;
    double dy = p[1].y - p[0].y;

    return dy / dx;
}

Point * ponto_medio(Point *p)
{
    Point *m = (Point *)malloc(sizeof(Point));

    m->x = (p[0].x + p[1].x) / 2;
    m->y = (p[0].y + p[1].y) / 2;

    return m;
}

int main()
{
    int T, t = 0;
    Point A[2], B[2];

    scanf("%d", &T);
    while (t ++ < T)
    {
        scanf("%lf %lf %lf %lf", &A[0].x, &A[0].y, &B[0].x, &B[0].y);
        scanf("%lf %lf %lf %lf", &A[1].x, &A[1].y, &B[1].x, &B[1].y);

        double coefA = get_coefficient(A);
        double coefB = get_coefficient(B);

        double rA = -1 / coefA;
        double rB = -1 / coefB;

        Point *mA = ponto_medio(A);
        Point *mB = ponto_medio(B);

        double nA = coefA ? mA->y - rA * mA->x : 0;
        double nB = coefB ? mB->y - rB * mB->x : 0;

        double x = !coefA ? mA->x : !coefB ? mB->x : (nB - nA) / (rA - rB);
        double y = coefA ? rA * x + nA : rB * x + nB;
        
        printf("Caso #%d: %.2lf %.2lf\n", t, x, y);
    }

    return 0;
}
