// bee 2471 - Quadrado
// Alonso Martins
// 21/06/2024
#include <stdio.h>

int get_soma(int *s)
{
    return s[0] == s[1] ? s[0] : s[2];
}

int main()
{
    int N, E, i, j, ans, soma;
    int quadrado[50][50];
    int somaLinha[50] = {};
    int somaColuna[50] = {};

    scanf("%d", &N);

    for (i = 0; i < N; i ++)
        for (j = 0; j < N; j ++)
        {
            scanf("%d", &E);
            quadrado[i][j] = E;
            somaLinha[i] += E;
            somaColuna[j] += E;
        }

    soma = get_soma(somaLinha);

    for (i = 0; i < N && somaLinha[i] == soma; i ++);
    for (j = 0; j < N && somaColuna[j] == soma; j ++);

    ans = soma - (somaColuna[j] - quadrado[i][j]);

    printf("%d %d\n", ans, quadrado[i][j]);

    return 0;
}
