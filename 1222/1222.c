// bee 1222 - Concurso de Contos
// Alonso Martins
// 02/05/2024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int N, L, C, i;
    int caracteres, linhas, paginas, len;
    char palavra[80];

    while (scanf("%d %d %d%*c", &N, &L, &C) != EOF)
    {
        caracteres = 0; linhas = paginas = 1;


        for (i = 0; i < N; i ++)
        {
            scanf("%s", palavra); len = strlen(palavra);
            caracteres += len + 1;

            if (caracteres - 1 > C)
            {
                caracteres = len + 1;
                linhas ++;
            }
            if (linhas > L)
            {
                linhas = 1;
                paginas ++;
            }
        }

        printf("%d\n", paginas);
    }

    return 0;
}
