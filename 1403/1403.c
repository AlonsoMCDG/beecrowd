// bee 1403 - Meu Avo e Famoso
// Alonso Martins
// 25/08/2024
#include <stdio.h>

#define MAX_JOGADORES 10001
int main()
{
    int N, M, i, j, maior, maior2, jogador;

    while (scanf("%d %d", &N, &M), N)
    {
        maior = maior2 = 0;
        int pontos[MAX_JOGADORES] = {};

        for (j = 0; j < N; j ++)
            for (i = 0; i < M; i ++)
            {
                scanf("%d", &jogador);
                pontos[jogador] ++;
                if (pontos[jogador] > maior)
                    maior = pontos[jogador];
            }

        for (i = 1; i <= MAX_JOGADORES; i ++)
            if (pontos[i] > maior2 && pontos[i] != maior)
                maior2 = pontos[i];

        for (i = 1; i <= MAX_JOGADORES; i ++)
            if (pontos[i] == maior2)
                printf("%d ", i);
        printf("\n");   
    }

    return 0;
}
