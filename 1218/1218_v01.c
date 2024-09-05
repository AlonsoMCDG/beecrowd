// bee 1218 - Getline Three - Calçados
// Alonso Martins
// 04/09/2024
#include <stdio.h>
#include <string.h>

int main()
{
    int N, num, caso = 0, i, sz;
    char sapatos[10000], modelo;

    while (scanf("%d", &N) != EOF)
    {
        int femininos = 0, masculinos = 0;

        scanf(" %[^\n]", sapatos);

        sz = strlen(sapatos);
        for (i = 0; i < sz; i += 5)
        {
            num = 10 * (sapatos[i] - '0') + (sapatos[i + 1] - '0');
            modelo = sapatos[i + 3];

            if (num != N) continue;

            if (modelo == 'F') femininos ++;
            else masculinos ++;
        }

        if (caso ++) printf("\n");
        printf("Caso %d:\nPares Iguais: %d\nF: %d\nM: %d\n", caso, femininos + masculinos, femininos, masculinos);
    }

    return 0;
}
