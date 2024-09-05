// bee 1218 - Getline Three - Calçados
// Alonso Martins
// 04/09/2024
#include <stdio.h>

int main()
{
    int N, num, caso = 0;
    char modelo, c;

    while (scanf("%d", &N) != EOF)
    {
        int femininos = 0, masculinos = 0;

        do
        {
            scanf("%d %c", &num, &modelo);
            if (num != N) continue;

            if (modelo == 'F') femininos ++;
            else masculinos ++;
        } while (c = getchar(), c != '\n' && c != EOF);

        if (caso ++) printf("\n");
        printf("Caso %d:\nPares Iguais: %d\nF: %d\nM: %d\n", caso, femininos + masculinos, femininos, masculinos);
    }

    return 0;
}
