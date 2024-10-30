// bee 2961 - O, Que Tanto de Filme!
// Alonso Martins
// 30/10/2024
#include <stdio.h>
#include <string.h>

int main()
{
    int N, i, acertos[4] = {}, min = 200, flag = 0;
    char palpites[4][102], vencedor[102];

    scanf("%d", &N);

    while (N --)
    {
        scanf(" %[^\n]", vencedor);
        for (i = 0; i < 4; i ++)
            scanf(" %[^\n]", palpites[i]);
        
        scanf(" %[^\n]", vencedor);
        for (i = 0; i < 4; i ++)
        {
            scanf(" %[^\n]", vencedor);

            acertos[i] += strcmp(palpites[i], vencedor) == 0;
        }
    }

    for (i = 0; i < 4; i ++) min = acertos[i] < min ? acertos[i] : min;

    for (i = 0; i < 4; i ++)
        if (acertos[i] == min)
            printf("%s%d", flag ++ ? " " : "", i + 1);
    printf("\n");

    return 0;
}
