// bee 1532 - Arremesso de Bolas
// Alonso Martins
// 04/09/2024
#include <stdio.h>

int main()
{
    int N, V, i, possivel, forca, d;

    while (scanf("%d %d", &N, &V), N)
    {
        possivel = 0;
        for (forca = V; forca >= 1; forca --)
        {
            d = 0, i = forca + 1;

            while (-- i && d + i * i < N)
                d += i * i;

            if (i && (N - d) % i == 0)
            {
                possivel = 1;
                break;
            }
        }

        printf("%s\n", possivel ? "possivel" : "impossivel");
    }

    return 0;
}
