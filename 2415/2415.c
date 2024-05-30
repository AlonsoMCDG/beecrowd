// bee 2415 - Consecultivos
// Alonso Martins
// 29/05/2024
#include <stdio.h>

int main()
{
    int N, A, B, cont, maiorSeq, i;

    for (scanf("%d %d", &N, &A), maiorSeq = cont = 1, i = 0; i < N - 1; i ++)
    {
        scanf("%d", &B);

        if (B == A)
            cont ++;
        else
            cont = 1;

        if (cont > maiorSeq)
            maiorSeq = cont;

        A = B;
    }

    printf("%d\n", maiorSeq);

    return 0;
}
