// bee 2584 - Pentagono
// Alonso Martins
// 19/09/2024
#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

int main()
{
    int N;
    double L, area;

    scanf("%d", &N);

    while (N -- && scanf("%lf", &L))
    {
        area = L * L * tan(3.0 * PI / 10.0) * 5.0 / 4.0;

        printf("%.3lf\n", area);
    }

    return 0;
}
