// bee 1936 - Fatorial
// Alonso Martins
// 13/05/2024
#include <stdio.h>

int main()
{
    int N, termos = 0, t, i;
    int fatoriais[] = { 1, 2, 6, 24, 120, 720, 5040, 40320 };

    scanf("%d", &N);

    for (i = 7; i >= 0; i --)
    {
        t = N / fatoriais[i];
        termos += t;
        N %= fatoriais[i];
    }

    printf("%d\n", termos);

    return 0;
}
