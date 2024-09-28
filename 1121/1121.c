// bee 1121 - Robo Colecionador
// Alonso Martins
// 28/09/2024
#include <stdio.h>

enum
{
    NORTE = 0,
    LESTE = 1,
    SUL = 2,
    OESTE = 3
};

int is_valid_cell(int i, int j, char m[100][102], int N, int M)
{
    return !(i < 0 || i >= N || j < 0 || j >= M || m[i][j] == '#');
}

int main()
{
    int N, M, S, i, j, c, nxt_i, nxt_j;
    char mapa[100][102], instrucoes[50002];
    int move[4][2] = { // [[lin][col]]
        {-1, 0}, // norte
        {0, +1}, // leste
        {+1, 0}, // sul
        {0, -1}  // oeste
    };

    while (scanf("%d %d %d", &N, &M, &S), N)
    {
        int robo_i = -1, robo_j = -1, robo_sentido = 0;
        int pontos = 0;

        for (i = 0; i < N; i ++)
        {
            scanf(" %s", mapa[i]);

            for (j = 0; j < M; j ++)
            {
                c = mapa[i][j];
                if (c >= 'A' && c <= 'Z')
                {
                    robo_i = i;
                    robo_j = j;
                    robo_sentido = (c == 'N' ? NORTE : c == 'L' ? LESTE : c == 'S' ? SUL : OESTE);
                }
            }
        }

        scanf(" %s", instrucoes);
        for (c = 0; c < S; c ++)
        {
            if (instrucoes[c] == 'E')
                robo_sentido = (4 + robo_sentido - 1) % 4;
            else if (instrucoes[c] == 'D')
                robo_sentido = (4 + robo_sentido + 1) % 4;
            else
            {
                nxt_i = robo_i + move[robo_sentido][0];
                nxt_j = robo_j + move[robo_sentido][1];

                if (is_valid_cell(nxt_i, nxt_j, mapa, N, M))
                {
                    robo_i = nxt_i;
                    robo_j = nxt_j;

                    if (mapa[robo_i][robo_j] == '*')
                    {
                        pontos ++;
                        mapa[robo_i][robo_j] = '.';
                    }
                }
            }
        }

        printf("%d\n", pontos);
    }

    return 0;
}
