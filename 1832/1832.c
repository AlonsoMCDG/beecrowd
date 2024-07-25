// bee 1832 - EBCDIC
// Alonso Martins
// 24/07/2024
#include <stdio.h>
#include <string.h>

int main()
{
    int len = 0, cod;
    char c, mensagem[1000];
    char *EBCDIC = "                                                                                                                                 abcdefghi       jklmnopqr        stuvwxyz                       ABCDEFGHI       JKLMNOPQR        STUVWXYZ      0123456789";

    while (scanf("%o", &cod) != EOF)
    {
        c = getchar();
        mensagem[len ++] = EBCDIC[cod];

        if (c == '\n' || c == EOF)
        {
            mensagem[len] = '\0';
            printf("%s\n", mensagem);
            len = 0;
        }

    }

    return 0;
}
