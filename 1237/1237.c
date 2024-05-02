// bee 1237 - Comparacao de Substring
// Alonso Martins
// 02/05/2024
#include <stdio.h>
#include <string.h>

int comparar(char *str1, char *str2)
{
    int i = 0, cont = 0;
    while (str1[i] && str2[i] && str1[i] == str2[i ++]) cont ++;
    return cont;
}

int main()
{
    char str1[52], str2[52];
    int size1, size2;
    int i, j, combinacoes, maxCombinacoes;

    while (scanf("%50[^\n]%*c", str1) != EOF)
    {            
        scanf("%50[^\n]%*c", str2); 
        size1 = strlen(str1); 
        size2 = strlen(str2);

        for (maxCombinacoes = i = 0; i < size1; i ++)
        {
            for (j = 0; j < size2; j ++)
            {
                if (j + maxCombinacoes >= size2) break;

                combinacoes = comparar(&str1[i], &str2[j]);

                maxCombinacoes = combinacoes > maxCombinacoes ? combinacoes : maxCombinacoes;
            }
            if (i + maxCombinacoes >= size1) break;
        }

        printf("%d\n", maxCombinacoes);
    }

    return 0;
}
