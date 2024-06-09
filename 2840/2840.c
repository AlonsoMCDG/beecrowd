// bee 2840 - Balao++
// Alonso Martins
// 08/06/2024
#include <stdio.h>

int main()
{
    double R, L, PI = 3.1415, volume;

    scanf("%lf %lf", &R, &L);

    volume = 4.0 * PI * R * R * R / 3.0;

    printf("%d\n", (int)(L / volume));

    return 0;
}
