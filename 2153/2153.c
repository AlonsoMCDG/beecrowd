// bee 2153 - Sanduicheiche
// Alonso Martins
// 20/09/2024
#include <stdio.h>
#include <string.h>

int main()
{
    char palavra[32];

    while (scanf(" %s", palavra) != EOF)
    {
        int i, j, sz = strlen(palavra);
        int final = sz, max = -1;

        for (i = sz - 1; i >= sz / 2 - 1; i --)
        {
            int cont = 0;
            for (j = 0; j < sz - i; j ++)
            {
                if (palavra[i - j] != palavra[sz - 1 - j])
                    break;
                cont ++;
            }

            if (cont > max)
            {
                max = cont;
                final = i + 1;
            }
        }
        palavra[final] = '\0';

        printf("%s\n", palavra);
    }

    return 0;
}
