// bee 2518 - Escada do DINF
// Alonso Martins
// 01/08/2024
#include <stdio.h>
#include <math.h>

int main()
{
    double N, H, C, L, K, area;

    while (scanf("%lf %lf %lf %lf", &N, &H, &C, &L) != EOF)
    {
        K = sqrt(H * H + C * C);

        area = N * K * L / 10000.0;

        printf("%.4lf\n", area);
    }

    return 0;
}
