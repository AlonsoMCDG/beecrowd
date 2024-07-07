// bee 1214 - Acima da Media
// Alonso Martins
// 07/07/2024
#include <stdio.h>

int main()
{
    int C, i;
    double notas[1000], media, acimaMedia, alunos;

    scanf("%d", &C);

    while (C -- && scanf("%lf", &alunos))
    {
        for (i = media = 0; i < alunos; i ++)
            scanf("%lf", &notas[i]), media += notas[i];
        media /= alunos;

        for (i = acimaMedia = 0; i < alunos; i ++)
            acimaMedia += (notas[i] > media);

        printf("%.3lf%%\n", 100.0 * acimaMedia / alunos);
    }

    return 0;
}
