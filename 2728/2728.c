// bee 2728 - Grace Hopper, a Vovo do Cobol
// Alonso Martins
// 27/04/2024
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int sum(int *v)
{
    int i, soma = 0;
    for (i = 0; i < 5; i ++) soma += v[i];
    return soma;
}
int main()
{
    int entrada, anterior = ' ', i;
    char *palavra = "cobol";
    char linha[52];

    while ((scanf("%50[^\n]%*c", linha)) != EOF)
    {
        int *cont = (int *)calloc(5, sizeof(int));
        int hifens = 0;

        cont[0] = (tolower(linha[0]) == 'c');
        cont[4] = (tolower(linha[strlen(linha) - 1]) == 'l');

        for (i = 1; i < strlen(linha) - 1; i ++)
        {
            if (linha[i] == '-')
            {
                hifens ++;
                cont[hifens - 1] = cont[hifens - 1] ? 1 : tolower(linha[i - 1]) == palavra[hifens - 1];
                cont[hifens + 0] = cont[hifens + 0] ? 1 : tolower(linha[i + 1]) == palavra[hifens + 0];
            }
        }

        printf(sum(cont) == 5 ? "GRACE HOPPER\n" : "BUG\n");
    }

    return 0;
}
