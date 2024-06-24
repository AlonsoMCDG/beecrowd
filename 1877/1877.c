// bee 1877 - O Castelo de Neve de Sansa
// Alonso Martins
// 23/06/2024
#include <stdio.h>

#define sinal(x) (x < 0 ? -1 : !!(x))

int main()
{
    int N, K, i, d0 = -2, d1, t0, t1, picos = 0, vales = 0;

    scanf("%d %d %d", &N, &K, &t0);

    for (i = 1; i < N; i ++)
    {
        scanf("%d", &t1);
        d1 = sinal(t1 - t0);

        if (d0 == 1 && d1 == -1)
            picos ++;
        else if (d0 == -1 && d1 == 1)
            vales ++;

        d0 = d1;
        t0 = t1;
    }

    printf("%s\n", picos == K && vales == K - 1 ? "beautiful" : "ugly");

    return 0;
}
