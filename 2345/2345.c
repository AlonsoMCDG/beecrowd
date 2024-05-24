// bee 2345 - Assigning Teams
// Alonso Martins
// 24/05/2024
#include <stdio.h>
#include <math.h>

int main()
{
    int A, B, C, D;

    scanf("%d %d %d %d", &A, &B, &C, &D);

    printf("%d\n", (int)fabs((A + D) - (B + C)));

    return 0;
}
