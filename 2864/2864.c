// bee 2864 - Qual e a Altura?
// Alonso Martins
// 17/08/2024
#include <stdio.h>
#include <math.h>

int main()
{
    int N;
    double a, b, c, delta;

    scanf("%d", &N);

    while (N -- && scanf("%lf %lf %lf", &a, &b, &c))
    {
        double x = -b / (2 * a);
        double y = a * x * x + b * x + c;

        printf("%.2lf\n", y);
    }

    return 0;
}

// x'  = -b + sqrt(b² - 4ac) / (2a)
// x'' = -b - sqrt(b² - 4ac) / (2a)

// x_max = (x' + x'') / 2
// x_max = [(-b + sqrt(b² - 4ac)) / (2a) + 
//          (-b - sqrt(b² - 4ac)) / (2a)] / 2
// x_max = [(-b + sqrt(b² - 4ac) - b - sqrt(b² - 4ac)) / (2a)] / 2
// x_max = (- b - b) / (2 * 2a)
// x_max = -2b / 4a
// x_max = -b / 2a

// y = a * x_max² + b * x_max + c
