// bee 1615 - Insatisfacao nas Eleicoes
// Alonso Martins
// 15/06/2024
#include <stdio.h>

int main()
{
    int T, N, M, i, voto;
    
    scanf("%d", &T);

    while (T -- && scanf("%d %d", &N, &M))
    {
        int votos[10] = {};
        int maiorVotos = 0, vencedor = -1, qtdVencedores = 0;

        for (i = 0; i < M; i ++)
        {
            scanf("%d", &voto);
            votos[voto - 1] ++;
        }

        for (i = 0; i < N; i ++)
        {
            if (votos[i] <= M / 2 || votos[i] < maiorVotos)
                continue;

            if (votos[i] > maiorVotos)
                vencedor = i + 1, maiorVotos = votos[i], qtdVencedores = 1;
            else
                qtdVencedores ++;
        }

        if (qtdVencedores == 1)
            printf("%d\n", vencedor);
        else
            printf("-1\n");
    }

    return 0;
}
