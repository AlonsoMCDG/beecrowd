// bee 1397 - Jogo do Maior
// Alonso Martins
// 13/05/2024
#include <stdio.h>

int main()
{
    int N, A, B, pA = 0, pB = 0;

    while (pA = pB = 0, scanf("%d", &N) && N)
    {
        while (N -- && scanf("%d %d", &A, &B))
        {
            if (A > B) pA ++;
            else if (A < B) pB ++;
        }
        
        printf("%d %d\n", pA, pB);
    }

    return 0;
}
