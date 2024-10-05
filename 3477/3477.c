// bee 3477 - Bau Danificado
// Alonso Martins
// 04/10/2024
#include <stdio.h>
#include <math.h>

int main()
{
    double X, Y, Z, R, area;

    scanf("%lf %lf %lf", &X, &Y, &Z);

    R = Z / 2;

    if (X * X == Y * Y + Z * Z)
    {
        area = 3 * R * R / 2; // semicirculo
        area += Z * Y / 2; // triangulo

        printf("AREA = %d\n", (int)area);
    }
    else
    {
        printf("Nao eh retangulo!\n");
    }

    return 0;
}
