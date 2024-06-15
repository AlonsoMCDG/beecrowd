// bee 1170 - Blobs
// Alonso Martins
// 14/06/2024
#include <stdio.h>
#include <math.h>

int main()
{
    double N, S;

    scanf("%lf", &N);

    while (N -- && scanf("%lf", &S))
        printf("%d dias\n", (int)ceil(log2(S)));

    return 0;
}
