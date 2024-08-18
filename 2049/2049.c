// bee 2049 - Numeros de Ahmoc
// Alonso Martins
// 18/08/2024
#include <stdio.h>
#include <string.h>

int main()
{
    char assinatura[10];
    char painel[300002];
    int instaciaAtual = 0;

    while (scanf(" %s", assinatura), strcmp(assinatura, "0"))
    {
        scanf(" %s", painel);
        printf("%sInstancia %d\n", instaciaAtual ++ ? "\n" : "", instaciaAtual);
        printf("%s\n", strstr(painel, assinatura) ? "verdadeira" : "falsa");
    }

    return 0;
}
