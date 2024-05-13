// bee 1428 - Procurando Nessy
// Alonso Martins
// 13/05/2024
#include <stdio.h>
#include <math.h>

int main()
{
    int T, n, m;

    scanf("%d", &T);

    while (T -- && scanf("%d %d", &n, &m))
    {
        n -= 2; m -= 2;
        printf("%d\n", (int)ceil(n / 3.0) * (int)ceil(m / 3.0));
    }

    return 0;
}
