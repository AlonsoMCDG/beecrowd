// bee 3102 - Kikoho
// Alonso Martins
// 11/07/2024
#include <stdio.h>
#include <math.h>

typedef struct Point
{
    int x;
    int y;
} Point;

double dist(Point p, Point q)
{
    return sqrt(pow(p.x - q.x, 2) + pow(p.y - q.y, 2));
}

int main()
{
    int N;
    double P, A, B, C, area;
    Point p1, p2, p3;
    
    scanf("%d", &N);

    while (N -- && scanf("%d %d %d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y))
    {
        A = dist(p1, p2);
        B = dist(p2, p3);
        C = dist(p3, p1);
        P = (A + B + C) / 2.0;
    
        /** Haron **/
        area = sqrt(P * (P - A) * (P - B) * (P - C));

        printf("%.3lf\n", area);
    }

    return 0;
}
