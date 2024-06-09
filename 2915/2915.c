// bee 2915 - Mount Marathon
// Alonso Martins
// 08/06/2024
#include <stdio.h>

int main()
{
    int N, cartas[52], pilhas = 1, topo, i;

    for (scanf("%d", &N), i = 0; i < N; i ++)
        scanf("%d", &cartas[i]);

    for (i = N - 2, topo = cartas[N - 1]; i >= 0; topo = cartas[i], i --)
        if (cartas[i] < topo)
            pilhas ++;

    printf("%d\n", pilhas);

    return 0;
}
