// bee 1620 - Triangulacao de Delaunay
// Alonso Martins
// 12/09/2024
#include <stdio.h>

int main()
{
    double N;

    while (scanf("%lf", &N), N)
        printf("%lf\n", 1 - 3 / N);

    return 0;
}
