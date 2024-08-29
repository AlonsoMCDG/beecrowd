// bee 2150 - Vogais Alienigenas
// Alonso Martins
// 28/08/2024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char vogais[40], texto[1000], c;
    int cont, i;

    while (cont = 0, i = 0, scanf(" %[^\n] %[^\n]", vogais, texto) != EOF)
    {
        while ((c = texto[i ++]) != '\0')
            cont += strchr(vogais, c) != NULL;

        printf("%d\n", cont);
    }

    return 0;
}
