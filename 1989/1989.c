// bee 1989 - Fazendo Nada
// Alonso Martins
// 18/08/2024
#include <stdio.h>

int main()
{
    long long N, M, i, C;
    while (scanf("%lld %lld", &N, &M), N > 0)
    {
        long long tempoTotal = 0;

        for (i = 0; i < N; i ++)
        {
            scanf("%lld", &C);
            tempoTotal += C * M * (N - i);
        }

        printf("%lld\n", tempoTotal);
    }
    return 0;
}
