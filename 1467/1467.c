// bee 1467 - Zerinho ou Um
// Alonso Martins
// 24/05/2024
#include <stdio.h>

int main()
{
    int A, B, C;

    while (scanf("%d %d %d", &A, &B, &C) != EOF)
        if (A != B && A != C)
            printf("A\n");
        else if (B != A && B != C)
            printf("B\n");
        else if (C != A && C != B)
            printf("C\n");
        else
            printf("*\n");

    return 0;
}
