// bee 1593 - Funcao Binaria
// Alonso Martins
// 24/05/2024
#include <stdio.h>
#include <string.h>

int funcaoBinaria(char *n)
{
    int i, j = strlen(n), sz, p, soma = 0, resto;

    while (n[0] - '0' > 0 || n[1] != '\0')
    {
        sz = j;
        for (i = j = resto = 0; i < sz; i ++)
        {
            p = n[i] - '0' + resto * 10;
            resto = p % 2;
            n[j ++] = p / 2 + '0';
            if (p / 2 == 0 && j == 1 && sz > 1)
                j = 0;
        }
        n[j] = '\0';
        soma += resto;
    }

    return soma;
}

int main()
{
    int T;
    char numero[1002];

    scanf("%d", &T);

    while (T -- && scanf(" %s", numero))
        printf("%d\n", funcaoBinaria(numero));

    return 0;
}
