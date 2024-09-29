// bee 1136 - Bingo!
// Alonso Martins
// 28/09/2024
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int N, B, i, j;
    int cartas[91], carta;
    bool ans;

    while (scanf("%d %d", &N, &B), N)
    {
        bool existe[200] = {};

        for (i = 0; i < B; i ++)
        {
            scanf("%d", &cartas[i]);
            existe[cartas[i]] = true;
        }

        for (i = 0; i <= N; i ++)
        {
            ans = false;
            for (j = 0; j < B && !ans; j ++)
            {
                carta = cartas[j] + i;
                ans = existe[carta];
            }

            if (!ans) break;
        }

        printf("%c\n", ans ? 'Y' : 'N');
    }

    return 0;
}
