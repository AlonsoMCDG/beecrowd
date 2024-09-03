// bee 3056 - Ponto do Meio
// Alonso Martins
// 03/09/2024
#include <stdio.h>

int main()
{
    long long N, D, P;

    scanf("%lld", &N);

    D = (1ll << N) + 1; // numero de pontos na diagonal do quadrado final = 2^N + 1
    P = D * D; // numero de pontos totais no quadrado final = 2 * {[(1 + D) * D] / 2} - D

    printf("%lld\n", P);

    return 0;
}
