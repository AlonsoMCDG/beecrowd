// bee 2457 - Letras
// Alonso Martins
// 21/06/2024
#include <stdio.h>
#include <string.h>

int main()
{
    char L, txt[1002];
    int total = 0, qtd = 0;

    scanf("%c", &L);

    while (scanf(" %s", txt) != EOF)
        if (total ++, strchr(txt, L) != NULL)
            qtd ++;

    printf("%.1lf\n", 100.0 * qtd / total);

    return 0;
}
