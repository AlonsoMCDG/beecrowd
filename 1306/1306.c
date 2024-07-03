// bee 1306 - Numerando Estradas
// Alonso Martins
// 02/07/2024
#include <stdio.h>
#include <math.h>

int main()
{
    int R, N, ans, t = 0;

    while (scanf("%d %d", &R, &N), R && N)
    {
        ans = (int)fmax(0, ceil(1.0 * R / N) - 1);

        printf("Case %d: ", ++ t);
        printf(ans > 26 ? "impossible\n" : "%d\n", ans);
    }

    return 0;
}
