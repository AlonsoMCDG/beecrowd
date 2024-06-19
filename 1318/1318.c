// bee 1318 - Bilhetes Falsos
// Alonso Martins
// 18/06/2024
#include <stdio.h>

int main()
{
    int N, M, i, id, ans;

    while (scanf("%d %d", &N, &M), N && M)
    {
        int bilhetes[10000] = {};
        ans = 0;

        for (i = 0; i < M; i ++)
        {
            scanf("%d", &id);
            ans += (++ bilhetes[id - 1]) == 2;
        }

        printf("%d\n", ans);
    }

    return 0;
}
