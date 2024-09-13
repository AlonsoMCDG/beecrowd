// bee 2871 - Colheita de Cafe
// Alonso Martins
// 13/09/2024
#include <stdio.h>

void add_int(char *, int *, int);
void concat(char *, int *, int);

int main()
{
    int N, M, sacas, litros, k, i, j, t = 0;
    char saida[280002] = {};

    while (scanf("%d %d", &N, &M) != EOF)
    {
        for (i = litros = 0; i < N; i ++)
            for (j = 0; j < M; j ++)
                scanf("%d", &k), litros += k;

        concat(saida, &t, litros);
    }

    printf("%s", saida);

    return 0;
}

void add_int(char *str, int *k, int n)
{
    int i = 0, aux[10];

    do
        aux[i ++] = n % 10;
    while (n /= 10);

    while (-- i >= 0)
        str[(*k) ++] = aux[i] + '0';
}

void concat(char *saida, int *k, int litros)
{
    int i = 0;
    char *s = " saca(s) e  litro(s)\n";

    add_int(saida, k, litros / 60);
    while (i < 11) saida[(*k) ++] = s[i ++];
    add_int(saida, k, litros % 60);
    while (i < 21) saida[(*k) ++] = s[i ++];
}
