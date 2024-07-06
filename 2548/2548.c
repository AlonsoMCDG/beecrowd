// bee 2548 - Museu Virtual 3D
// Alonso Martins
// 05/07/2024
#include <stdio.h>

int main()
{
    int N, M, i, ans, modelos[1000];

    while (scanf("%d %d", &N, &M) != EOF)
    {
        for (i = 0; i < N; i ++)
            scanf("%d", &modelos[i]);

        for (i = N - 1, ans = 0; i >= 0 && i >= N - M; i --)
            ans += modelos[i];

        printf("%d\n", ans);
    }

    return 0;
}
