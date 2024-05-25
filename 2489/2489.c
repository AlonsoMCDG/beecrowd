// bee 2489 - Flecha no Coelho
// Alonso Martins
// 25/05/2024
#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793
#define DEG_TO_RAD(x) (x * PI / 180.0)

int main()
{
    double A, R, D, H;

    while (scanf("%lf %lf %lf", &A, &D, &R) != EOF)
    {
        R *= PI / 180.0;

        if (R < 90)
            H = -D / tan(R) + A;
        else
            H = tan(R) * D + A;

        printf("%.4lf\n", H);
    }

    return 0;
}
