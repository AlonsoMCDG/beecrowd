// bee 1483 - Jogo do Bicho
// Alonso Martins
// 28/10/2024
#include <stdio.h>

int main()
{
    int N, M, grupo1, grupo2;
    double V, multiplicador, premio;

    while (scanf("%lf %d %d", &V, &N, &M), N || M || V)
    {
        grupo1 = (N + (4 - N % 4) % 4) % 100;
        grupo2 = (M + (4 - M % 4) % 4) % 100;

        if (N % 10000 == M % 10000) multiplicador = 3000;
        else if (N % 1000 == M % 1000) multiplicador = 500;
        else if (N % 100 == M % 100) multiplicador = 50;
        else if (grupo1 == grupo2) multiplicador = 16;
        else multiplicador = 0;

        premio = V * multiplicador;
        printf("%.2lf\n", premio);
    }

    return 0;
}
