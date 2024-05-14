// bee 2187 - Bits Trocados
// Alonso Martins
// 14/05/2024
#include <stdio.h>

int main()
{
    int bits[] = { 1, 5, 10, 50 };
    int bit, i, t = 1;

    while (i = 3, scanf("%d", &bit), bit)
    {
        printf("Teste %d\n", t ++);
        while (i + 1)
        {
            printf("%d%s", bit / bits[i], i ? " " : "\n");
            bit %= bits[i --];
        }
        printf("\n");
    }

    return 0;
}
