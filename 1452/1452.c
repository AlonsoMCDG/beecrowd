// bee 1452 - Gloud Computing
// Alonso Martins
// 02/06/2024
#include <stdio.h>
#include <string.h>

typedef struct Provedor
{
    int qtdServicos;
    char servicosDisponiveis[100][22];
} Provedor;

typedef struct Usuario
{
    int qtdRequisicoes;
    char servicoesRequisitados[100][22];
} Usuario;

int tentarConexao(Usuario *u, Provedor *p)
{
    int i, j;
    for (i = 0; i < u->qtdRequisicoes; i ++)
        for (j = 0; j < p->qtdServicos; j ++)
            if (strcmp(u->servicoesRequisitados[i], p->servicosDisponiveis[j]) == 0)
                return 1; // o servidor oferece pelo menos um dos servicos
    return 0; // o servidor nao oferece nenhum dos servicos
}

int main()
{
    int N, M, Q, i, j;
    char servico[22];

    while (scanf("%d %d", &N, &M), N && M)
    {
        int conexoes = 0;
        Provedor provedores[N];
        Usuario usuario;

        for (i = 0; i < N; i ++) // provedores
            for (scanf("%d", &Q), provedores[i].qtdServicos = Q, j = 0; j < Q; j ++)
                scanf(" %s", provedores[i].servicosDisponiveis[j]);

        for (i = 0; i < M; i ++)
        {
            for (scanf("%d", &Q), j = 0; j < Q; j ++)
                scanf(" %s", usuario.servicoesRequisitados[j]);

            for (usuario.qtdRequisicoes = Q, j = 0; j < N; j ++)
                conexoes += tentarConexao(&usuario, &provedores[j]);
        }

        printf("%d\n", conexoes);
    }

    return 0;
}
