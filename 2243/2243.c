// bee 2243 - Isosceles
// Alonso Martins
// 29/09/2024
#include <stdio.h>

int max(int x, int y) { return x > y ? x : y; }
int min(int x, int y) { return x < y ? x : y; }

int main()
{
    int N, muro[50001], i, max_altura;
    int crescentes[50001] = {};  // altura maxima crescente da esquerda para a direita
    int decrescente[50002] = {}; // altura maxima crescente da direita para a esquerda (decrescente)

    scanf("%d", &N);

    for (i = 1; i <= N; i ++)
    {
        scanf("%d", &muro[i]);
        crescentes[i] = min(crescentes[i - 1] + 1, muro[i]);
    }

    // percorre do fim ao inicio montando o maior triangulo possivel
    max_altura = 0;
    for (i = N; i >= 1; i --)
    {
        decrescente[i] = min(decrescente[i + 1] + 1, crescentes[i]);
        max_altura = max(max_altura, decrescente[i]);
    }

    printf("%d\n", max_altura);

    return 0;
}
