// bee 2203 - Tempestade de Corvos
// Alonso Martins
// 05/09/2024
#include <stdio.h>
#include <math.h>

int main()
{
    double xf, yf, xi, yi, v, r1, r2, d;

    while (scanf("%lf %lf %lf %lf %lf %lf %lf", &xf, &yf, &xi, &yi, &v, &r1, &r2) != EOF)
    {
        d = sqrt(pow(xi - xf, 2) + pow(yi - yf, 2)); // distancia entr Fiddlesticks e o inimigo 
        d += 1.5 * v; // o inimigo se move nesse tempo

        if (d <= r1 + r2)  // o ataque alcanca o inimigo
            printf("Y\n");
        else  // o ataque nao alcanca o inimigo
            printf("N\n");
    }

    return 0;
}
