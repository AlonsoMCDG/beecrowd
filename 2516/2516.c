// bee 2516 - Corrida
// Alonso Martins
// 11/07/2024
#include <stdio.h>

int main()
{
    double S, va, vb;

    while (scanf("%lf %lf %lf", &S, &va, &vb) != EOF)
    {
        if (va > vb)
            printf("%.2lf\n", S / (va - vb));
        else
            printf("impossivel\n");
    }

    return 0;
}
