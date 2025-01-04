// bee 1725 - Quadtree II
// Alonso Martins
// 03/01/2025
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 512
#define MAX_COL 514

typedef struct QuadTree
{
    int coord_i;
    int coord_j;
    int size;
    char color;
    struct QuadTree *top_left;
    struct QuadTree *top_right;
    struct QuadTree *bottom_left;
    struct QuadTree *bottom_right;
} QuadTree;

// alocação estática de memória para evitar alocação dinâmica
QuadTree mem_pool[349525];
int count_mem_pool = 0;

QuadTree *new_quadtree(int, int, int, char [MAX_N][MAX_COL]);
void subdivide(QuadTree *, char [MAX_N][MAX_COL]);
void print_tree(QuadTree *);
void make_map(QuadTree *, char *, int *);

int main()
{
    int entrada;
    char input_line[322];
    char mapa[MAX_N][MAX_COL] = {};
    int N, i, j, k, num, a, b, c;
    
    // leitura da dimensão do mapa
    scanf("%*s %*s %d %*[^\n]%*c%*[^\n]%*c", &N);

    for (i = 0; i < N; i ++)
    {
        for (j = 0; j < N / 8; j ++)
        {
            scanf("%x,", &entrada);

            for (k = 0; k < 8; k ++)
                mapa[i][j * 8 + k] = ((entrada >> k) & 1) ? 'B' : 'W';
        }
    }

    // cria a estrutura de quadtree a partir da matriz de entrada
    QuadTree *quadtree = new_quadtree(0, 0, N, mapa);

    // string de saída
    char out[349527] = {};
    int sz = 0;

    make_map(quadtree, out, &sz);

    // saída do enunciado
    printf("%d\n", N);
    printf("%s\n", out);

    return 0;
}

QuadTree *new_quadtree(int i, int j, int size, char mapa[MAX_N][MAX_COL])
{
    QuadTree *quadtree = &mem_pool[count_mem_pool ++];

    quadtree->color = mapa[i][j];
    quadtree->size = size;
    quadtree->coord_i = i;
    quadtree->coord_j = j;
    quadtree->top_left = NULL;
    quadtree->top_right = NULL;
    quadtree->bottom_left = NULL;
    quadtree->bottom_right = NULL;

    int l, c, k, flag = 1;
    for (l = 0; l < size && flag; l ++)
        for (c = 0; c < size && flag; c ++)
        {
            // a área não é homogênea, então subdivide
            if (mapa[i + l][j + c] != mapa[i][j])
            {
                flag = 0;
                subdivide(quadtree, mapa);
                quadtree->color = 'X';
            }
        }

    // retorna a quadtree criada
    return quadtree;
}

void subdivide(QuadTree *quadtree, char mapa[MAX_N][MAX_COL])
{
    int i = quadtree->coord_i;
    int j = quadtree->coord_j;
    int size = quadtree->size / 2;

    quadtree->top_left = new_quadtree(i, j, size, mapa);
    quadtree->top_right = new_quadtree(i, j + size, size, mapa);
    quadtree->bottom_left = new_quadtree(i + size, j, size, mapa);
    quadtree->bottom_right = new_quadtree(i + size, j + size, size, mapa);
}

void print_tree(QuadTree *quadtree)
{
    if (quadtree->color != 'X')
    {
        printf("%c", quadtree->color);
        return;
    }

    printf("Q");
    print_tree(quadtree->top_left);
    print_tree(quadtree->top_right);
    print_tree(quadtree->bottom_left);
    print_tree(quadtree->bottom_right);
}

void make_map(QuadTree *quadtree, char *map, int *len)
{
    if (quadtree->color != 'X')
    {
        map[(*len) ++] = quadtree->color;
        map[(*len)] = '\0';
        return;
    }

    map[(*len) ++] = 'Q';
    make_map(quadtree->top_left, map, len);
    make_map(quadtree->top_right, map, len);
    make_map(quadtree->bottom_left, map, len);
    make_map(quadtree->bottom_right, map, len);
}
