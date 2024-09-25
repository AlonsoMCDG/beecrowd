// bee 2380 - Fusoes
// Alonso Martins
// 24/09/2024
#include <stdio.h>

int find(int x, int *b)
{
    while (b[x] != x)
        x = b[x];

    return x;
}

int main()
{
    int N, K, i, A, B;
    int bancos[100001] = {};
    char cod;

    scanf("%d %d", &N, &K);

    for (i = 1; i <= N; i ++)
        bancos[i] = i;

    for (i = 0; i < K; i ++)
    {
        scanf(" %c %d %d", &cod, &A, &B);

        int r1 = find(A, bancos);
        int r2 = find(B, bancos);

        if (r1 > r2)
            r1 += r2, r2 = r1 - r2, r1 -= r2;

        if (cod == 'F')
            bancos[r2] = r1;
        else
            printf("%c\n", bancos[r2] == r1 ? 'S' : 'N');
    }

    return 0;
}
