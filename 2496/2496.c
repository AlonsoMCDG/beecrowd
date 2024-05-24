// bee 2496 - A Unica Chance
// Alonso Martins
// 23/05/2024
#include <stdio.h>

int main()
{
    int N, M;
    char sequencia[28], c;

    scanf("%d", &N);

    while (N -- && scanf("%d %s", &M, sequencia))
    {
        int i, j, trocas = 0;

        for (i = 0; i < M; i ++)
        {
            c = sequencia[i] - 'A';
            if (c != i)
            {
                if (sequencia[c] - 'A' != i)
                {
                    trocas = 3;
                    break;
                }
                trocas ++;
            }
        }

        printf("There are%s the chance.\n", trocas > 2 ? "n't" : "");
    }

    return 0;
}
