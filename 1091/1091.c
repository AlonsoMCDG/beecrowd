// bee 1091 - Divisão da Nlogônia
// Alonso Martins
// 04/04/2024
#include <stdio.h>

int main()
{
    int K, N, M, X, Y, i;
    char div[2][2][3] = {{"SO", "NO"}, {"SE", "NE"}};

    while (scanf("%d", &K) && K)
    {
        scanf("%d %d", &N, &M);

        for (i = 0; i < K; i ++)
        {
            scanf("%d %d", &X, &Y);

            if (X == N || Y == M)
                printf("divisa\n");
            else
                printf("%s\n", div[X>N][Y>M]);
        }
    }
    return 0;
}
