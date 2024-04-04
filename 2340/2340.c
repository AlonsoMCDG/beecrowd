// bee 2340 - Feira de Bacterias
// Alonso Martins
// 16/03/2024
#include <stdio.h>
#include <math.h>

int main()
{
    int n, in, D, C;
    double d, max = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++)
    {
        scanf("%d %d", &D, &C);
        d = C * log(D);
        if (d > max)
        {
            max = d;
            in = i;
        }
    }
    printf("%d\n", in);

    return 0;
}
