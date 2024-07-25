// bee 2229 - Dobradura
// Alonso Martins
// 24/07/2024
#include <stdio.h>
#include <math.h>

int main()
{
    int N, ans, l, t = 1;

    while (scanf("%d", &N), N != -1)
    {
        l = pow(2, N) - 1;
        ans = 4 + l * l + 4 * l;

        printf("Teste %d\n", t ++);
        printf("%d\n", ans);
        printf("\n");
    }

    return 0;
}
