// bee 1093 - Vampiros
// Alonso Martins
// 09/05/2024
#include <stdio.h>
#include <math.h>

int main()
{
    int EV1, EV2, D, AT;
    int maxV, maxD;
    double ans, p, pV, pD;

    while (scanf("%d %d %d %d", &EV1, &EV2, &AT, &D) && EV1 + EV2 + D + AT)
    {
        maxV = ceil((double)EV2 / D);   // maximo de vitorias de V1
        maxD = ceil((double)EV1 / D);   // maximo de derrotas de V1
        pV = AT / 6.0;          // probabilidade de vencer uma rodada
        pD = (6 - AT) / 6.0;    // probabilidade de perder uma rodada
        p = pD / pV;
        ans = 0;        // saida do programa

        if (AT == 3)
            ans = (double) maxD / (maxV + maxD);
        else
            ans = (1.0 - pow(p, maxD)) / (1.0 - pow(p, maxD + maxV));

        printf("%.1lf\n", ans * 100);
    }

    return 0;
}
