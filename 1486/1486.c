// bee 1486 - Circuito Bioquimico Digital
// Alonso Martins
// 25/09/2024
#include <stdio.h>

int main()
{
    int P, N, C, i, j, bit;

    while (scanf("%d %d %d", &P, &N, &C), P)
    {
        int ans[1001] = {};
        int tam_palitos[1001] = {};

        for (i = 0; i < N; i ++)
        {
            for (j = 0; j < P; j ++)
            {
                scanf("%d", &bit);
                if (bit == 0)
                {
                    ans[tam_palitos[j]] ++;
                    tam_palitos[j] = 0;
                }
                else
                {
                    tam_palitos[j] ++;
                }
            }
        }

        for (j = 0; j < P; j ++)
            ans[tam_palitos[j]] ++;

        int total = 0;
        for (i = C; i <= N; i ++)
            total += ans[i];

        printf("%d\n", total);
    }

    return 0;
}
