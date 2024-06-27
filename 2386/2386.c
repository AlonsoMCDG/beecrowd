// bee 2386 - Telescopio
// Alonso Martins
// 26/06/2024
#include <stdio.h>

int main()
{
    int T, N, L, i, ans = 0;

    scanf("%d %d", &T, &N);

    while (N -- && scanf("%d", &L))
        ans += L * T >= 40000000;

    printf("%d\n", ans);

    return 0;
}
