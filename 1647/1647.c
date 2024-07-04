// bee 1647 - Um Jogo com Bolas de Gude
// Alonso Martins
// 03/07/2024
#include <stdio.h>

int main()
{
    int N, i;
    long long ans, bacia[50];

    while (ans = 0, scanf("%d", &N), N)
    {
        for (i = 0; i < N; i ++)
            scanf("%lld", &bacia[i]);
        
        for (i = N - 1; i >= 0; i --)
        {
            bacia[i] += ans;
            ans += bacia[i];
        }

        printf("%lld\n", ans);
    }

    return 0;
}
