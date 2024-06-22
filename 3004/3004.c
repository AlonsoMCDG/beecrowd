// bee 3004 - Envelopes
// Alonso Martins
// 21/06/2024
#include <stdio.h>
#include <math.h>

int main()
{
    int N, A, B, C, D, s1, s2;

    scanf("%d", &N);

    while (N -- && scanf("%d %d %d %d", &A, &B, &C, &D))
    {
        s1 = A + B, s2 = C + D;
        A = (int)fmax(A, B), C = (int)fmax(C, D);
        B = s1 - A, D = s2 - C;

        printf("%s\n", A < C && B < D ? "S" : "N");
    }

    return 0;
}
