// bee 2452 - Semente
// Alonso Martins
// 24/11/2024
#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main()
{
    int F, R, i, a = 1, b, ans = 0;

    scanf("%d %d %d", &F, &R, &a);
    ans = a - 1;

    for (i = 1; i < R; i ++)
    {
        scanf("%d", &b);
        ans = max((b - a) / 2, ans);
        a = b;
    }
    ans = max(F - a, ans);

    printf("%d\n", ans);

    return 0;
}
