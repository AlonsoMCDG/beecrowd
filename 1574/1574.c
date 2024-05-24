// bee 1574 - Instrucoes do Robo
// Alonso Martins
// 23/05/2024
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T, N, i, j, p, instrucoes[100];
    char instrucao[20];

    scanf("%d", &T);

    while (i = p = 0, T -- && scanf("%d", &N))
    {
        while (N --)
        {
            scanf(" %19[^\n]", instrucao);

            switch (instrucao[0])
            {
                case 'L': instrucoes[i] = -1; break;
                case 'R': instrucoes[i] = 1; break;
                case 'S': instrucoes[i] = instrucoes[(int)atoi(&instrucao[8]) - 1];
                default: break;
            }
            p += instrucoes[i ++];
        }

        printf("%d\n", p);
    }
    
    return 0;
}
