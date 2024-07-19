// bee 1641 - Restaurante e Pizzaria do Alfredo
// Alonso Martins
// 19/07/2024
#include <stdio.h>

int main()
{
    double R, L, C, D;
    int t = 1;

    while (scanf("%lf", &R), R)
    {
        scanf("%lf %lf", &L, &C);

        D = L * L + C * C;

        printf("Pizza %d %s on the table.\n", t ++, D <= 4 * R * R ? "fits" : "does not fit");
    }

    return 0;
}
