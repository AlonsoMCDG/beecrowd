// bee 1708 - Volta
// Alonso Martins
// 21/07/2024
#include <stdio.h>
#include <math.h>

int main()
{
    double X, Y;

    scanf("%lf %lf", &X, &Y);

    printf("%d\n", (int)ceil(1 / (1 - X / Y)));

    return 0;
}
