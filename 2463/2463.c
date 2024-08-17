// bee 2463 - Corredor
// Alonso Martins
// 16/08/2024
#include <stdio.h>

int main()
{
    int N, x, i, soma, ans = 0;

    scanf("%d", &N);

    for (i = soma = 0; i < N; i ++)
    {
        scanf("%d", &x);
        soma += x;

        if (soma > ans) ans = soma;
        if (soma < 0) soma = 0;
    }

    printf("%d\n", ans);

    return 0;
}
