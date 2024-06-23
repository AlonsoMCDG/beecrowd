// bee 2844 - Escrita Rapida, o Duelo
// Alonso Martins
// 22/06/2024
#include <stdio.h>
#include <string.h>
#define MAXLEN 100002

int main()
{
    char frase[MAXLEN], *ans[] = { "Empate", "Matheus", "Vinicius" };
    int Am, Rm, Em, Av, Rv, Ev, sz, M, V;

    scanf("%d %d %d %d %d %d %100002[^\n]", &Am, &Rm, &Em, &Av, &Rv, &Ev, frase);
    sz = strlen(frase);

    M = 2 * Am + Rm + Em * sz;
    V = 2 * Av + Rv + Ev * sz;

    printf("%s\n", ans[(M < V) + 2 * (V < M)]);

    return 0;
}
