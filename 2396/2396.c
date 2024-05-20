// bee 2396 - Corrida
// Alonso Martins
// 19/05/2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int n;
    int tempo;
} Carro;

int comparar(const void *_a, const void *_b)
{
    Carro *a = (Carro *)_a;
    Carro *b = (Carro *)_b;
    return a->tempo - b->tempo;
}

int main()
{
    int N, M, i, j, tempo; scanf("%d %d", &N, &M);
    Carro carros[N]; memset(carros, 0, N * sizeof(Carro));

    for (i = 0; i < N; i ++)
    {
        carros[i].n = i + 1;
        for (j = 0; j < M; j ++)
        {
            scanf("%d", &tempo);
            carros[i].tempo += tempo;
        }
    }

    qsort(carros, N, sizeof(carros[0]), comparar);

    for (i = 0; i < 3; i ++)
        printf("%d\n", carros[i].n);

    return 0;
}
