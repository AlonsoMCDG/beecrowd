// bee 1239 - Atalhos Bloggo
// Alonso Martins
// 02/05/2024
#include <stdio.h>
#include <string.h>

int main()
{
    char *tags[2][2] = {{"<i>", "</i>"}, {"<b>", "</b>"}};
    int i, sub, neg, size;
    char texto[52];

    while (fgets(texto, sizeof(texto), stdin) != NULL)
    {
        sub = neg = 0;
        size = strlen(texto);
        for (i = 0; i < size; i ++)
        {
            if (texto[i] == '_') printf("%s", tags[0][(sub ++ % 2)]);
            else if (texto[i] == '*') printf("%s", tags[1][(neg ++ % 2)]);
            else printf("%c", texto[i]);
        }
    }

    return 0;
}
