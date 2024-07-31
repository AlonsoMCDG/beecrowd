// bee 1553 - Perguntas mais Frequentes
// Alonso Martins
// 30/07/2024
#include <stdio.h>

int main()
{
    int N, K, p;

    while (scanf("%d %d", &N, &K), N && K)
    {
        int frequencia[101] = {}, i, ans = 0;

        for (i = 0; i < N; i ++)
        {
            scanf("%d", &p);
            frequencia[p] ++;

            ans += frequencia[p] == K;
        }

        printf("%d\n", ans);
    }

    return 0;
}
