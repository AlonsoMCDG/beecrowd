// bee 2823 - Eearliest Deadline First
// Alonso Martins
// 25/09/2024
#include <stdio.h>

int main()
{
    int N;
    double U = 0.0, T, P;

    scanf("%d", &N);

    while (N -- && scanf("%lf %lf", &T, &P))
        U += T / P;

    printf("%s\n", U <= 1 ? "OK" : "FAIL");

    return 0;
}
