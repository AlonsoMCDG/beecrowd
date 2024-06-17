// bee 2322 - Peca Perdida
// Alonso Martins
// 17/06/2024
#include <stdio.h>

int main()
{
    int N, i, p;
    int pecas[1000] = {};

    for (scanf("%d", &N), i = 0; i < N; i ++)
        scanf("%d", &p), pecas[p - 1] ++;

    for (i = 0; i < N;)
        if (!pecas[i ++])
            break;

    printf("%d\n", i);

    return 0;
}
