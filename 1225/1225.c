// bee 1225 - Coral Perfeito
// Alonso Martins
// 14/07/2024
#include <stdio.h>
#include <math.h>

int main()
{
    int N, i, notas[10000], media, ans;

    while (scanf("%d", &N) != EOF)
    {
        for (i = media = 0; i < N; i ++)
        {
            scanf("%d", &notas[i]);
            media += notas[i];
        }

        if (media % N)
        {
            printf("-1\n");
            continue;
        }

        media /= N;
        for (i = ans = 1; i < N; i ++)
            ans += (int)fmax(0, notas[i] - media);
        
        printf("%d\n", ans);
    }

    return 0;
}
