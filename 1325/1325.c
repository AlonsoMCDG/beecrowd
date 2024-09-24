// bee 1325 - Mapas Bolha
// Alonso Martins
// 23/09/2024
#include <stdio.h>
#include <string.h>
#define DEBUG 0
#define debug if (DEBUG)

// muda o vizinho nessa direcao
void change_nbr(char *fonte, char *destino, int n, char v, int *sz)
{
    *sz = 0;
    while ((*sz) < n)
        destino[(*sz) ++] = *fonte ++;
    destino[(*sz) ++] = v;
}

enum
{
    UP = 0,
    DW = 1,
    LF = 2,
    RT = 3
};

int main()
{
    int N, i, j, sz_mapa;
    char mapa[5002];

    // guarda o vizinho correspondente ao zoom aplicado na regiao `k`
    char ngbs_aux[4][2][2] = {
        {{'q', RT}, {'s', DW}}, // k = 'p'
        {{'p', LF}, {'r', DW}}, // k = 'q'
        {{'q', UP}, {'s', LF}}, // k = 'r'
        {{'p', UP}, {'r', RT}}  // k = 's'
    };
    // 
    char ngbs_zoom[4][2] = {
        {'s', 'r'}, // cima     -> p:s/q:r | p q - -
        {'q', 'p'}, // baixo    -> s:p/r:q | - - r s
        {'q', 'r'}, // esquerda -> p:q/s:r | p - - s
        {'s', 'p'}  // direita  -> q:p/r:s | - q r -
    };

    scanf("%d", &N);

    while (N -- && scanf(" %s", mapa))
    {
        char mapa_cpy[4][5002] = {};
        char *ngbs[4] = {};
        char last_ngb[4] = {};
        int ngbs_sz[4] = {};
        sz_mapa = strlen(mapa);

        for (i = 0; i < 4; i ++)
            strcpy(mapa_cpy[i], mapa);

        for (i = 1; i < sz_mapa; i ++)
        {
            debug printf("i = %d / %d\n", i, sz_mapa);
            debug printf("mapa[%d] = %c\n", i, mapa[i]);
 
            int c = mapa[i] - 'p';
            int viz = ngbs_aux[c][0][0];
            int dir = ngbs_aux[c][0][1];

            // change_nbr(mapa, ngbs[dir], i, viz, &ngbs_sz[dir]);
            ngbs_sz[dir] = i;
            last_ngb[dir] = viz;
            debug printf("viz[%d] = %c\n", dir, viz);

            viz = ngbs_aux[c][1][0];
            dir = ngbs_aux[c][1][1];

            // change_nbr(mapa, ngbs[dir], i, viz, &ngbs_sz[dir]);
            ngbs_sz[dir] = i;
            last_ngb[dir] = viz;
            debug printf("viz[%d] = %c\n", dir, viz);

            // debug for (j = 0; j < 4; j ++)
            //     printf("[%s]%s", ngbs[j], j == 3 ? "\n" : " ");
            
            debug printf("----------\n");
        }

        // aplicar zoom nos vizinhos que nao estao com o mesmo nivel de zoom
        for (i = 0; i < 4; i ++)
        {   
            // nao tem um vizinho nessa direcao `i`
            if (ngbs_sz[i] == 0)
            {
                ngbs[i] = "<none>";
                continue;
            }

            debug printf("zooming in %d: [%d:%s]\n", i, ngbs_sz[i], mapa_cpy[i]);
            ngbs[i] = mapa_cpy[i];

            int sz = ngbs_sz[i];
            mapa_cpy[i][sz ++] = last_ngb[i];
            mapa_cpy[i][sz] = '\0';
            ngbs_sz[i] = sz;

            // vizinho com nivel de zoom diferente
            debug printf("zooming in %d: [%d:%s]\n", i, ngbs_sz[i], mapa_cpy[i]);
            for (j = ngbs_sz[i]; j < sz_mapa; j ++)
            {
                int c = mapa[j] - 'p';
                mapa_cpy[i][j] = ngbs_zoom[i][c % 2];
                debug printf("c = %c | ngb[%d] = %c\n", c + 'p', j, mapa_cpy[i][j]);
            }
            ngbs_sz[i] = j;
        }

        debug for (printf("viz_sz = "), i = 0; i < 4; i ++)
            debug printf("[%d]", ngbs_sz[i]);
        debug printf("\n");

        // saida
        for (i = 0; i < 4; i ++)
            printf("%s%s", ngbs[i], i == 3 ? "\n" : " ");
        debug printf("\n");
    }

    return 0;
}
