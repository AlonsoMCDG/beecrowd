// bee 2382 - Sedex Marciano
// Alonso Martins
// 17/07/2024
#include <stdio.h>
#include <math.h>

int main()
{
    double L, A, P, R, diag;

    scanf("%lf %lf %lf %lf", &L, &A, &P, &R);

    diag = sqrt(L * L + A * A + P * P) / 2.0;

    printf("%c\n", diag <= R ? 'S' : 'N');

    return 0;
}
