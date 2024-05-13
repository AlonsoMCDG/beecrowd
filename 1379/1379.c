// bee 1379 - Problema com Mediana e Media
// Alons Martins
// 12/05/2024
#include <stdio.h>

int main()
{
    int A, B, C;

    while (scanf("%d %d", &A, &B) && A + B)
    {
        C = 3 * A - A - B;
        printf("%d\n", C);
    }

    return 0;
}
