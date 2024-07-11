// bee 2667 - Jogo de Boca
// Alonso Martins
// 11/07/2024
#include <stdio.h>
#include <string.h>

int main()
{
    char v[200];
    int soma = 0, i, sz, ans;

    scanf("%s", v);

    for (i = 0, sz = strlen(v); i < sz; i ++)
        soma += v[i] - '0';
    
    ans = soma % 3;

    printf("%d\n", ans);

    return 0;
}
