// bee 2568 - Acoes
// Alonso Martins
// 29/05/2024
#include <stdio.h>

int main()
{
    int D, I, X, F;

    scanf("%d %d %d %d", &D, &I, &X, &F);

    printf("%d\n", I + (2 * (D % 2) - 1) * X * (F % 2));

    return 0;
}
