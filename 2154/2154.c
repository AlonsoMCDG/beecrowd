// bee 2154 - Derivada de Polinomios
// Alonso Martins
// 08/08/2024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int T, C, E, i;
    char termo[1000];

    while (scanf("%d", &T) != EOF)
    {
        for (i = 0; i < T; i ++)
        {
            scanf(" %s", termo);
            C = atoi(termo);
            E = atoi((strchr(termo, 'x')) + 1);
            C *= E --;

            if (i > 0) printf(" + ");
            if (C > 1) printf("%d", C);
            printf("x");
            if (E > 1) printf("%d", E);

            if (i < T - 1) scanf(" %*c"); // descartar o sinal '+'
        }
        printf("\n");
    }

    return 0;
}
