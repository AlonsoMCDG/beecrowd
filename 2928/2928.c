// bee 2928 - Cruzando Lagos
// Alonso Martins
// 27/07/2024
#include <stdio.h>

int main()
{
    int N, pulos = 0;
    char c, c0 = '-', c1 = '-', c2;

    scanf("%d%*c", &N);

    while (N -- && (c2 = getchar())) // le o primeiro caractere da linha
    {
        if (c0 == '.' && c2 == '.')
        {
            printf("N\n");
            return 0;
        }

        if (c2 == '-' && c1 == '.')
            pulos ++;

        c0 = c1;
        c1 = c2;

        while (c = getchar(), c != '\n' && c != EOF); // descarta o resto da linha
    }
    
    pulos += (c2 == '.' && (c0 == '-' || c1 == '-'));
    printf("%d\n", pulos);

    return 0;
}
