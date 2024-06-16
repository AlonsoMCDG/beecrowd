// bee 1808 - O Retorno do Rei
// Alonso Martins
// 16/06/2024
#include <stdio.h>
#include <string.h>

#define toi(x) x - '0'

int main()
{
    int soma = 0, i, sz, notas = 0;
    char s[102];

    scanf("%s", s);

    for (i = 0, sz = strlen(s); i < sz; i ++)
        if (toi(s[i]))
            soma += toi(s[i]), notas ++;
        else
            soma += 9;

    printf("%.2lf\n", (double)soma / notas);

    return 0;
}
