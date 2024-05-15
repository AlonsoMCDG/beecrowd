// bee 1803 - Matring
// Alonso Martins
// 14/05/2024
#include <stdio.h>
#include <string.h>

int obterColuna(char m[][90], int i)
{
    int n = 0, j = 4, c = 1;
    while (j--)
        n += c * (m[j][i] - '0'), c *= 10;
    return n;
}

int main()
{
    char matring[4][90];
    int i, c, N, F, L, M;

    for (i = 0; i < 4; i++)
        scanf("%s", matring[i]);

    N = strlen(matring[0]) - 1;

    F = obterColuna(matring, 0);
    L = obterColuna(matring, N);
    
    for (i = 1; i < N; i ++)
        printf("%c", (F * obterColuna(matring, i) + L) % 257);
    printf("\n");

    return 0;
}
