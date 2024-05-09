// bee 1161 - Soma de Fatoriais
// Alonso Martins
// 09/05/2024
#include <stdio.h>
#include <math.h>

#define MAX_FAT 21
long long fatorial[MAX_FAT] = {1};

void calcularFatoriais()
{
    int i;
    for (i = 1; i < MAX_FAT; i ++)
        fatorial[i] = fatorial[i - 1] * i;
}

int main()
{
    int f1, f2;

    calcularFatoriais();    // para evitar recalculo

    while (scanf("%d %d", &f1, &f2) != EOF)
        printf("%lld\n", fatorial[f1] + fatorial[f2]);

    return 0;
}
