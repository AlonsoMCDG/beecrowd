// bee 2875 - Jogo Tunel
// Alonso Martins
// 18/08/2024
#include <stdio.h>
#define DEBUG 0
#define debug if (DEBUG)

#define MAXN 100
#define X 0
#define Y 1

enum
{
    NORTE,
    LESTE,
    SUL,
    OESTE,
    FIM
};

int direcoes[][2] = { // {x, y}
    { 0, -1}, // NORTE
    {+1,  0}, // LESTE
    { 0, +1}, // SUL
    {-1,  0}  // OESTE
};

int proximo_passo(int p[2], int m[MAXN][MAXN], int l, int c)
{
    int x = p[X], y = p[Y];
    
    if (y > 0 && m[y - 1][x    ] == '0') return NORTE;
    if (x < c && m[y    ][x + 1] == '0') return LESTE;
    if (y < l && m[y + 1][x    ] == '0') return SUL;
    if (x > 0 && m[y    ][x - 1] == '0') return OESTE;

    return FIM;
}

void print_mat(int m[MAXN][MAXN], int M, int N)
{
    int i, j;
    for (i = 0, printf("-\n"); i < M; i ++, printf("|\n"))
        for (j = 0, printf("| "); j < N; j ++, printf(" "))
            printf("%c", m[i][j]);
    printf("-\n");
}

int main()
{
    int N, M, i, j;
    int mat[MAXN][MAXN];

    while (scanf("%d %d", &M, &N) != EOF)
    {
        char saida[2 * MAXN * MAXN] = "";
        char comandos[] = "LFR"; // (Left, Front, Right)
        int tam = 0;
        int pos[2] = {0, 0};
        int direcaoMovimento, prox;

        for (i = 0; i < M; i ++)
            for (j = 0; j < N; j ++)
            {
                scanf(" %c", &mat[i][j]);
                if (mat[i][j] == 'X')
                    pos[X] = j, pos[Y] = i;
            }

        direcaoMovimento = prox = proximo_passo(pos, mat, M - 1, N - 1);
        while (prox != FIM)
        {
            debug print_mat(mat, M, N);
            int aux = (direcaoMovimento + 1) % 4 == prox ? 1 : (4 + direcaoMovimento - 1) % 4 == prox ? -1 : 0;

            saida[tam ++] = comandos[1 + aux];
            saida[tam ++] = ' ';

            if (aux != 0) // virou de direcao
            {
                saida[tam ++] = 'F';
                saida[tam ++] = ' ';
            }

            debug printf("%c\n", comandos[1 + aux]);

            direcaoMovimento = prox;

            mat[pos[Y]][pos[X]] = '.'; // para marcar que ja foi visitado

            pos[X] += direcoes[direcaoMovimento][X];
            pos[Y] += direcoes[direcaoMovimento][Y];

            mat[pos[Y]][pos[X]] = 'X';

            (prox = proximo_passo(pos, mat, M - 1, N - 1));
        }
        debug print_mat(mat, M, N);

        debug printf("E\n");
        saida[tam ++] = 'E';
        saida[tam] = '\0';

        printf("%s\n", saida);        
    }
 
    return 0;
}
