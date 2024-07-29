// bee 1418 - Outra Crise
// Alonso Martins
// 28/07/2024
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_FUNCIONARIOS 100002

typedef struct Funcionario
{
    int subordinados[200];
    int num_subordinados;
    int pedidos;
} Funcionario;

Funcionario funcionarios[MAX_FUNCIONARIOS];
int T;

int comp(const void *, const void *);
void adicionar_subordinado(int, int);
void contar_peticoes(Funcionario *);

int main()
{
    int N, i, chefe_id, pedidos;

    while (scanf("%d %d", &N, &T), N)
    {
        // zerar_funcionarios(N); // limpar o vetor de funcionarios
        
        funcionarios[0].num_subordinados = 0;
        funcionarios[0].pedidos = 0;
        for (i = 1; i <= N; i ++)
        {
            funcionarios[i].num_subordinados = 0;
            funcionarios[i].pedidos = 0;
            scanf("%d", &chefe_id);

            // coloca funcs[i] como subordinado de funcs[chefe_id]
            adicionar_subordinado(chefe_id, i);
        }

        contar_peticoes(&funcionarios[0]);

        printf("%d\n", funcionarios[0].pedidos);
    }

    return 0;
}

int comp(const void *a, const void *b)
{
    Funcionario *A = &funcionarios[*(const int *)a];
    Funcionario *B = &funcionarios[*(const int *)b];

    return A->pedidos - B->pedidos;
}

void adicionar_subordinado(int chefe, int subordinado)
{
    Funcionario *c = &funcionarios[chefe];
    c->subordinados[c->num_subordinados ++] = subordinado;
}

void contar_peticoes(Funcionario *f)
{
    if (f->num_subordinados == 0) // eh um operario
    {
        f->pedidos = 1;
        return;
    }

    int i;
    for (i = 0; i < f->num_subordinados; i ++)
    {
        Funcionario *subordinado = &funcionarios[f->subordinados[i]];
        contar_peticoes(subordinado);
    }

    // ordena o vetor de subordinados pela quantidade de peticoes de cada um
    qsort(f->subordinados, f->num_subordinados, sizeof(f->subordinados[0]), comp);

    // coleta (soma) as peticoes dos subordinados
    int min_peticoes = (int)ceil(T * f->num_subordinados / 100.0);
    for (i = 0; i < min_peticoes; i ++)
    {
        Funcionario *s = &funcionarios[f->subordinados[i]];
        f->pedidos += s->pedidos;
    }
}
