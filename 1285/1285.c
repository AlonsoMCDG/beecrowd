// bee 1285 - Digitos Diferentes
// Alonso Martins
// 16/06/2024
#include <stdio.h>

void calc(int *v)
{
    int i, j, ok;
    for (i = 1; i <= 5000; i ++)
    {
        v[i] = v[i - 1];
        int dig[10] = {};
        int aux = i, d;
        ok = 1;
        while (aux && ok)
        {
            d = aux % 10;
            if (dig[d])
                ok = 0;
            dig[d] = 1;
            aux /= 10;
        }
        if (ok)
            v[i] ++;
    }
}

int main()
{
    int ans[5001] = {};
    int N, M;

    calc(ans);

    while (scanf("%d %d", &N, &M) != EOF)
    {
        printf("%d\n", ans[M] - ans[N - 1]);
    }
    

    return 0;
}
