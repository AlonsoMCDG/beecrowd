// bee 2833 - Campeonato
// Alonso Martins
// 04/08/2024
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int jogadores[16], i;
    char *saidas[20] = {"oitavas", "quartas", "semifinal", "final"};

    for (i = 0; i < 16; i ++)
        scanf("%d", &jogadores[i]);
    
    int p, q, j;
    int jogos[] = {8, 4, 2, 1}, etapa_atual = -1;
    bool se_enfrentaram = false;

    while (etapa_atual < 4 && !se_enfrentaram)
    {
        etapa_atual ++;

        for (j = 0; j < jogos[etapa_atual]; j ++)
        {
            p = jogadores[2 * j];
            q = jogadores[2 * j + 1];

            if (p == 1 && q == 9 || p == 9 && q == 1)
            {
                se_enfrentaram = true;
                break;
            }

            jogadores[j] = p;
            if (q == 1 || q == 9)
                jogadores[j] = q;
        }
    }

    printf("%s\n", saidas[etapa_atual]);

    return 0;
}
