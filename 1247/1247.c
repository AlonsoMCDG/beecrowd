// bee 1247 - Guarda Costeira
// Alonso Martins
// 16/06/2024
#include <stdio.h>
#include <math.h>

int main()
{
    int D, VF, VG;
    double tf, tg, dg;

    while (scanf("%d %d %d", &D, &VF, &VG) != EOF)
    {
        tf = 12.0 / VF;
        dg = sqrt(D * D + 144.0);
        tg = dg / VG;

        printf("%s\n", tg <= tf ? "S" : "N");
    }

    return 0;
}
