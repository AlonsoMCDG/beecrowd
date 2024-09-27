// bee 3088 - Correcao de Texto
// Alonso Martins
// 27/09/2024
#include <stdio.h>

int main()
{
    int i, t;
    char entrada[1000] = {}, saida[1000];

    while (scanf(" %[^\n]", &entrada[1]) != EOF)
    {
        i = 1, t = 0;

        while (entrada[i])
        {
            if ((entrada[i - 1] == ' ') && (entrada[i] == '.' || entrada[i] == ','))
                t --;

            saida[t ++] = entrada[i ++];
        }
        saida[t] = '\0';

        printf("%s\n", saida);
    }

    return 0;
}
