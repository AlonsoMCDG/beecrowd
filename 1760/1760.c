// bee 1760 - Floco de Neve de Koch
// Alonso Martins
// 29/05/2024
#include <stdio.h>

int main()
{
    int S;
    double A;

    while (scanf("%d", &S) != EOF)
    {
        A = S * S * 0.69282032302; // A = S^2 * (2/5) * sqrt(3)

        printf("%.2lf\n", A);
    }

    return 0;
}
