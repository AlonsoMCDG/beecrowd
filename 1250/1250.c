// bee 1250 - KiloMan
// Alonso Martins
// 13/05/2024
#include <stdio.h>

int main()
{
    int N, T, ans, i;
    int tiros[50];
    char m;

    scanf("%d", &N);

    while (ans = 0, scanf("%d", &T), N --)
    {
        for (i = 0; i < T; i ++)
            scanf("%d", &tiros[i]);
        scanf("%*c"); // remover o '\n'

        for (i = 0; i < T; i ++)
            if(scanf("%c", &m), m == 'S' && tiros[i] <= 2 || m == 'J' && tiros[i] > 2)
                ans ++;

        printf("%d\n", ans);
    }

    return 0;
}
