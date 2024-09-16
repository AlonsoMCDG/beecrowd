// bee 2355 - Brasil e Alemanha
// Alonso Martins
// 15/09/2024
#include <stdio.h>
#include <math.h>

int main()
{
    int N, B, A;

    while (scanf("%d", &N), N)
    {
        B = (int)floor(N / 90.0);
        A = (int)ceil(7.0 * N / 90.0);
        printf("Brasil %d x Alemanha %d\n", B, A);
    }

    return 0;
}
