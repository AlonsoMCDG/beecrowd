// bee 2137 - A Biblioteca do Senhor Severino
// Alonso Martins
// 08/04/2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparar(const void *a, const void *b)
{
    return strcmp((const char *)a, (const char *)b);
}
int main()
{
    int T, i;
    char livros[1000][5];

    while (scanf("%d", &T) != EOF)
    {
        for (i = 0; i < T; i ++)
            scanf("%s", livros[i]);

        qsort(livros, T, sizeof(livros[0]), comparar);

        for (i = 0; i < T; i ++)
            printf("%s\n", livros[i]);
    }
    return 0;
}
