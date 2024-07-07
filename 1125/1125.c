// bee 1125 - Formula 1
// Alonso Martins
// 28/04/2024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Piloto
{
    int id;
    int pontos;
} Piloto;

int comp(const void *a, const void *b)
{
    Piloto *A = (Piloto *)a, *B = (Piloto *)b;
    if (B->pontos == A->pontos)
        return A->id - B->id;
    return B->pontos - A->pontos;
}

void zerar_pontuacao(Piloto p[])
{
    int i;
    for (i = 0; i < 100; i ++)
    {
        p[i].id = i + 1;
        p[i].pontos = 0;
    }
}

void imprime_vet(int *v, int n)
{
    int i;
    for (i = 1; i < n; i ++)
        printf("%s%d", i ? " " : "", v[i]);
    printf("\n");
}

void imprime_pilotos(Piloto *p, int P)
{
    for (int i = 0; i < P; i ++)
        printf("[%d:%d]", p[i].id, p[i].pontos);
    printf("\n");
}

int main()
{
    int G, P, S, K, i, j, p;
    Piloto pilotos[100];
    int sistema_de_pontos[100];

    for (i = 0; i < 100; i ++)
        pilotos[i].id = i + 1, pilotos[i].pontos = 0;

    while (scanf("%d %d", &G, &P), G && P)
    {
        int ranking_gp[100][100] = {};

        for (i = 0; i < G; i ++)
            for (j = 0; j < P; j ++)
            {
                scanf("%d", &p);
                ranking_gp[i][p - 1] = j + 1;
            }

        scanf("%d", &S);

        while (S -- && scanf("%d", &K))
        {
            for (i = 0; i < K; i ++)
                scanf("%d", &sistema_de_pontos[i]);

            zerar_pontuacao(pilotos);

            for (i = 0; i < G; i ++)
            {
                for (j = 0; j < K; j ++)
                {
                    int piloto_id = ranking_gp[i][j];
                    pilotos[piloto_id - 1].pontos += sistema_de_pontos[j];
                }
            }

            qsort(pilotos, P, sizeof(pilotos[0]), comp);

            for (i = 0; i < P; i ++)
            {
                if (pilotos[i].pontos != pilotos[0].pontos)
                    break;

                printf("%s%d", i > 0 ? " " : "", pilotos[i].id);
            }
            printf("\n");
        }
    }

    return 0;
}
