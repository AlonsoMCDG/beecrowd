// bee 2111 - Entendendo o Sorobov
// Alonso Martins
// 29/09/2024
#include <stdio.h>
#include <string.h>

int soborov[10][2] = {
    {1, 0}, // 0
    {1, 1}, // 1
    {1, 2}, // 2
    {1, 3}, // 3
    {1, 4}, // 4
    {0, 0}, // 5
    {0, 1}, // 6
    {0, 2}, // 7
    {0, 3}, // 8
    {0, 4}, // 9
};

int main()
{
    int i, j, sz;
    char aux[12];

    while (scanf(" %s", aux) != EOF)
    {
        char num[12] = {};
        sz = strlen(aux);

        for (i = 0; i < sz; i ++)
            num[8 - i] = aux[sz - i - 1] - '0';

        // imprime a parte acima da linha
        for (j = 0; j < 2; j ++, printf("\n"))
            for (i = 0; i < 9; i ++)
                printf("%d", j != soborov[num[i]][0]);

        printf("---------\n");

        // imprime a parte abaixo da linha
        for (j = 0; j < 5; j ++, printf("\n"))
            for (i = 0; i < 9; i ++)
                printf("%d", j != soborov[num[i]][1]);

        printf("\n");
    }

    return 0;
}
