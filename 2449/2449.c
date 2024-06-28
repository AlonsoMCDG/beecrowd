// bee 2449 - Fechadura
// Alonso Martins
// 27/06/2024
#include <stdio.h>

#define abs(x) ((x) < 0 ? -(x) : (x))

int main()
{
    int N, M, i, t0, t1, ans = 0, p;

    scanf("%d %d %d", &N, &M, &t0);

    if (N == 1)
        ans = abs(t0 - M);

    for (i = 1; i < N; i ++)
    {
        scanf("%d", &t1);
        
        p = M - t0;
        ans += abs(p);
        t1 += p;
        t0 = t1;
    }

    printf("%d\n", ans);

    return 0;
}
