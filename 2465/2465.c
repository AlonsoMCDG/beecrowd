// bee 2465 - Passa Bolinha
// Alonso Martins
// 19/05/2024
#include <stdio.h>
#include <string.h>

#define NORTE 0
#define LESTE 1
#define SUL 2
#define OESTE 3
#define INVALIDA 5

int bandeirasLevantadas = 0;

typedef struct
{
    int numeracao;
    int direcao;
    int temBandeiraLevantada;
    int fileira, coluna;
} Aluno;

typedef struct
{
    int topo;
    Aluno *lista[10000];
} Pilha;

void insert(Pilha *pilha, Aluno *aluno)
{
    pilha->lista[++ pilha->topo] = aluno;
}

Aluno *getTopo(Pilha *pilha)
{
    return pilha->lista[pilha->topo];
}

void pop(Pilha *pilha)
{
    pilha->topo --;
}

int main()
{
    int direcoesIndex[][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    int N, inicio_i, inicio_j, i, j;
    scanf("%d %d %d", &N, &inicio_i, &inicio_j), inicio_i --, inicio_j --;
    Aluno alunos[N][N];
    Aluno *aluno;
    Pilha pilha;
    pilha.topo = -1;
    memset(alunos, 0, N * N * sizeof(Aluno));

    for (i = 0; i < N; i ++)
        for (j = 0; j < N; j ++)
            scanf("%d", &alunos[i][j].numeracao),
                alunos[i][j].fileira = i,
                alunos[i][j].coluna = j;

    insert(&pilha, &alunos[inicio_i][inicio_j]);

    while (pilha.topo != -1) // topo == -1 significa pilha vazia
    {
        aluno = getTopo(&pilha);

        bandeirasLevantadas += !aluno->temBandeiraLevantada;
        aluno->temBandeiraLevantada = 1;

        aluno->direcao ++;
        while (aluno->direcao != INVALIDA)
        {
            int a2_fileira = aluno->fileira + direcoesIndex[aluno->direcao % 4][1];
            int a2_coluna = aluno->coluna + direcoesIndex[aluno->direcao % 4][0];

            if (a2_coluna < 0 || a2_coluna >= N || a2_fileira < 0 || a2_fileira >= N)
            {
                aluno->direcao ++;
                continue;
            }

            Aluno *aluno2 = &alunos[a2_fileira][a2_coluna];

            if (aluno2->numeracao >= aluno->numeracao && !aluno2->temBandeiraLevantada)
            {
                insert(&pilha, aluno2);
                break;
            }

            aluno->direcao ++;
        }

        if (aluno->direcao == INVALIDA)
            pop(&pilha);
    }

    printf("%d\n", bandeirasLevantadas);

    return 0;
}
