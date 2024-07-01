// bee 1276 - Faixa de Letras
// Alonso Martins
// 01/07/2024
#include <stdio.h>

int main()
{
    char c = 0, i, flag;

    while ((c = getchar()) != EOF)
    {
        char letras[27] = {};

        if (c != '\n') 
            do
                if (c != ' ') 
                    letras[c - 'a'] = 1;
            while (c = getchar(), c != '\n' && c != EOF);

        char inicio = 0, fim = 0;

        for (flag = i = 0; i < 27; i ++)
            if (letras[i])
            {
                if (!inicio)
                    inicio = i + 'a';
                
                fim = i + 'a';
            }
            else if (fim)
            {
                printf("%s%c:%c", flag ++ ? ", " : "", inicio, fim);
                inicio = fim = 0;
            }
        printf("\n");
    }

    return 0;
}
