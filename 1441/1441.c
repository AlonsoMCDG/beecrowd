// bee 1441 - Sequencias de Granizo
// Alonso Martins
// 18/08/2024
#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int N;

    while (scanf("%d", &N), N)
    {
        int ans = N;

        while (N > 1)
        {
            N = N % 2 ? 3 * N + 1 : N / 2;
            ans = max(ans, N);
        }

        printf("%d\n", ans);
    }

    return 0;
}
