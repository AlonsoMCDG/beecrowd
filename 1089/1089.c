// bee 1089 - Loop Musical
// Alonso Martins
// 11/04/2024
#include <stdio.h>

int main()
{
    int N, picos, i;
    int sequencia[10002];

    while (scanf("%d", &N) && N)
    {
        picos = 0;
        for (i = 0; i < N; i++)
            scanf("%d", &sequencia[i]);

        sequencia[N] = sequencia[0];
        sequencia[N + 1] = sequencia[1];

        for (i = 1; i <= N; i++)
            if (sequencia[i - 1] < sequencia[i] && sequencia[i] > sequencia[i + 1] ||
                sequencia[i - 1] > sequencia[i] && sequencia[i] < sequencia[i + 1])
                picos++;

        printf("%d\n", picos);
    }

    return 0;
}
