// bee 2348 - Dating On-Line
// Alonso Martins
// 30/05/2024
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793
#define DEG_TO_RAD(x) (x * PI / 180.0)

int comp(const void *a, const void *b)
{
    return *(const int *)b - *(const int *)a;
}

int main()
{
    int N, i;
    scanf("%d", &N);
    int atividades[100004] = {};
    int areas[100004] = {};

    for (i = 0; i < N; i ++)
        scanf("%d", &atividades[i]);

    qsort(atividades, N, sizeof(int), comp);

    atividades[N] = atividades[N + 1] = atividades[N - 1];

    int meio = (N + 1) / 2;
    areas[meio] = atividades[0];

    for (i = 0; i < meio; i ++)
    {
        areas[meio - (i + 1)] = atividades[1 + 2 * i];
        areas[meio + (i + 1)] = atividades[2 + 2 * i];
    }

    double angulo = DEG_TO_RAD(360.0/N);
    double area, areaTotal = 0.0;

    for (i = 0; i < N; i ++)
    {
        int a = areas[i], b = areas[i + 1];
        area = 0.5 * a * b * sin(angulo);
        area = 
        areaTotal += area;
    }

    printf("%.3lf\n", areaTotal);

    return 0;
}
