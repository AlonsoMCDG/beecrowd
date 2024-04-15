// bee 1023 - Estiagem
// Alonso Martins
// 07/04/2024
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, X, Y, nCidade = 0, i, flag, cm;
    double aux;
    int totalPessoas, totalConsumo;

    for (nCidade = 0; scanf("%d", &N) && N;)
    {
        int consumos[201] = {0};
        totalConsumo = 0; totalPessoas = 0;
        
        for (i = 0; i < N; i ++)
        {
            scanf("%d %d", &X, &Y);

            consumos[Y / X] += X;

            totalPessoas += X;
            totalConsumo += Y;
        }

        printf("%sCidade# %d:\n", nCidade++ ? "\n" : "", nCidade);

        for (i = 0, flag = 0; i <= 200; i ++)
        {
            if (consumos[i])
            {
                printf("%s%d-%d", flag ? " " : "", consumos[i], i);
                flag = 1;
            }
        }
        printf("\n");

        printf("Consumo medio: %.2lf m3.\n", ((int)(((double)totalConsumo / totalPessoas)*100)) / 100.0);
    }

    return 0;
}
