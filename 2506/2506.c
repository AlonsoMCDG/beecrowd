// bee 2506 - Fila do SUS
// Alonso Martins
// 09/01/2025
#include <stdio.h>

int em_segundos(int h, int m)
{
    return h * 60 + m;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int N, i, H, M, C;

    while (scanf("%d", &N) != EOF)
    {
        int tempo_atual = em_segundos(7, 0), pacientes_criticos = 0;
        int tempo_chegada, tempo_atendimento;

        for (i = 0; i < N; i ++)
        {
            scanf("%d %d %d", &H, &M, &C);

            tempo_chegada = em_segundos(H, M);

            if (tempo_atual < tempo_chegada && M % 30 == 0)
                tempo_atual = tempo_chegada;

            tempo_atendimento = max(tempo_atual, tempo_chegada + (30 - tempo_chegada % 30) % 30);

            if (tempo_atendimento - tempo_chegada > C)
                pacientes_criticos ++;

            tempo_atual = tempo_atendimento + em_segundos(0, 30);
        }
        printf("%d\n", pacientes_criticos);
    }

    return 0;
}
