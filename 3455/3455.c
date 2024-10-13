// bee 3455 - Banco Nacional de Questoes
// Alonso Martins
// 13/10/2024
#include <stdio.h>

typedef long long ll;

double a_to_b(double A) { return 2.0 * A / 3; }
double a_to_c(double A) { return 2.0 * A / 5; }
double b_to_a(double B) { return 3.0 * B / 2; }
double c_to_a(double C) { return 5.0 * C / 2; }

int main()
{
    double A, B, C;
    ll total;
    char max;

    scanf("%lf %lf %lf", &A, &B, &C);
    scanf(" %c", &max);

    if (max == 'A')
        total = (ll)(A + b_to_a(B) + c_to_a(C));
    else if (max == 'B')
        total = (ll)(B + a_to_b(A + c_to_a(C)));
    else
        total = (ll)(C + a_to_c(A + b_to_a(B)));

    printf("%lld\n", total);

    return 0;
}
