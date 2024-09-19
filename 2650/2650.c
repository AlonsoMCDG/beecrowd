// bee 2650 - Construindo Muralhas
// Alonso Martins
// 18/09/2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_altura(char *str)
{
    int altura = 0, c = 1, sz = strlen(str) - 1;

    while (str[sz] != ' ')
    {
        altura += (str[sz] - '0') * c;
        c *= 10;
        sz --;
    }
    str[sz] = '\0';

    return altura;
}

int main()
{
    int N, W;
    char titan[120];

    scanf("%d %d", &N, &W);

    while (N -- && scanf(" %[^\n]", titan))
    {
        int altura = get_altura(titan);

        if (altura > W)
            printf("%s\n", titan);
    }

    return 0;
}
