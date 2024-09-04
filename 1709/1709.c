// bee 1709 - Baralho Embaralhado
// Alonso Martins
// 03/09/2024
#include <stdio.h>

int min(int x, int y) { return x < y ? x : y; }

int main()
{
    int N, i = 2, passos = 1;

    scanf("%d", &N);
    N >>= 1;

    while (i != 1)
    {
        i += (i > N ? -1 : 1) * min(i, 2 * N + 1 - i);
        passos ++;
    }

    printf("%d\n", passos);

    return 0;
}
