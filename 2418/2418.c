// bee 2418 - Carnaval
// Alonso Martins
// 08/06/2024
#include <stdio.h>

int main()
{
    int i = 5;
    double M = 5.0, m = 10.0, n, ans = 0;

    while (i -- && scanf("%lf", &n))
    {
        M = n > M ? n : M;
        m = n < m ? n : m;
        ans += n;
    }

    printf("%.1lf\n", ans - M - m);

    return 0;
}
