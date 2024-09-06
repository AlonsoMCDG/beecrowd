// bee 2900 - Jogo de Varetas
// Alonso Martins
// 05/09/2024
#include <stdio.h>

int min(int x, int y)
{
    return x < y ? x : y;
}

int main()
{
    int N, C, V;

    while (scanf("%d", &N), N)
    {
        int total_retangulos = 0, v, varetas_disponiveis = 0;

        while (N -- && scanf("%d %d", &C, &V))
        {
            v = min(varetas_disponiveis, (V >> 1));
            total_retangulos += v;
            varetas_disponiveis = (varetas_disponiveis + (V >> 1)) - 2 * v;
        }
    
        total_retangulos += (varetas_disponiveis >> 1);

        printf("%d\n", total_retangulos);
    }
    printf("\n");

    return 0;
}
