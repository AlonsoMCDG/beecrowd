// bee 1199 - Conversao Simples de Base
// Alonso Martins
// 09/07/2024
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char entrada[50];
    unsigned valor;

    while (scanf(" %s", entrada), entrada[0] != '-')
    {
        if (entrada[1] == 'x')
        {
            sscanf(entrada, "%x", &valor);
            printf("%u\n", valor);
        }
        else
        {
            valor = atoi(entrada);
            printf("0x%X\n", (unsigned) valor);
        }
    }

    return 0;
}
