// bee 1728 - Dificil de Acreditar, Mas e Verdade!
// Alonso Martins
// 30/06/2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverter(char *p)
{
    int sz, i = strlen(p);
    char s[10] = "";
    for (i = 0; i < sz; i ++)
        s[sz - i - 1] = p[i];
    s[i] = '\0';
    strcpy(p, s);
    printf("p = %s, sz = %d\n", p, sz);
}

int main()
{
    int A, B, C, sz, i, j;
    char input[50], p[50];

    while (1)
    {
        scanf(" %50[^\n]", input);
        sz = strlen(input);

        for (i = sz - 1, j = 0; i >= 0; i --, j ++)
            if (input[i] == '=') break;
            else p[j] = input[i];
        p[j] = '\0';
        C = atoi(p);

        for (i --, j = 0; i >= 0; i --, j ++)
            if (input[i] == '+') break;
            else p[j] = input[i];
        p[j] = '\0';
        B = atoi(p);

        for (i --, j = 0; i >= 0; i --, j ++)
            p[j] = input[i];
        p[j] = '\0';
        A = atoi(p);

        printf("%s\n", A + B == C ? "True" : "False");

        if (!A && !B && !C)
            break;
    }

    return 0;
}
