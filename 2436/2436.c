// bee 2436 - Robo
// Alonso Martins
// 01/06/2024
#include <stdio.h>

#define IMPRIME_ROBO imprime(L, C, chao, robo.linha, robo.coluna);

void imprime(int L, int C, int v[L][C], int p, int q)
{
    int i, j;

    for (printf("---\n"), i = 0; i < L; i++, printf("\n"))
        for (j = 0; j < C; j++)
            printf(i == p && j == q ? "[%d]" : " %d ", v[i][j]);
}

int main()
{
    int L, C, A, B, i, j;
    struct { int linha, coluna, direcao; } robo;
    int movimentos[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {0, 0}};

    scanf("%d %d %d %d", &L, &C, &A, &B);

    int chao[L][C];
    robo.direcao = 4;
    robo.linha = A - 1;
    robo.coluna = B - 1;

    for (i = 0; i < L; i++)
        for (j = 0; j < C; j++)
            scanf("%d", &chao[i][j]);

    i = 0;
    while (i != 4)
    {
        int dir[] = {0, 0, 0, 0};
        int l, c;

        robo.linha += movimentos[robo.direcao][0];
        robo.coluna += movimentos[robo.direcao][1];

        // imprime(L, C, chao, robo.linha, robo.coluna);

        for (i = 0; i < 4; i++)
        {
            l = robo.linha + movimentos[i][0];
            c = robo.coluna + movimentos[i][1];
            if ((l == robo.linha || 0 <= l && l < L) &&
                (c == robo.coluna || 0 <= c && c < C))
                dir[i] = chao[l][c];
        }

        i = 0;
        while (i < 4 && (!dir[i] || (i + 2) % 4 == robo.direcao))
            i++;

        robo.direcao = i;
    }

    printf("%d %d\n", robo.linha + 1, robo.coluna + 1);

    return 0;
}
