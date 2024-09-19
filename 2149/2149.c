// bee 2149 - Sequencia do Tio Phill Bonati
// Alonso Martins
// 19/09/2024
#include <stdio.h>

int main()
{
    long long N, seq[17] = {0, 1};

    for (N = 2; N < 17; N ++)
        seq[N] = N % 2 ? seq[N - 2] * seq[N - 1] : seq[N - 2] + seq[N - 1];

    while (scanf("%lld", &N) != EOF)
        printf("%lld\n", seq[N - 1]);

    return 0;
}
