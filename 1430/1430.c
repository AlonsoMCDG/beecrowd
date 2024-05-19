// bee 1430 - Composicao de Jingles
// Alonso Martins
// 19/05/2024
#include <stdio.h>

int main()
{
    double tempos[] = {0, 0, 0, 0, 0.125, 0, 0, 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0.25, 0, 0.0625, 0.03125, 0, 0, 1, 0.015625};
    double tempo = 0.0;
    int i, compassosCorretos;
    char nota;

    while (compassosCorretos = 0, nota = getchar(), nota != '*')
    {
        while (nota = getchar(), nota != '\n')
        {
            if (nota == '/')
            {
                compassosCorretos += tempo == 1;
                tempo = 0;
                continue;
            }

            tempo += tempos[nota - 'A'];
        }

        printf("%d\n", compassosCorretos);
    }

    return 0;
}
